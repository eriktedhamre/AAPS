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
    struct Edge *reverse;
};

// Used in the function below
vector<ll> parent; // parent vector
ll flow; // How much flow we can increase
// Calculates the maxflow of graph network from s to t
vector<vector<Edge> > maxflow(vector<vector<Edge> > network, ll s, ll t){

    // Size of network
    ll n = network.size();
    // distance in number of nodes from source
    vector<bool> dist.assign(n, false);
    dist[s] = true;
    // parent vector
    parent.assign(n, -1);

    queue<ll> q;
    q.push(s);

    ll max_flow = 0;
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
                parent[edge.dest] = u;
            }
        }

        ll f = augment();

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    return 0;
}
