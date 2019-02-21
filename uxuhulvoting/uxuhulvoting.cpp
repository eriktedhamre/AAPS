#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

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

// DP-table
vector<vector<int> > dp;

// Satisfaction table
vector<vector<int> > p_p_table;

// number of priests
int p;

// number of round
int n;

// Returns the best vote for the current priest
// given current vote-state v
int uxuvote(int p_i, int v){


    if (dp[p_i][v] != 0){
        // We have been here before
        // the final vote is decided

        return dp[p_i][v];
    }
    else if(p_i == p){
        vector<int> p_v = n_v(v);
        int best_pref {1000};
        int best = 0;
        //printf("v is %d\n", v);
        for(int i = 0; i < 3; i++){
            int n_v = p_v[i];
            //printf("n_v is %d \n", n_v);
            int v_pref = p_p_table[p_i][n_v];
            // Preference for current priest
            if(v_pref < best_pref){
                best = n_v;
                best_pref = v_pref;
            }
        }
        
        dp[p_i][v] = best;
        //printf("v is %d, p_i is %d, best is %d \n", v, p_i, best);
        return best;
    }
    else{
        vector<int> p_v = n_v(v);
        // result if we vote first
        int first = uxuvote(p_i + 1, p_v[0]);
        // result if we vote second
        int second = uxuvote(p_i + 1, p_v[1]);
        // result if we vote third
        int third = uxuvote(p_i + 1, p_v[2]);
        int pref_first = p_p_table[p_i][first];
        int pref_second = p_p_table[p_i][second];
        int pref_third = p_p_table[p_i][third];
        auto il = {pref_first, pref_second, pref_third};
        int vote = min(il);

        if(vote == pref_first){
            dp[p_i][v] = first;
            return first;
        }
        else if (vote == pref_second)
        {
            dp[p_i][v] = second;
            return second;
        }
        else{
            dp[p_i][v] = third;
            return third;
        }
        
        
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    scanf("%d", &n);
    int v_state = 1;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &p);
        dp.resize(p + 1, vector<int>(9, 0));
        p_p_table.resize(p + 1, vector<int>(9, 0));
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

        // Start state for next vote
        v_state = uxuvote(1,  1);
        switch (v_state)
        {
            case 1:
                printf("NNN\n");
                break;
            case 2:
                printf("NNY\n");
                break;
            case 3:
                printf("NYN\n");
                break;
            case 4:
                printf("NYY\n");
                break;
            case 5:
                printf("YNN\n");
                break;
            case 6:
                printf("YNY\n");
                break;
            case 7:
                printf("YYN\n");
                break;
            case 8:
                printf("YYY\n");
                break;
            default:
                printf("HOL UP \n");
                break;
        }
        

        // Print result
        
        // Reset variables!
        dp.clear();
        p_p_table.clear();
    }
    

    return 0;
}
