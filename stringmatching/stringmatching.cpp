/*
* Author: Erik Tedhamre
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> find(string p, string t){
    vector<ll> b_table;
    vector<ll> res;
    // Construct back_table
    b_table.assign(p.size() + 1, 0);
    ll i = 0, j = -1, p_s = p.size(), t_s = t.size();
    // To make things easier, in case we don't have a match for
    // the first letter
    b_table[0] = -1;
    while(i < p_s){
        //Restart if p[i] != p[j]
        while( j >= 0 && p[i] != p[j]){
            j = b_table[j];
        }
        // Matching char
        i++;
        j++;
        // Off-set where we restart
        // search in case of mismatch
        b_table[i] = j;
    }

    // Search the string
    i = 0, j = 0;
    while(i < t_s){
        // Mismatch go to stored value in back_table
        while(j >= 0 && t[i] != p[j]){
            j = b_table[j];
        }
        // Current char matches
        i++;
        j++;

        // Full match
        if(j == p_s){
            res.push_back(i - j);
            // Prepare for next match
            j = b_table[j];
        }
    }
    return res;

} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string p;
    string t;

    while(getline(cin, p)){
        getline(cin, t);
        vector<ll> result = find(p, t);
        string to_print;
        if(result.empty()){
            cout << endl;
            continue;
        }
        to_print.append(to_string(result[0]));
        for(int i = 1; i < result.size(); i++){
            to_print.append(" " + to_string(result[i]));
        }
        cout << to_print << endl;
    }
}
