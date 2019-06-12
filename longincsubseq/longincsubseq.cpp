/*
* Author: Erik Tedhamre
*/
#include <bits/stdc++.h>
using namespace std;

template <typename Iterator>
vector<int> lis(Iterator begin, Iterator end){
    vector<int> seq;

    if((end - begin) == 0){
        seq.push_back(-1);
        return seq;
    }
    // Using pseudo-code from wikipedia as inspiration.
    // Sequence values denoted as X[0], X[1],...X[N]
    
    // P[k] - Stores the index of the predecesor of X[k] in the longest 
    // increasing subsequence ending at X[k]

    //Zero initialized
    int P [100000];

    // Zero initialized
    int M [100001];
    
    // Length of LIS
    int L = 0;
    Iterator it = begin;
    while(it != end){
        // Binary search for the largest positive j ≤ L
        // such that X[M[j]] < X[i]
        // If current > last, append to the end
        // if current <= last, replace element >= current
        // Starting at one since j ≥ 1
        int lo = 1;
        int hi = L;
        int mid;
        while(lo <= hi){
            // We want to have a strictly larger so always go right
            mid = ceil((((double)hi) + (double(lo)))/2);

            if(*(begin + M[mid]) < *it){
                // Current element is greater than the
                // LIS middle element
                // Try to find an element later in the
                // LIS that we can replace the latest
                // possible element
                lo = mid + 1;
            }
            else{
                // Current element is less than
                // or equal to the 
                // LIS middle element
                // Try to find a smaller element
                // So that we don't replace too early
                hi = mid - 1;
            }
        }
        // After searching, lo is 1 greater than the
        // length of the longest prefix of X[i]
        int newL = lo;
        // Parent pointer should to the index of it's predecessor
        P[it - begin] = M[newL - 1];
        M[newL] = (it - begin);
        //Longer than previous LIS
        if (newL > L) {
            L = newL;
        }
    it++;
    }
    // P parent pointer
    // M Stores index of smallest value for LIS
    // ending at index
    int k = M[L];
    seq.push_back(k);
    for(int i = 0; i < L - 1; i++){
        // Index of the smallest ending element
        seq.push_back(P[k]);
        k = P[k];        
    }
    // Could perhaps be done outside
    reverse(seq.begin(), seq.end());
    return seq;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int seq_len;
    while(scanf("%d", &seq_len) != EOF){
        if(seq_len == 0){
            printf(0);
            printf("\n");
            break;
        }
        vector<int> seq;
        int cur_elem;
        for(int i = 0; i < seq_len; i++)
        {
            scanf("%d", &cur_elem);
            seq.push_back(cur_elem);
        }
        vector<int> lseq = lis(seq.begin(), seq.end());
        printf("%lu \n", lseq.size());
        for(int i = 0; i < lseq.size() - 1; i++){
            printf("%d ",lseq[i]);
        }
        printf("%d \n", lseq[lseq.size() - 1]);
    }
}
