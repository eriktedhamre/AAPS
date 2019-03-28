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
    ll cap = 0;
    // flow of edge
    ll flow = 0;
    // Index for the reverse edge in network[dest][rev_index]
    ll rev_index;
};

// Calculates the maxflow of graph network from s to t
ll maxflow(vector<vector<Edge> > &network, ll s, ll t){
    // Size of network
    ll n = network.size();
    // Maximum flow so far
    ll max_flow = 0;
    // How much flow we can increase
    ll flow; 
    // parent vector containing
    // parent[v] = {u, i}, where i is the index for that edge
    vector<pair<ll ,ll>> parent;
    parent.resize(n);
    // Breaks when we can't increase flow
    while(true){
        // parent vector
        parent.assign(n, make_pair(-1, -1));

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
                Edge *edge = &network[u][i];
                // Residual capacity > 0;
                // and the node is unvisited
                //printf("u:%lld v:%lld flow:%lld\n", edge->source, edge->dest, edge->flow);
                if(parent[edge->dest].first == -1 && edge->dest != s && (edge->cap - edge->flow) > 0){
                    // Add to queue
                    q.push(edge->dest);
                    // Fix parent
                    parent[edge->dest] = make_pair(u, i);
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
            //printf("node:%lld\n", node);
            //printf("s:%lld\n", s);
            //printf("node %lld\n", node);
            if(node == s){
            // The currently saved flow is the limit
            flow = min_flow;
            break;
            }
            // The path ends here
            else if(parent[node].first != -1){
                // Limiting flow
                // Find the edge from parent to child
                Edge *f_edge = &network[parent[node].first][parent[node].second];
                //printf("u:%lld v:%lld c:%lld r:%d\n", f_edge.source, f_edge.dest, f_edge.cap, f_edge.r_edge);
                min_flow = min(min_flow, f_edge->cap - f_edge->flow);
                node = parent[node].first;
            }else{
                //printf("This isn't right\n");
                break;
            }
        }
        //printf("flow:%lld\n", flow);
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
                Edge* m_edge = &network[parent[node].first][parent[node].second];
                Edge* back_m_edge = &network[m_edge->dest][m_edge->rev_index];
                m_edge->flow += flow;
                back_m_edge->flow -= flow;
                //printf("u:%lld v:%lld flow:%lld\n", m_edge->source, m_edge->dest, m_edge->flow);
                //printf("b_u:%lld b_v:%lld b_flow:%lld\n", back_m_edge->source, back_m_edge->dest, back_m_edge->flow);              
                /*
                if (r_m_edge->flow < 0 || m_edge->flow < 0) {
                    printf("Reverse edge 2\n");
                }
                */
                node = parent[node].first; 
            }
        }
        max_flow += flow;
    }
    //printf("max_flow:%lld\n",max_flow);
    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    int n, m, s, t;

    scanf("%d %d %d %d", &n, &m, &s, &t);
    //printf("%d %d %d %d", n, m, s, t);
    vector<vector<Edge> > network;
    network.resize(n);
    for(int i = 0; i < m; i++)
    {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        Edge edge{};
        edge.source = u;
        edge.dest = v;
        edge.cap = c;

        Edge r_edge{};
        r_edge.source = v;
        r_edge.dest = u;

        network[u].push_back(edge);
        network[v].push_back(r_edge);
        network[u].back().rev_index = network[v].size() - 1;
        network[v].back().rev_index = network[u].size() - 1;
    }

   ll result = maxflow(network, s, t);

    vector<Edge*> path;
    
    vector<bool> visited;
    visited.assign(n, false);
    queue<ll> q;
    q.push(s);
    while(!q.empty()){
        ll u = q.front();
        q.pop();
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        ll neighbours = network[u].size();
        // For all edges from u
        for(int i = 0; i < neighbours; i++){
            // Edge from u
            Edge *edge = &network[u][i];

            if(edge->flow > 0){
                path.push_back(edge);
                q.push(edge->dest);
            }
        }
    }

    printf("%d %lld %lu\n", n, result, path.size());

    for(int i = 0; i < path.size(); i++)
    {
        printf("%lld %lld %lld\n", path[i]->source, path[i]->dest, path[i]->flow);
    }
    
    
    return 0;
}
