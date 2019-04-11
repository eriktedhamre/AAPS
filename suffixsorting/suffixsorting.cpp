#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

class suffix_array{
    private:
        vector<int> rank, suffix, tmp_r, tmp_s, count;
        string T;
        int T_size;
        const int ALPHABET_LL = 300;

        void counting_sort(int k){
            //This could probably be sped up when you have a small alphabet
            int i, sum = 0;
            int max_r = max(ALPHABET_LL, (int)T.size());
            count.assign(T_size, 0);
            for(i = 0; i < max_r; i++)
            {
                if(i + k < T_size){
                    // Increment frequency for element at [r + k]
                    count[rank[i + k]]++;
                }
                else
                {
                    //Initial offset
                    count[0]++;
                }
            }
            // Indices
            for(i = 0; i < max_r; i++)
            {
                int r = count[i];
                count[i] = sum;
                //Running sum for indices
                sum += r;
            }
            // Shuffle array
            for(i = 0; i < T_size; i++) 
            {
                if (count[suffix[i] + k]) {
                    /* code */
                }
                
            }
            
            
            
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    return 0;
}
