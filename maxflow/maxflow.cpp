#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ll = long long;

// INF defined to 1000B, safe than long long max
static ll const INF = 1000000000000;

// Struct for representing an edge
struct Edge{

    ll dest; // destination node

    ll source; // Index for edge
                // connecting to this edge
    ll cap; // flow capacity for edge

    ll flow; // Current flow

     
    
};

vector<vector<Edge> > maxflow(vector<vector<Edge> > network, ll source, ll dest){

    
    ll n = network.size();
    vector<ll> dist.resize(n, INF);
    
    queue<ll> q; q.push(s);

    ll max_flow = 0;
    while(!q.empty()){
        ll u = q.front();
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    return 0;
}
