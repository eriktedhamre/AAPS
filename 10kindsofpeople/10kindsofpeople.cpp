#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <queue>
using namespace std;

//            (-1, 0)
//     (0,-1)  (0,0) (0, 1)
//             (1, 0)
//

void modified_bfs(int r1, int c1, int group_number, vector<vector<bool> > &map, vector<vector<int> > &groups, vector<int> &row, vector<int> &col)
{
    bool type = map[r1][c1];
    queue<pair<int, int> > q;
    groups[r1][c1] = group_number;
    q.push(make_pair(r1, c1));

    int r_size = map.size();
    int c_size = map[0].size();

    pair<int, int> v;
    int v_r;
    int v_c;
    int n_v_r;
    int n_v_c;

    while (!q.empty())
    {
        v = q.front();
        q.pop();
        v_r = v.first;
        v_c = v.second;
        for (size_t i = 0; i < 4; i++)
        {
            n_v_r = v_r + row[i];
            n_v_c = v_c + col[i];
            if (0 <= n_v_r && n_v_r < r_size && 0 <= n_v_c && n_v_c < c_size && map[n_v_r][n_v_c] == type && groups[n_v_r][n_v_c] == 0)
            {
                groups[n_v_r][n_v_c] = group_number;
                q.push(make_pair(n_v_r, n_v_c));
            } 
        }
    }
}

int main()
{
    int r, c;
    string line;

    getline(cin, line);

    istringstream is( line );
    string current_string;
    getline(is, current_string, ' ');
    r = stoi(current_string);
    getline(is, current_string, ' ');
    c = stoi(current_string);

    vector<vector<bool> > map(r, vector<bool>(c, false));
    vector<vector<int> > groups(r, vector<int>(c, 0));
    vector<int> row;
    row.push_back(0);
    row.push_back(-1);
    row.push_back(0);
    row.push_back(1);
    vector<int> col;
    col.push_back(-1);
    col.push_back(0);
    col.push_back(1);
    col.push_back(0);

    //cout << "r " << r << " c " << c << "\n";

    for (size_t i = 0; i < r; i++)
    {
        getline(cin, line);
        for (size_t j = 0; j < c; j++)
        {
            if(line[j] == '1')
            {
                map[i][j] = true;
            }
            continue;
        }
    }

    int questions;
    int r1, c1, r2, c2;
    int group_number = 1;

    //cout << "Got to questions" << "\n";

    cin >> questions;

    for (size_t i = 0; i < questions; i++)
    {
        cin >> r1 >> c1 >> r2 >> c2;

        //cout << r1  << " " << c1 << " " << r2 << " " << c2 << "\n";

        r1--;
        c1--;
        r2--;
        c2--;

        if (map[r1][c1] != map[r2][c2])
        {
            cout << "neither" << "\n";
            continue;
        }

        if( groups[r1][c1] == 0)
        {
            //cout << "1" << "\n";
            modified_bfs(r1, c1, group_number, map, groups, row, col);
            group_number++;
        }
        if ( groups[r2][c2] == 0)
        {
            //cout << "2" << "\n";
            modified_bfs(r2, c2, group_number, map, groups, row, col);
            group_number++;
        }
        
        if (groups[r1][c1] == groups[r2][c2])
        {
            if (map[r1][c1])
            {
                cout << "decimal" << "\n";
            }
            else
            {
                cout << "binary" << "\n";
            }
        }
        else
        {
            cout << "neither" << "\n";
        }
        
    }
}