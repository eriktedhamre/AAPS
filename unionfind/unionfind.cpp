/*
* Author: Erik Tedhamre
*/
#include <bits/stdc++.h>
using namespace std;

class disjointSet{
    private:
        vector<long long> sets;

    public:
        disjointSet(long long size){
            sets.assign(size, -1);
        }

        // Weighted union for two roots
        void unify(long long a,  long long b){
            long long root_a = find(a);
            long long root_b = find(b);
            if(root_a == root_b){
                return;
            }
             // Weight of a
            long long rank_a = sets[root_a];
             // Weight of b
            long long rank_b = sets[root_b];
            // Weighted union 0f both roots
            long long children;
            // Parent a has fewer nodes
            if (rank_a > rank_b){
                // Total number of nodes;
                children = rank_a + rank_b;
                sets[root_a] = root_b;
                sets[root_b] = children;
            }
            // Parent b has fewer or equal nodes
            else if(rank_b >= rank_a){
                children = rank_a + rank_b;
                sets[root_b] = root_a;
                sets[root_a] = children;
            }
        }

        // Collapsing find for
        // element with index a
        // returns root
        long long find(long long i){

            long long root = i;
            // loop until root is the root
            // for item i
            vector<long long> nodes;
            while(sets[root] >= 0){
                root = sets[root];
            }
            // collapse their depth
            // Go from the bottom up
            // and update roots until
            // you hit the root
            long long parent;
            while(root != i){
                // Next node to handle
                parent = sets[i];
                // Set the nodes root to
                // the collapsed root
                sets[i] = root;
                // Update node switch root for
                i = parent;
            }
            return parent;
        }

        bool same(long long a, long long b){
            return (find(a) == find(b));
        }

       // find depth of the root for a
        long long depth(long long a){
            return abs(sets[find(a)]);
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    long long Q;

    scanf("%lld %lld", &N, &Q);
    
    disjointSet set(N);

    char c;
    long long a, b;
    for(int i = 0; i < Q; i++){
        scanf(" %c", &c);
        if(c == '?'){
            scanf("%lld %lld", &a, &b);
            if(set.same(a, b)){
                printf("yes\n");
            }
            else{
                printf("no\n");
            }
        }
        else if(c == '='){
            scanf("%lld %lld", &a, &b);
            set.unify(a, b);
        }
    }
}
