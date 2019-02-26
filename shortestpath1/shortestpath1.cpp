#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ll = long long;

// INF defined to 1000B, safe than long long max
static ll const INF = 1000000000000;

// Calculates the shortest path from node start to all nodes in the graph
// Returns vector<Distance, Pair> where the node index is the index
vector<pair<ll, ll> > shortest_path(vector<vector<pair<ll, ll> > > AdjList, ll s){
    // Result vector
    vector<pair<ll, ll> > dist_parent;

    // Vector with the parent node for the 
    // shortest path to each node
    vector<ll> parent;
    // Parent to -1 if it is itself...
    parent.resize((long long)AdjList.size(), -1);
    // Vector with shortest distance from s to i
    vector<ll> dist{(long long)AdjList.size(), INF};
    // Starting node's distance to itself
    dist[s] = 0;

    // Priority queue to keep track of distances
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push({0, s});

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

            // If the path from the current node
            // is shorter than our saved path
            if (dist[u] + v.second < dist[v.first]) {
                // Update distance
                dist[v.first] = dist[u] + v.second;
                // Update parent pointer
                parent[v.first] = u;
                // Enqueue new item 
                pq.push({dist[v.first], v.first});
            }
        }
    }

    for(ll i = 0; i < AdjList.size(); i++){
        dist_parent.push_back({dist[i], parent[i]});
    }
    return dist_parent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Adjacency list for the graph G
    vector<vector<pair<ll, ll> > > AdjList;

    ll n, m, q, s;

    while(scanf("%lld %lld %lld %lld", &n, &m , &q, &s)){
        // Break -- Last Row
        if (n == 0 && m == 0 && q == 0 && s == 0){
            break;
        }

        AdjList.resize(n);
        
        ll u, v, w;
        for(int i = 0; i < m; i++)
        {
            scanf("%lld %lld %lld", &u, &v, &w);
            AdjList[u].push_back({v, w});
        }

        vector<pair<ll ,ll> > dist_parent = shortest_path(AdjList, s);

        ll dest;
        for(int i = 0; i < q; i++)
        {
            scanf("%lld", &dest);
            if (dist_parent[dest].first == INF) {
                printf("Impossible\n");
            }
            
            printf("%lld\n", dist_parent[dest].first);
        }

        printf("\n");
        AdjList.clear();
    }
    return 0;
}
