#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ll = long long;

// INF defined to 1000B, safe than long long max
static ll const INF = 1000000000000;

// Struct for representing an edge
struct Edge{

    // destination for edge
    ll dest; 
    // source of edge
    ll source; 
    // capacity of edge
    ll cap;
    // flow of edge
    ll flow;
    // The backwards Edge for this Edge
    struct Edge* reverse;
};

// Calculates the maxflow of graph network from s to t
vector<vector<Edge> > maxflow(vector<vector<Edge> > network, ll s, ll t){

    // Size of network
    ll n = network.size();
    // Maximum flow so far
    ll max_flow = 0;
    // How much flow we can increase
    ll flow; 
    // parent vector containing
    // parent[v] = {u, i}, where i is the index for that edge
    // in the adjacency-list
    vector<bool> dist;
    dist.resize(n);
    vector<pair<ll ,ll>> parent;
    parent.resize(n);
    // Breaks when we can't increase flow
    while(true){
        // distance in number of nodes from source
        
        dist.assign(n, false);
        dist[s] = true;
        // parent vector
        
        parent.assign(n,make_pair(-1, -1));

        queue<ll> q;
        q.push(s);
        while(!q.empty()){
            ll u = q.front();
            q.pop();

            // We have reached the sink, break
            if(u == t){
            break;
            }
            ll neighbours = network[u].size();
            // For all edges from u
            for(int i = 0; i < neighbours; i++){
                // Edge from u
                Edge edge = network[u][i];
                // Residual capacity > 0;
                // and the node is unvisited
                if(edge.cap - edge.flow > 0 && !dist[edge.dest]){
                    // Node is now visited
                    dist[edge.dest] = true;
                    // Add to queue
                    q.push(edge.dest);
                    // Fix parent
                    parent[edge.dest] = make_pair(u, i);
                }
            }
        }
        // Traverse the tree
        // We have traversed the full path
        // Reset flow
        flow = 0;
        // Current edge limit
        ll min_flow = INF;
        // Current node
        ll node = t;
        // save value and terminate
        while(true){
            // We've reached the source
            if(node == s){
            // The currently saved flow is the limit
            flow = min_flow;
            break;
            }
            // The path ends here
            else if(parent[node].first != -1){
                // Limiting flow
                // Find the edge from parent to child
                Edge f_edge = network[parent[node].first][parent[node].second];
                min_flow = min(min_flow, f_edge.cap - f_edge.flow);
                node = parent[node].first;
            }else{
                break;
            }
        }

        if(flow == 0){
            break;
        }

        node = t;
        // Update the flows
        while(true){
            // We've reached the source
            if(node == s){
            break;
            }
            else{
                Edge m_edge = network[parent[node].first][parent[node].second];
                Edge* r_m_edge = m_edge.reverse;

                m_edge.flow += flow;
                r_m_edge->flow -= flow;
            }
        }
        max_flow += flow;
    }
    return network;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    return 0;
}
