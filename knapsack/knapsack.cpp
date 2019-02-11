#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

// typename for pair iterators
template <typename PairIterator>

// Returns a vector with the indices of the elements
// to be included in the knapsack
vector<int> knapsack(int cap, PairIterator begin, PairIterator end){
    //Result vector
    vector<int> res;

    //Number of items
    int n = (end - begin);
    // We can't work with this
    if(n <= 0 || cap <= 0){
        printf("hold up 1\n");
        res.push_back(-1);
        return res;
    }
    // We to have a zero row & col hence +1 for both
    int dp[n + 1][cap + 1];
    
    //Bottom up DP approach
    // We want a 0-row and 0-col, increase them by one
    for(int i = 0; i < n + 1; i++){
        for(int c = 0; c < cap + 1; c++){
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
                int inc = (begin + i - 1)->first + dp[i - 1][c - (begin + i - 1)->second];
                // 2. Exclude the item
                int exc = dp[i - 1][c];
                // + maximized value for the remaining weight
                dp[i][c] = max(inc, exc);
            }
            // We don't have space for the item
            else{
                // Maximized value without the item
                dp[i][c] = dp[i - 1][c];
            }
        }
    }
    int value = dp[n][cap];
    //Reading the DP-table
    for(int i = n; i > 0 && value > 0; i--){

        // The current element is not included
        // Since we have the same value without it
        // see previous loop
        if(dp[i - 1][cap] == value){
            continue;
        }
        else{
            // Add element to result
            res.push_back(i - 1);
            // Reduce value and weigth
            value -= (begin + i - 1)->first;
            cap -= (begin + i - 1)->second;
        }
    }
    if(res.empty()){
        res.push_back(-1);
    }
    return res;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Capacity-read
    double C;
    // Capacity floored
    int n;
    // Value & Weight vector
    vector<pair<int, int> > items;
    int value;
    int weigth;

    //Reading input
    while(scanf("%lf %d", &C, &n) != EOF){
        
        for(int i = 0; i < n; i++){
            scanf("%d %d", &value, &weigth);
            items.push_back(pair<int, int>(value, weigth));
        }
        //Solving current case
        vector<int> res = knapsack(floor(C), items.begin(), items.end());
        if(res[0] == -1){
            printf("0\n");
        }
        else{
            int elements = res.size();
            printf("%d\n", elements);
            for(int i = 0; i < elements - 1; i++){
                printf("%d ", res[i]);
            }
            printf("%d\n", res[elements - 1]);
        }
        //Reset vectors
        items.clear();
        res.clear();
    }

    return 0;
}
