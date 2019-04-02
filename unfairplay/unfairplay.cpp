#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

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
                min_flow = min(min_flow, f_edge->cap - f_edge->flow);
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
                Edge* m_edge = &network[parent[node].first][parent[node].second];
                Edge* back_m_edge = &network[m_edge->dest][m_edge->rev_index];
                m_edge->flow += flow;
                back_m_edge->flow -= flow;
                node = parent[node].first; 
            }
        }
        max_flow += flow;
    }
    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int teams, matches;
    

    while(scanf(" %d", &teams) > 0 && teams != -1){
        vector<int> t_score;
        vector<pair<int, int> > match;
        vector<vector<Edge> > network;
        t_score.resize(teams);

        scanf("%d", &matches);
        match.resize(matches);
        
        int score;
        int highest_score = 0;
        for(int i = 0; i < teams - 1; i++)
        {
            scanf("%d", &score);
            t_score[i] = score;
            if(score > highest_score){
                highest_score = score;
            }
        }
        scanf("%d", &score);
        t_score[teams - 1] = score;
        /*
        for(int i = 0; i < t_score.size(); i++){
            printf("t_score[%d]:%d\n", i, t_score[i]);
        }
        */
        int a, b;
        int N_games = 0;
        for(int i = 0; i < matches; i++)
        {
            scanf("%d %d", &a, &b);
            if(a == teams || b == teams){
                N_games++;
            }
            match[i] = make_pair(a - 1, b - 1);
        }
        /*
        for(int i = 0; i < match.size(); i++){
            printf("match[%d] %d vs %d\n", i, match[i].first + 1, match[i].second + 1);
        }
        */
        int played = matches - N_games;
        //printf("played:%d\n", played);
        int total_nodes = played + teams - 1 + 2;
        int sink = total_nodes - 1;
        network.clear();
        network.resize(total_nodes);

        int s = 0;
        int N_score = t_score.back() + 2 * N_games;
        //printf("h_score:%d N_score:%d\n", highest_score, N_score);
        if (highest_score >= N_score) {
            printf("NO\n");
            continue;
        }
        else if(matches == 0){
            printf("\n");
            continue;
        }

        //Create Edges between Source and Matches
        for(int i = 1; i <= played; i++)
        {
            Edge edge{};
            edge.source = s;
            edge.dest = i;
            edge.cap = 2;

            Edge r_edge{};
            r_edge.source = i;
            r_edge.dest = 0;

            network[s].push_back(edge);
            network[i].push_back(r_edge);
            network[s].back().rev_index = network[i].size() - 1;
            network[i].back().rev_index = network[s].size() - 1;
        }
        
        // Create Edges between Matches and Teams
        int i_offset = 0;
        for(int i = 0; i < match.size(); i++)
        {
            pair<int, int> game = match[i];
            if(game.first == teams - 1 || game.second == teams - 1) {
                i_offset++;
                continue;
            }
            //printf("t1:%d t2:%d i:%d\n", game.first + 1, game.second + 1, i);
            int j = i - i_offset + 1;
            int t1_index = game.first + played + 1;
            int t2_index = game.second + played + 1;
            //printf("t1_index:%d t2_index:%d j:%d\n", t1_index, t2_index, j);
            Edge edge1{};
            edge1.source = j;
            edge1.dest = t1_index;
            edge1.cap = 2;

            Edge r_edge1{};
            r_edge1.source = t1_index;
            r_edge1.dest = j;

            network[j].push_back(edge1);
            network[t1_index].push_back(r_edge1);
            network[j].back().rev_index = network[t1_index].size() - 1;
            network[t1_index].back().rev_index = network[j].size() - 1;

            Edge edge2{};
            edge2.source = j;
            edge2.dest = t2_index;
            edge2.cap = 2;

            Edge r_edge2{};
            r_edge2.source = t2_index;
            r_edge2.dest = j;

            network[j].push_back(edge2);
            network[t2_index].push_back(r_edge2);
            network[j].back().rev_index = network[t2_index].size() - 1;
            network[t2_index].back().rev_index = network[j].size() - 1;
        }
        
        //Create edges between teams and sink
        for(int i = 0; i < teams - 1; i++){
            int team_i = i + played + 1;
            Edge edge1{};
            edge1.source = team_i;
            edge1.dest = sink;
            edge1.cap = N_score - t_score[i] - 1;

            Edge r_edge1{};
            r_edge1.source = sink;
            r_edge1.dest = team_i;

            network[team_i].push_back(edge1);
            network[sink].push_back(r_edge1);
            network[team_i].back().rev_index = network[sink].size() - 1;
            network[sink].back().rev_index = network[team_i].size() - 1;
        }
        
        /*
        for(int i = 0; i < network.size(); i++){
            for(int j = 0; j < network[i].size(); j++){
                Edge *edge3 = &network[i][j];
                printf("u:%lld v:%lld cap:%lld\n", edge3->source, edge3->dest, edge3->cap);
            }
        }
        */
        int flow = maxflow(network, s, sink);

        if(flow < played * 2){
            //printf("played:%d flow:%d\n", played, flow);
            printf("NO\n");
            continue;
        }

        i_offset = 0;
        for(int i = 0; i < match.size(); i++){
            pair<int, int> game = match[i];
            if(game.first == teams - 1) {
                i_offset++;
                printf("0 ");
                continue;
            }
            if(game.second == teams - 1){
                i_offset++;
                printf("2 ");
                continue;
            }

            int j = i - i_offset + 1;
            for(int k = 0; k < network[j].size(); k++){
                Edge *edge = &network[j][k];
                if(edge->cap == 0){
                    continue;
                }

                if(edge->flow == 0){
                    if(edge->dest - played - 1 == game.first){
                        printf("2 ");
                    }
                    else{
                        printf("0 ");
                    }
                }
                else if(edge->flow == 1){
                    printf("1 ");
                }
                else{
                    if(edge->dest - played - 1 == game.first){
                        printf("0 ");
                    }
                    else{
                        printf("2 ");
                    }
                }
                break;
            }    
        }
        printf("\n");
    }
    return 0;
}
