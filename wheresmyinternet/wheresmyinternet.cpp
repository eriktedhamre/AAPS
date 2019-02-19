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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int M;

    scanf("%d %d", &N, &M);

    // Off by one since we start at 0
    disjointSet houses(N);

    int a, b;
    for(int i = 0; i < M; i++){
        // Cable between a and b
        scanf("%d %d", &a, &b);
        // Both are reduced by one
        // due to off-set
        houses.unify(a - 1, b - 1);
    }

    vector<int> roots;
    for(int i = 0; i < N; i++){
        roots.push_back(houses.find(i));
    }

    int internet = roots[0];
    int connected = 0;
    for(int i = 0; i < N; i++){
        if(roots[i] != internet){
            // Off-set by one, house 0 is actually house 1
            printf("%d\n", i + 1);
        }
        else{
            connected++;
        }
    }
    if(connected == N){
        printf("Connected\n");
    }
}
