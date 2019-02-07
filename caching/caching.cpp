#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

using vi=vector<int>;

// access vector
vi a_vector(100001);
// The vector at index i conatins
// the indices for that element in the 
// access vector
vector<deque<int> > index_vector(100001);

// Map where the key is the element and
// the value is the next time it's accessed
// Keeping a pair<int, int> of the key
// with the latest access index
map<int, int> cache_map;

bool cmp(pair<int, int> const& a, pair<int, int> const& b){
    // Should only need this since the 
    // access indices should be unique
    return a.second > b.second;
}
// Priority queue to always remove the element 
// to be accessed at the latest time
priority_queue< pair<int, int>, deque<pair<int, int> >,
    function<bool (pair<int, int>, pair<int, int>)> > erase_queue(cmp);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int c;
    int n;
    int a;
    int number_of_reads;

    scanf("%d %d %d", &c, &n, &a);

    int input;
    for(int i = 0; i < a; i++)
    {
        scanf("%d", &input);
        a_vector.push_back(input);
        index_vector[input].push_back(i);
    }
    
    for(int i = 0; i < a_vector.size(); i++)
    {
        // Is it in the map
        if (cache_map.count(a_vector[i])) {
            //Update value for map
            deque<int> index_value = index_vector[a_vector[i]]; 
            cache_map[a_vector[i]] = index_value.front();

            // Since this is the current element it
            // should be the element with the lowest 
            // priority in the queue
            // CHANGE DATA STRUCTURE TO ENABLE THIS IF NECCESSARY
            // Maybe a set which sorts based on index and not element

            // Add to queue, it's possible we will store things
            // multiple times now which isn't nice
            // Possible cause for memory overflow
            erase_queue.push(pair<int, int>(a_vector[i], index_value.front()));

            // Destroy it
            index_vector[a_vector[i]].pop_front();  
        }
        // It is not in the map
        else{
            deque<int> index_value = index_vector[a_vector[i]];
            // Space to read it into the map
            if (cache_map.size() < c){
                cache_map.insert(a_vector[i], )
            }
            erase_queue.pop_back()
            // Do we need to replace something
            // in the map
        }
    }
    

    
    return 0;
}
