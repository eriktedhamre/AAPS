#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

// DP-table
vector<vector<int> > dp{9, vector<int>{101, {0}}};

// Satisfaction table
vector<vector<int> > p_p_table{101,vector<int>{8,{0}}};

// number of priests
int p;

// number of round
int n;

// This could probably be done with bit
// operations witch should be faster...
vector<int> n_v(int v){
    vector<int> res;

    /*
    NNN - 1
    NNY - 2
    NYN - 3
    NYY - 4
    YNN - 5
    YNY - 6
    YYN - 7
    YYY - 8
    */

    switch (v)
    {
        // NNN
        case 1:
            // NNY NYN YNN
            res = {2, 3, 5};
            break;
        // NNY
        case 2:
            // NNN NYY YNY
            res = {1, 4, 6};
            break;
        // NYN
        case 3:
            // NNN YYN NYY
            res = {1, 7, 4};
            break;
        // NYY    
        case 4:
            // YYY NNY NYN
            res = {8, 2, 3};
            break;
        // YNN
        case 5:
            // NNN YYN YNY
            res = {1, 7, 6};
            break;
        // YNY
        case 6:
            // NNY YYY YNN
            res = {2, 8, 5};
            break;
        // YYN
        case 7:
            // NYN YNN YYY
            res = {3, 5, 8};
            break;
        // YYY
        case 8:
            // NYY YNY YYN
            res = {4, 6, 7};
            break;
        default:
            res = {-1};
            break;
    }
    return res;
}

int uxuvote(int p_i, int v){

    if(p_i == p){
        vector<int> p_v = n_v(v);
        int best {0};
        for(int i = 0; i < 3; i++){
            int n_v = p_v[i];
            int v_pref = p_p_table[p_i][n_v];
            // Preference for current priest
            if(v_pref > best){
                best = n_v;
            }
        }
        dp[p_i][v] = best;
        return best;
    }
    else if (dp[p_i][v] != 0)
    {
        // We have been here before
        // the final vote is decided
        return dp[p_i][v];
    }
    else
    {
        vector<int> p_v = n_v(v);
        int first = uxuvote(p_i + 1, p_v[0]);
        int second = uxuvote(p_i + 1, p_v[1]);
        int third = uxuvote(p_i + 1, p_v[2]);

        if(first > second){

            // first greatest
            if(first > third){
                dp[p_i][v] = p_v[0];
            }
            // third greatest
            else
            {
                dp[p_i][v] = p_v[2];
            }
        }
        // second > first
        else
        {
            // second greatest
            if(second > third){
                dp[p_i][v] = p_v[1];
            }
            // third greatest
            else
            {
                dp[p_i][v] = p_v[2];
            } 
        }
        
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &p);

        int p_i_p;
        // Off-set to make sense in p_p array
        for(int i = 1; i < p + 1; i++)
        {
            // Off-set again...
            for(int j = 1; j < 9; j++)
            {
                scanf("%d", &p_i_p);
                // Save preference
                // for priest i for vote j
                p_p_table[i][j] = p_i_p;
            }
        }
        
        // Read DP-table
        // Start from dp[1][0]
        // See what they voted
        // move to that square
        // move until you reach 
        // last priest print out
        // resulting vote

        // Print result

        // Reset variables!
    }
    

    return 0;
}
