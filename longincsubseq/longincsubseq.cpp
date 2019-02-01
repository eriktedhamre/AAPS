#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

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
    int P [(end - begin)];
    // Stores the index k of the smallest value X[k]
    // such that there is an increasing subsequence
    // of length j + 1 ending at X[k - 1]
    // on the range k ≤ i.
    // Note that j ≤ i, because j ≥ 1 
    // represents the length of the increasing
    // subsequence, and k ≥ 0 represents
    // the index of its termination.
    int M [(end - begin) + 1];

    // Length of LIS
    int L = 0;
    Iterator it = begin;
    while(it != end){

        // Binary search for the largest positive j ≤ L
        // such that X[M[j]] < X[i]
        // Find the largest element that is less than
        // the current
        // If current > last, append to the end
        // if current <= last, replace element >= current
        // Starting at one since j ≥ 1
        int lo = 1;
        int hi = L;
        int mid;
        while(lo <= hi){
            mid = floor((((double)hi) + (double(lo)))/2)


            if(*(begin + M(mid)))
        }


    }
    
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    return 0;
}