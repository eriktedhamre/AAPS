#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ll = long long;

// INF defined to 1000B, safe than long long max
static ll const INF = 1000000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Take input
    ll N, M, A, B, K, G;

    //printf("1\n");
    scanf("%lld %lld", &N, &M);
    scanf("%lld %lld %lld %lld", &A, &B , &K, &G);
    //printf("2\n");
    // George's visitation order
    queue<pair<ll, ll> > g_path;
    ll g_u = 0;
    ll g_v = 0;
    for(ll i = 0; i < G; i++)
    {
        scanf("%lld", &g_v);
        if (g_u != 0) {
            g_path.push({g_u, g_v});
            g_u = g_v;
        }else{
            g_u = g_v;
        }
    }
    //printf("3\n");
    vector<vector<ll> >AdjMatrix;
    AdjMatrix.resize(N + 1);
    for(int i = 0; i < AdjMatrix.size(); i++){
        AdjMatrix[i].resize(N + 1);
    }
    //Keeping track of all edges in graph
    vector<vector<pair<ll, ll> > > AdjList;
    AdjList.resize(N + 1);
    for(int i = 0; i < M; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        AdjMatrix[u][v] = (ll)w;
        AdjMatrix[v][u] = (ll)w;
        AdjList[u].push_back(make_pair((ll)v, (ll)w));
        AdjList[v].push_back(make_pair((ll)u, (ll)w));
    }
    //printf("4\n");
    // vector[u][v] = {block_start, block_end}
    vector<vector<pair<ll, ll> > > george{1001, vector<pair<ll, ll> >{1001, {-1, -1}}};
    ll g_time = 0;
    while(!g_path.empty()){
        pair<ll, ll> edge = g_path.front();
        g_path.pop();
        ll g_l = AdjMatrix[edge.first][edge.second];
        //printf("[%lld][%lld]:%lld\n", edge.first, edge.second, g_l);
        george[edge.first][edge.second] = make_pair(g_time, g_time + g_l);
        //printf("u:%lld v:%lld start:%lld end:%lld\n", edge.first, edge.second, g_time, g_time + g_l);
        george[edge.second][edge.first] = make_pair(g_time, g_time + g_l);
        //printf("u:%lld v:%lld start:%lld end:%lld\n", edge.second, edge.first, g_time, g_time + g_l);
        g_time += g_l;
    }
    //printf("george[2][4]:%lld", george[2][4]);
    //printf("5\n");
    // Vector with shortest distance from s to i
    vector<ll> dist;
    // Initialize to really big 
    dist.resize((ll)AdjList.size(), (ll)INF);
    // Starting node's distance to itself
    dist[A] = K;

    // Priority queue to keep track of distances
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push({K, A});
    while(!pq.empty()){
        // Cheapest node
        pair<ll, ll> node = pq.top();
        // Remove extracted node
        pq.pop();
        //distance from source
        ll d = node.first;
        // node index
        ll u = node.second;

        // We already have a better path
        if (d > dist[u]){
            // Try next element
            continue;
        }
        // Number of neighbours for current node
        ll neighbours = AdjList[u].size();

        for(ll i = 0; i < neighbours; i++)
        {   
            pair<ll, ll> v = AdjList[u][i];
            ll block_start = george[u][v.first].first;
            ll block_end = george[u][v.first].second;
            // Current time
            ll t = dist[u];
            //printf("u:%lld v:%lld t:%lld start:%lld end:%lld\n", u, v.first, t, block_start, block_end);
            ll add_time = v.second;
            if (block_start != -1 && t >= block_start && t < block_end) {
                // We need to wait
                add_time += block_end - t;
                //printf("%lld %lld %lld", t, block_end, add_time);
            }
            
            // If the path from the current node
            // is shorter than our saved path
            if (dist[u] + add_time < dist[v.first]) {     
                // Update distance
                dist[v.first] = dist[u] + add_time;
                // Enqueue new item 
                pq.push({dist[v.first], v.first});
            }
        }
    }
    printf("%lld\n", dist[B] - K);

    return 0;
}
