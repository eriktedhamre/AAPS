#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    // BFS all reachable nodes
    int t;
    scanf("%d", &t);

    vector<pair<int, int> > coord;

    for(int i = 0; i < t; i++){
        int n;
        scanf("%d", &n);
        coord.resize(n + 2);

        int x, y;
        // Home
        scanf("%d %d", &x, &y);
        //printf("home:%d home:%d\n", &x, &y);
        coord[0] = make_pair(x, y);

        for(int j = 1; j <= n; j++){
            // Every store
            scanf("%d %d", &x, &y);
            //printf("store:%d store:%d\n", &x, &y);
            coord[j] = make_pair(x, y);
        }
        
        // The goal
        scanf("%d %d", &x, &y);
        //printf("goal:%d goal:%d\n", &x, &y);
        coord[n + 1] = make_pair(x, y);

        vector<vector<int> > AdjList;
        AdjList.resize(n + 2);
        vector<vector<bool> > AdjMatrix;
        AdjMatrix.resize(n + 2, vector<bool>(n + 2, false));
        for(int j = 0; j < n + 2; j++){
            for(int k = 0; k < n + 2; k++){
                if(k == j || AdjMatrix[j][k]){
                    continue;
                }
                ll dist = abs(coord[j].first - coord[k].first) + abs(coord[j].second - coord[k].second);
                if(dist > 1000){
                    continue;
                }
                else{
                    AdjList[j].push_back(k);
                    AdjList[k].push_back(j);
                    AdjMatrix[j][k] = true;
                    AdjMatrix[k][j] = true;
                }
            }
        }

        bool happy = false;
        vector<bool> dist;
        dist.resize(n + 2);
        dist[0] = true;
        queue<ll> q;
        q.push(0);
        while(!q.empty()){
            ll u = q.front();
            q.pop();

            // We have reached the sink, break
            if(u == n+1){
                happy = true;
                break;
            }
            ll neighbours = AdjList[u].size();
            // For all edges from u
            for(int j = 0; j < neighbours; j++){
                int v = AdjList[u][j];

                if(!dist[v]){
                    // Node is now visited
                    dist[v] = true;
                    // Add to queue
                    q.push(v);
                }
            }
        }

        if(happy){
            printf("happy\n");
        }
        else{
            printf("sad\n");
        }
        AdjMatrix.clear();
        AdjList.clear();
        coord.clear();
    }

    return 0;
}
