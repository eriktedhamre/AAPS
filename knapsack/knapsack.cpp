#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

// typename for pair iterators
template <typename PairIterator>

// Returns a vector with the indices of the elements
// to be included in the knapsack
vector<int> knapsack(int cap, pairItertor begin, pairIterator end){
    //Result vector
    vector<int> res;

    //Number of items
    int n = (end - begin);
    if(n == 0){
        return
    }
    // We to have a zero row & col hence +1 for both
    int dp[n + 1][cap + 1]
    
    //Bottom up DP approach
    for(int i; i < n; i++){
        for(int c < cap; c++){
            // We are in 0-row or 0-col
            if(i == 0 || c == 0){
                // Default value for ints should be zero
                // could possibly skip this
                dp[i][c] = 0;
            }
            // We have space for the current item
            else if((begin + i - 1)->second <= c){
                // Take the best option between
                // 1. Include the item
                int inc = (begin + i - 1)->first + dp[i - 1][c - (begin + i - 1)->second]);
                // 2. Exclude the item
                int exc = dp[i - 1][w];
                // + maximized value for the remaining weight
                dp[i][c] = max(inc, exc);
                
            }

        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    return 0;
}
