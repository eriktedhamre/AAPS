#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ll = long long;

// INF defined to 1000B, safe than long long max
static ll const INF = 1000000000000;

// Calculates the shortest path from s to all nodes
// with Bellman-Ford's algorithm
vector<vector<pair<ll, ll> > > shortest_path(vector<vector<pair<ll, ll> > > AdjList, ll s){
    // Result vector
    vector<vector<pair<ll, ll> > > dist_parent;

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
            for(ll i = 0; i <(ll)AdjList[u].size(); i++){
                // Current neighbour
                pair<ll, ll> v = AdjList[u][i];

                // Relaxation of edge u -> v
                if(dist[v.first] > dist[u] + v.second){
                    dist[v.first] = dist[u] + v.second;
                    // Saving parent pointer
                    parent[v.first] = u;
                }
            }
        }
    }

    // Detect negative cycles and fix them.

    // For each node
    for(ll u = 0; u < n; u++){
        // For each neighbour
        for(ll i = 0; i <(ll)AdjList[u].size(); i++){
            // Current neighbour
            pair<ll, ll> v = AdjList[u][i];

            // If Relaxation of edge u -> v 
            // is still possible u is part of a
            // negative cycle
            if(dist[v.first] > dist[u] + v.second){

                dist[v.first] = -INF;
                parent[v.first] = u;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    return 0;
}
