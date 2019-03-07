#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ll = long long;

// INF defined to 1000B, safe than long long max
static ll const INF = 1000000000000;

// Uses floyd-warshall to calculate all pairs shortest path
// The adjacency matrix should have a zero diagonal and
// INF for [u][v] that has no path
vector<vector<ll> > shortest_path_all_pairs(vector<vector<ll> > AdjMatrix){
    ll n = AdjMatrix.size();
    // Calculate shortest path
    // Test all nodes as intermediary node
    for(ll k = 0; k < n; k++){
        // Loop through matrix
        for(ll u = 0; u < n; u++){
            for(ll v = 0; v < n; v++){
                // If there is a faster path from u to v
                // going through k, update matrix
                if(AdjMatrix[u][k] != INF && AdjMatrix[k][v] != INF &&
                AdjMatrix[u][v] > AdjMatrix[u][k] + AdjMatrix[k][v]){
                    AdjMatrix[u][v] = AdjMatrix[u][k] + AdjMatrix[k][v];
                }
            }
        }
    }

    // Check for negative cycles
    // Loop through matrix
    for(ll k = 0; k < n; k++){
        for(ll u = 0; u < n; u++){
            for(ll v = 0; v < n; v++){
                //We have already done this one
                if(AdjMatrix[u][v] == -INF){
                    continue;
                }
                // There is a path from u to v via k
                // and k is part of a negative cycle
                else if(AdjMatrix[k][k] < 0 && AdjMatrix[u][k] != INF && AdjMatrix[k][v] != INF){
                    AdjMatrix[u][v] = -INF;
                }
            }
        }
    }

    return AdjMatrix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<ll> > AdjMatrix;

    // # of nodes, # of edges, # of queries
    ll n, m, q;
    int test_case = 0;
    while(scanf("%lld %lld %lld", &n, &m, &q)){
        //We are done
        if(n == 0 && m == 0 && q == 0){
            break;
        }

        if(test_case != 0){
            printf("\n");
        }

        // Matrix initilization
        AdjMatrix.assign(n, vector<ll>(n, INF));

        ll u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%lld %lld %lld", &u, &v, &w);
            AdjMatrix[u][v] = min(w, AdjMatrix[u][v]);
        }
        // Distance from node to itself is 0
        for(int i = 0; i < n; i++){ AdjMatrix[i][i] = 0; }
        
        AdjMatrix = shortest_path_all_pairs(AdjMatrix);

        for(int i = 0; i < q; i++){
            scanf("%lld %lld", &u, &v);
            ll dist = AdjMatrix[u][v];

            if(dist == INF){
                printf("Impossible\n");
            }
            else if(dist == -INF){
                printf("-Infinity\n");
            }
            else{
                printf("%lld\n", dist);
            }
        }
        test_case++;
    }

    return 0;
}
