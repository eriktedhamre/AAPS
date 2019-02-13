#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

class disjointSet{
    private:
        vector<long long> sets;
    public:
    disjointSet(long long size){
        sets.assign(size, -1);
    }

    // Weighted union for two roots
    union(long long a,  long long b){
        long long parent_a = sets[a];
        long long parent_b = sets[b];

        // Weighted union if both are roots
        if(parent_a < 0 && parent_b < 0){
            int children;
            // Parent a has fewer nodes
            if (parent_a > parent_b){
                // Total number of nodes;
                children = parent_a + parent_b;
                sets[a] = b;
                sets[b] = children;
            }
            // Parent b has fewer or equal nodes
            else if(parent_b => parent_a){
                children = parent_a + parent_b;
                sets[b] = a;
                sets[a] = children;
            }
        }
        // Both are not roots
        // a could be a root
        else if (parent_a < parent_b){
            sets[b] = a;
        }
        // Both are not root
        // b could be root
        else{
            sets[a] = b
        }
    }

    // Collapsing find for
    // element with index a
    // returns root
    long find(long i){

        long root = i;
        // loop until root is the root
        // for item i
        while(sets[root] > 0){
            root = sets[root];
        }
        // collapse their depth
        // Go from the bottom up
        // and update roots until
        // you hit the root
        while(root != i){
            // Next node to handle
            long parent = sets[i];
            // Set the nodes root to
            // the collapsed root
            sets[i] = root;
            // Update node switch root for
            i = parent;
        }
        return root;
    }

    bool same(long long a, long long b){
        return (find(a) == find(b));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    long long Q;

    scanf("%lld %lld", &N, &Q);
    
    disjointSet disjointSet(N);

    char c;
    long long a, b;
    for(int i = 0; i < Q; i++){
        scanf(" %c", &c);
        //printf("c == %c\n", c);
        if(c == '?'){
            scanf("%lld %lld", &a, &b);
            
        }
        else if(c == '='){
            scanf("%lld %lld", &a, &b);
            
        }
    }

    return 0;
}
