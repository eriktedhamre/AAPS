#include <bits/stdc++.h>
using namespace std;

// Treasure map
vector<vector<char> > t_map;
// Keep track of breeze squares 
vector<vector<bool> > breeze;
// Visited
vector<vector<bool> > visited;
// Possible moves
vector<pair<int, int> > moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    
    pair<int, int> P;
    int col, row;

    scanf("%d %d", &col, &row);

    breeze.resize(col, vector<bool>(row, false));
    t_map.resize(col, vector<char>(row, '.'));
    visited.resize(col, vector<bool> (row, false));

    char token;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {

            scanf("%c", &token);
            while(isspace(token)) { scanf("%c", &token); }

            switch (token) {
                case '.':
                    t_map[j][i] = '.';
                    break;
                case '#':
                    t_map[j][i] = '#';
                    visited[j][i] = true;
                    break;
                case 'T':
                    t_map[j][i] = 'T';
                    breeze[j + 1][i] = true; breeze[j - 1][i] = true;
                    breeze[j][i + 1] = true; breeze[j][i - 1] = true;
                    break;
                case 'G':
                    t_map[j][i] = 'G';
                    break;
                case 'P':
                    t_map[j][i] = 'P';
                    P = make_pair(j, i);
                    visited[j][i] = true;
                    break;         
            }
        }
    }

    queue<pair<int, int> > q;
    q.push(P);

    int gold = 0;
    while(!q.empty()) {
        pair<int, int> s = q.front();
        q.pop();
        
        if(t_map[s.first][s.second] == 'G')
            gold++;

        if(breeze[s.first][s.second])
            continue;

        for(int i = 0; i < 4; i++) {

            pair<int, int> next = make_pair(s.first + moves[i].first, s.second + moves[i].second);

            if((next.first < col) && (next.first > 0) &&
               (next.second > 0)  && (next.second < row) &&
               (!visited[next.first][next.second])) {

                q.push(next);
                visited[next.first][next.second] = true;
            }
        }   
    }
    printf("%d\n", gold);
}
