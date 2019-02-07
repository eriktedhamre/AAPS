#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

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
    vector<int> v;
    // Input loop
    // Adds element to v-vector and freq-map
    for(int i = 0; i < cuts; i++)
    {
        int cur_v;
        scanf("%d", &cur_v);
        int v_freq = freq_table[cur_v];
        freq_table[cur_v] = v_freq + 1;
        v.push_back(cur_v);
    }
    //Last element
    upper_limit = *(v.end() - 1);

    // Too few numbers available
    if (upper_limit <= cuts){
        upper_limit = 0;
        cuts = 0;
    }
    // Queue used to determine next smallest leaf
    priority_queue< int, vector<int>, greater<int> > available_numbers;

    // Add initially available numbers
    for(int i = 1; i < upper_limit; i++){
        // Check if current element
        // can't be cut off initially
        if(!freq_table.count(i)){
            available_numbers.push(i);
        }
    }
    vector<int> u;
    vector<int>::iterator it = v.begin();

    while(u.size() < cuts && it != v.end()){

        // Pop smallest value and add it to u
        int smallest = available_numbers.top();
        available_numbers.pop();
        u.push_back(smallest);

        // Reduce the frequency of the connecting 
        // node in the map by one
        // until it has zero frequency and then add it to
        // available numbers
        int v_value = *it;
        int v_freq = freq_table[v_value];
        v_freq--;
        if(v_freq == 0){
            available_numbers.push(v_value);
        }
        else
        {
            freq_table[v_value] = v_freq;
        }

        // Move v-iterator since we have dealt with
        // the current cut
        it++;

    }

    if(u.size() < cuts || upper_limit == 0){
        printf("Error\n");
    }

    for(int i = 0; i < u.size(); i++)
    {
        printf("%d\n", u[i]);
    }
    
    
    return 0;
}
