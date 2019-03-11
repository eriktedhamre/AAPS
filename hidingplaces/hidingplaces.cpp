#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

char convert(int col){
    
    switch(col){
        case 0:
            return 'a';
            break;
        case 1:
            return 'b';
            break;
        case 2:
            return 'c';
            break;
        case 3:
            return 'd';
            break;
        case 4:
            return 'e';
            break;
        case 5:
            return 'f';
            break;
        case 6:
            return 'g';
            break;
        case 7:
            return 'h';
            break;
        default:
            return -1;
            break;
    }
}

int convert_int(char a){

    switch(a){
        case 'a':
            return 0;
            break;
        case 'b':
            return 1;
            break;
        case 'c':
            return 2;
            break;
        case 'd':
            return 3;
            break;
        case 'e':
            return 4;
            break;
        case 'f':
            return 5;
            break;
        case 'g':
            return 6;
            break;
        case 'h':
            return 7;
            break;
        default:
            return -1;
            break;
    }
}


// Vectors used for knight movement
vector<int> drow{2, 2, 1, -1, -2, -2, -1, 1};
vector<int> dcol{-1, 1, 2, 2, 1, -1, -2, -2};
// Chessboard representing the moves from the start node
vector<vector<int> > chessboard;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    scanf("%d", &n);

    for(int k = 0; k < n; k++){

        chessboard.assign(8, vector<int>(8, -1));
        char c_in;
        scanf(" %c", &c_in);
        //printf("%c", c_in);
        int start_col = convert_int(c_in);
        int start_row;
        scanf("%d", &start_row);
        //printf("%d", start_row);
        //printf("\n");
        start_row--;
        //printf("start_row:%d start_col:%d\n", start_row, start_col);
        chessboard[start_row][start_col] = 0;

        queue<pair<int, int> > q;
        q.push(make_pair(start_row, start_col));
        while(!q.empty()){
            pair<int, int> u = q.front();
            q.pop();
            int row = u.first;
            int col = u.second;
            for(int i = 0; i < 8; i++){
                int n_row = row + drow[i];
                int n_col = col + dcol[i];
                if(0 <= n_row && n_row < 8 && 0 <= n_col && n_col < 8 && chessboard[n_row][n_col] == -1){
                    chessboard[n_row][n_col] = chessboard[row][col] + 1;
                    q.push(make_pair(n_row, n_col)); 
                }
            }
        }

        string output;
        int greatest_dist = -1;
        for(int i = 7; i >= 0; i--){
            for(int j = 0; j < 8; j++){
                if(chessboard[i][j] > greatest_dist){
                    greatest_dist = chessboard[i][j];
                    output.clear();
                    output += to_string(greatest_dist);
                    char c = convert(j);
                    output += " ";
                    output +=c;
                    output +=to_string(i + 1);
                }
                else if(chessboard[i][j] == greatest_dist){
                    char c = convert(j);
                    output +=" ";
                    output += c;
                    output+= to_string(i + 1);
                }
            }
        }
        
        printf("%s\n", output.c_str());
    }

    
    return 0;
}
