/*
* Author: Erik Tedhamre
*/
#include <bits/stdc++.h>
using namespace std;

// Fenwick tree class
class Ftree{
    private:
        vector<long long> tree;
    public:

        // Create fenwick tree
        // initialized to zero
        Ftree(long long size){
            tree.assign(size + 1, 0);
        }
        // Replace with new
        // cleared tree
        void clear(long long size){
            tree.assign(size + 1, 0);
        }
        
        // Add value a to index i for FTree
        void add(int i, int a){
            while(i < tree.size()){
                // Add to sum for node
                tree[i] += a;
                // Go up and right in tree
                i += i & -i;
            }
        }

        // Range sum query for FTree
        // From start to end 
        long long sum(int end){
            long long res {0};
            while( end > 0){
                res += tree[end];
                // Go up and left in tree
                end -= end & -end;
            }
            return res;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    long long Q;

    scanf("%lld %lld", &N, &Q);
    
    Ftree fenwick(N);
    char c;
    long long index, a;
    for(int i = 0; i < Q; i++){
        scanf(" %c", &c);
        if(c == '+'){
            scanf("%lld %lld", &index, &a);
            // We use 1-indexed array
            fenwick.add(index + 1, a);
        }
        else if(c == '?'){
            scanf("%lld", &index);
            // Up to but not including index
            printf("%lld\n", fenwick.sum(index));
        }
    }
    return 0;
}
