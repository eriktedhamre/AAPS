#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

using vi=vector<int>;

// access vector
vi a_vector;
// The vector at index i conatins
// the indices for that element in the 
// access vector
vector<deque<int> > index_vector;

// Map where the index of the next occurence
// is the key and the element to be accessed
// is the value
map<int, int> cache_map;

bool cmp(pair<int, int> const& a, pair<int, int> const& b){
    // Should only need this since the 
    // access indices should be unique
    return a.second > b.second;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);
    // Cache size
    int c;
    // Number of elements
    int n;
    // Number of accesses
    int a;
    // Total number of reads to the cache
    int number_of_reads = 0;

    scanf("%d %d %d", &c, &n, &a);

    for(int i = 0; i < n; i++)
    {
        index_vector.push_back(deque<int>());
    }
    
    int input;
    for(int i = 0; i < a; i++)
    {
        scanf("%d", &input);
        a_vector.push_back(input);
        // Could probably be done faster with initilazation
        index_vector[input].push_back(i);
    }

    //Read first input to avoid creatin
    for(int i = 0; i < a; i++)
    {   
        // If in map
        if (cache_map.count(i)) {
            //printf("%d \n", i);
            // Get the resource
            int resource = cache_map[i];
            // Pop current access from access-queue
            index_vector[resource].pop_front();

            deque<int> index_queue = index_vector[resource]; 
            
            // Erase old entry
            cache_map.erase(i);
            if (!index_queue.empty()){
                // Add new entry to the map
                cache_map.insert(pair<int ,int>(index_queue.front(), resource));
            }
            else
            {
                cache_map.insert(pair<int, int>(1000000, -1));
            }
        }
        // Not in map
        else
        {
            // We have to read the entry into our cache.
            number_of_reads++;
            // We have space for a new entry
            if (cache_map.size() < c ) {
                //printf("%d \n", i);
                // Get resource
                int resource = a_vector[i]; 
                // Remove current entry
                index_vector[resource].pop_front();
                // Find next entry
                if (!index_vector[resource].empty()){
                    // Add new entry to the map
                    cache_map.insert(pair<int ,int>(index_vector[resource].front(), resource));
                }
                else
                {
                    //Add dummy entry
                    cache_map.insert(pair<int, int>(1000000, -1));
                }
            }
            // We need to remove the entry with the largest key
            else
            {
                //printf("%d \n", i);
                pair<int, int> latest_access = *cache_map.rbegin();
                cache_map.erase(latest_access.first);
                // Get resource
                int resource = a_vector[i];
                // Remove current entry
                index_vector[resource].pop_front();
                
                if (!index_vector[resource].empty()){
                    // Add new entry to the map
                    cache_map.insert(pair<int ,int>(index_vector[resource].front(), resource));
                }
                else
                {
                    //Add dummy entry
                    cache_map.insert(pair<int, int>(1000000, -1));
                }
            }
        }
    }
    printf("%d\n", number_of_reads);
    return 0;
}
