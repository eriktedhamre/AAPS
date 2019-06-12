/*
* Author: Erik Tedhamre
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// INF defined to 1000B, safe than long long max
static ll const INF = 1000000000000;

// Takes an expanded Adjacency Time List, on the form (v, t0, P, d)
// t0 first time the edge can be traversed
// P the interval at when the edge can be traversed again
// d the time it takes to traverse the edge
// Returns vector<Distance, Pair> where the node index is the index
vector<pair<ll, ll> > shortest_path(vector<vector<vector<ll> > > AdjTimeList, ll s){

    vector<pair<ll, ll> > dist_parent;

    // Vector with the parent node for the 
    // shortest path to each node
    vector<ll> parent;
    // Parent to -1 if it is itself...
    parent.resize((ll)AdjTimeList.size(), -1);
    // Vector with shortest distance from s to i
    vector<ll> dist;
    dist.resize((ll)AdjTimeList.size(), (ll)INF);
    dist[s] = 0;

    // Priority queue to keep track of distances
    // keep the next time the node is available in the queue
    // if we've passed the time for it when we reach it re-insert it into the queue
    // at the next time we can access it
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
    pq.push({0, s});

    while(!pq.empty()){

        pair<ll, ll> node = pq.top();
        // Remove extracted node
        pq.pop();
        // time from source
        ll t = node.first;
        // node index
        ll u = node.second;

        // We already have a better path
        if (t > dist[u]){
            continue;
        }

        ll neighbours = AdjTimeList[u].size();

        for(ll i = 0; i < neighbours; i++)
        {   
            vector<ll> v_info = AdjTimeList[u][i];

            // Calculate next time it can be accessed
            ll v = v_info[0];
            ll t0 = v_info[1];
            ll P = v_info[2];
            ll d = v_info[3];

            ll add_time;

            // Wait until we can pass
            if(t <= t0){
                // Wait for start time and add the travel time
                add_time = t0 - t + d; 
            }
            else if(P != 0){
                ll t_diff = t-t0;
                ll p_mult = ceil(t_diff/(long double)P);
                add_time = t0 + p_mult*P - t + d;
            }
            // P == 0 && t > t0
            else{
                continue;
            }
            

            // If the path from the current node
            // is shorter than our saved path
            if (dist[u] + add_time < dist[v]) {     
                dist[v] = dist[u] + add_time;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    //Create result vector from
    // parent and dist vectors
    for(ll i = 0; i < AdjTimeList.size(); i++){
        dist_parent.push_back({(ll)dist[i], (ll)parent[i]});
    }
    return dist_parent;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Adjacency list for the graph G
    vector<vector<vector<ll> > > AdjTimeList;

    ll n, m, q, s;
    int test_case = 0;
    while(scanf("%lld %lld %lld %lld", &n, &m , &q, &s)){
        
        if (n == 0 && m == 0 && q == 0 && s == 0){
            break;
        }

        if(test_case != 0){
            printf("\n");
        }

        AdjTimeList.resize(n);
        
        ll u, v, t0, P, d;
        for(int i = 0; i < m; i++)
        {
            scanf("%lld %lld %lld %lld %lld", &u, &v, &t0, &P, &d);
            AdjTimeList[u].push_back({v, t0, P, d});
        }

        vector<pair<ll ,ll> > dist_parent = shortest_path(AdjTimeList, s);

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
        AdjTimeList.clear();
    }

    return 0;
}
