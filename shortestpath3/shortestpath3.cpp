#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ll = long long;

// INF defined to 1000B, safe than long long max
static ll const INF = 1000000000000;

// Calculates the shortest path from s to all nodes
// with Bellman-Ford's algorithm
vector<pair<ll, ll> > shortest_path(vector<vector<pair<ll, ll> > > AdjList, ll s){
    // Result vector
    vector<pair<ll, ll> > dist_parent;

    ll n = (ll)AdjList.size();
    // Parent vector
    vector<ll> parent;
    // Initialized to -1 when pointing to itself
    parent.resize(n, -1);

    // Distance vector
    vector<ll> dist;
    // Initialized to INF
    dist.resize(n, INF);
    dist[s] = 0;

    // Relax edges  k = n - 1 times
    // since a path can at most contain all nodes once
    for(ll k = 0; k < n - 1; k++){
        // For each node
        for(ll u = 0; u < n; u++){
            // For each neighbour
            for(ll i = 0; i < (ll)AdjList[u].size(); i++){
                // Current neighbour
                pair<ll, ll> v = AdjList[u][i];

                // Relaxation of edge u -> v
                if(dist[u] != INF && dist[v.first] > dist[u] + v.second){
                    dist[v.first] = dist[u] + v.second;
                    // Saving parent pointer
                    parent[v.first] = u;
                }
            }
        }
    }

    // Run the algorithm a second time
    // might be too slow, liked the other approach better
    // but couldn't get it to work
    for(ll k = 0; k < n - 1; k++){
        // For each node
        for(ll u = 0; u < n; u++){
            // For each neighbour
            for(ll i = 0; i < (ll)AdjList[u].size(); i++){
                // Current neighbour
                pair<ll, ll> v = AdjList[u][i];

                // Relaxation of edge u -> v
                if(dist[u] != INF && dist[v.first] > dist[u] + v.second){
                    dist[v.first] = -INF;
                }
            }
        }
    }

    /*
    //printf("Negative cycle detection \n");
    // Detect negative cycles and fix them.
    // Keep check of nodes in the current cycle
    vector<ll> n_cycle;
    n_cycle.assign(n, 0);

    // For each node
    for(ll u = 0; u < n; u++){
        // For each neighbour
        for(ll i = 0; i < (ll)AdjList[u].size(); i++){
            // Current neighbour
            pair<ll, ll> v = AdjList[u][i];

            // There is no path to
            if(dist[v.first] == INF || dist[v.first] == -INF ){
                continue;
            }
            // If Relaxation of edge u -> v 
            // is still possible u is part of a
            // negative cycle
            if(dist[u] != INF && dist[v.first] > dist[u] + v.second){
                parent[v.first] = u;
                ll node = v.first;
                // Find all nodes in cycle
                n_cycle[node] = 1;
                n_cycle[s] = 1;
                dist[node] = -INF;
                while(!n_cycle[parent[node]]){
                    //printf("node: %lld parent: %lld", node, parent[node]);
                    n_cycle[parent[node]] = 1;
                    node = parent[node];
                    dist[node] = -INF;
                }
                n_cycle.clear();

            }
        }
    }
    */
    //Create result vector from
    // parent and dist vectors
    for(ll i = 0; i < AdjList.size(); i++){
        dist_parent.push_back({(ll)dist[i], (ll)parent[i]});
    }
    return dist_parent;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //printf("1dasdasd\n");
    vector<vector<pair<ll, ll> > > AdjList;

    ll n, m, q, s;
    int test_case = 0;
    while(scanf("%lld %lld %lld %lld", &n, &m, &q, &s)){
        // Done
        if(n == 0 && m == 0 && q == 0 && s == 0){
            break;
        }

        if(test_case != 0){
            printf("\n");
        }

        // List initilization
        AdjList.resize(n);
        //printf("Preinput\n");
        ll u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%lld %lld %lld", &u, &v, &w);
            AdjList[u].push_back(make_pair(v, w));
        }
        //printf("Precalculation\n");
        vector<pair<ll ,ll> > dist_parent = shortest_path(AdjList, s);
        //printf("Postcalculation\n");
        ll dest;
        for(int i = 0; i < q; i++)
        {
            scanf("%lld", &dest);
            if (dist_parent[dest].first == INF) {
                printf("Impossible\n");
            }
            else if(dist_parent[dest].first == -INF){
                printf("-Infinity\n");
            }
            else{
                printf("%lld\n", dist_parent[dest].first);
            }
        }
        test_case++;
        AdjList.clear();
    }

    return 0;
}
