#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;
bool cmp(const int &a, const int &b){
    return a < b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    int cuts;
    scanf("%d", &cuts);

    // Keep check if a number is left in tree
    map<int, int> freq_table;
    // Upper limit for the initial leaves
    int upper_limit;
    // V-list
    vector<int> input;
    for(int i = 0; i < cuts; i++)
    {
        int cur_v;
        scanf("%d", &cur_v);
        freq_table[cur_v]++;
        input[i] =  cur_v;
    }
    //Last element
    upper_limit = *(input.end - 1);
    
    priority_queue< int, vector<int>, cmp > available_numbers;

    return 0;
}
