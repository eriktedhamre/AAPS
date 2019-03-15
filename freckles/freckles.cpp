#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ld=long double;

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

// Takes a graph represented as a sorted EdgeList (weight, (u, v))
// and an integer denoting the number of nodes in the graph
// Returns an EdgeList containing the mst
vector<pair<ld, pair<int, int> > > mst(int vertices, vector< pair<ld, pair<int, int> > > EdgeList){
    
    vector<pair<ld, pair<int, int> > > result_tree;

    if (vertices == 0 || EdgeList.size() == 0) {
        return result_tree;
    }

    // Use the disjoin set datastructure
    // to keep track of which
    // nodes are part of the mst
    disjointSet DS(vertices);

    int edges = EdgeList.size();
    for(int i = 0; i < edges; i++)
    {
        // Current minimum edge
        pair<ld, pair<int, int> > edge = EdgeList[i];

        // If the current minimum edge reaches a node
        // that is not in the mst add it to the mst
        if (!DS.same(edge.second.first, edge.second.second)) {

            DS.unify(edge.second.first, edge.second.second);
            // Add the edge to the results
            result_tree.push_back(edge);

            // They are all part of the same set
            // mst complete
            if(DS.depth(edge.second.first) == vertices){
                break;
            }
        }
    }

    // We don't have a complete tree
    if(!result_tree.empty() && !(DS.depth(result_tree.front().second.first) == vertices)){
        result_tree.clear();
    }
    return result_tree;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int finished = 0;

    

    vector< pair<ld, pair<int, int> > > Edges;
    vector<vector<bool> > exists;
    exists.resize(1001, vector<bool>(1001, false));
    ld x;
    ld y;
    int freckles;
    vector< pair<ld, ld> > coord;
    while(scanf("%d", &n) != EOF){

        while(finished != n){

        scanf("%d", &freckles);
        //printf("freckles:%d\n", freckles);
        coord.resize(freckles);
        if(finished != 0){
            printf("\n");
        }
        if(freckles == 1){
            scanf("%Lf %Lf", &x, &y);
            printf("0.00\n");
            finished++;
            continue;
        }

        for(int i = 0; i < freckles; i++)
        {
            scanf("%Lf %Lf", &x, &y);
            coord[i] = make_pair(x, y);
        }
        
        exists.assign(freckles, vector<bool>(freckles, false));
        for(int i = 0; i < freckles; i++)
        {
            for(int j = 0; j < freckles; j++)
            {
                if (i == j || exists[i][j]) {
                    //printf("i:%d j:%d\n",i, j);
                    continue;
                }
                else{
                    ld dist = sqrt(pow(coord[i].first - coord[j].first, 2) + pow(coord[i].second - coord[j].second, 2));
                    Edges.push_back(make_pair(dist, make_pair(i, j)));
                    exists[i][j] = true;
                    exists[j][i] = true;
                }
            }
            
        }
        //printf("%lu\n", Edges.size());
        sort(Edges.begin(), Edges.end());
        //printf("%lu\n", Edges.size());
        vector< pair<ld, pair<int, int> > > result = mst(freckles, Edges);

        ld sum = 0;

        for(int i = 0; i < result.size(); i++)
        {
            sum += result[i].first;
        }

        printf("%.2Lf\n", sum);
        Edges.clear();
        coord.clear();
        finished++;
    }
}
return 0;
}
