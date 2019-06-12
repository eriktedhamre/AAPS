/*
* Author: Erik Tedhamre
*/
#include <bits/stdc++.h>
using namespace std;

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
    parent.resize((ll)AdjList.size(), -1);
    // Vector with shortest distance from s to i
    vector<ll> dist;
    // Initialize to really big 
    dist.resize((ll)AdjList.size(), (ll)INF);
    // Starting node's distance to itself
    dist[s] = 0;

    // Priority queue to keep track of distances
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push({0, s});

    while(!pq.empty()){

        pair<ll, ll> node = pq.top();
        // Remove extracted node
        pq.pop();
        //distance from source
        ll d = node.first;
        // node index
        ll u = node.second;

        // We already have a better path
        if (d > dist[u]){
            continue;
        }

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

    // Adjacency list for the graph G
    vector<vector<pair<ll, ll> > > AdjList;

    ll n, m, q, s;
    int test_case = 0;
    while(scanf("%lld %lld %lld %lld", &n, &m , &q, &s)){

        if (n == 0 && m == 0 && q == 0 && s == 0){
            break;
        }

        if(test_case != 0){
            printf("\n");
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
            else{
                printf("%lld\n", dist_parent[dest].first);
            }
        }
        test_case++;
        AdjList.clear();
    }
}
