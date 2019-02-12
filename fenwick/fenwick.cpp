#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

class Ftree(){
    private :
        vector<long long> tree;
    public :

        // Create fenwick tree
        // initialized to zero
        FTree(long long size){
            tree.assign(size + 1, 0);
        }
        // Clear tree
        // and replace with new
        // cleared tree
        void clearFTree(long long size){
            tree.assign(size + 1, 0);
        }
        
        // Add value a to index i for FTree
        void aFTree(int i, int a){
            while(i < tree.size()){
                // Add to sum for node
                tree[i] += a;
                // Go up and right in tree
                i += i & -i;
            }
        }

        // Range sum query for FTree
        // From start to end 
        long long sumFTree(int end){
            long long res {0};
            while( end > 0){
                // Add sum for current node
                // to result
                res += tree[end];
                // Go up and left in tree
                end -= end & -end;
            }
        }  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    int []

    return 0;
}
