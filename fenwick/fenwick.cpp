#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

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
        // Clear tree
        // and replace with new
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
                // Add sum for current node
                // to result
                res += tree[end];
                // Go up and left in tree
                end -= end & -end;
            }
            return res;
        }
};
 NEGATIVA TAL, DU ÄR SKÖN
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    long long N;
    long long Q;

    scanf("%lld %lld", &N, &Q);

    Ftree fenwick(N);
    char c;
    long long i, a;
    while(scanf(" %c", &c) != EOF){
        if(c == '+'){
            scanf("%lld %lld", &i, &a);
            fenwick.add(i, a);
        }
        else if(c == '?'){
            scanf("%lld", &i);
            printf("%lld\n", fenwick.sum(i));
        }
    }

    return 0;
}
