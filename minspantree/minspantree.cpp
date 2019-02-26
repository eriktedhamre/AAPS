#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ll=long long;

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
vector<pair<ll, pair<ll, ll> > > mst(ll vertices, vector< pair<ll, pair<ll, ll> > > EdgeList){
    vector<pair<ll, pair<ll, ll> > > result_tree;

    if (vertices == 0 || EdgeList.size() == 0) {
        return result_tree;
    }
    

    disjointSet DS(vertices);

    int edges = EdgeList.size();
    for(int i = 0; i < edges; i++)
    {
        pair<ll, pair<ll, ll> > edge = EdgeList[i];
        if (!DS.same(edge.second.first, edge.second.second)) {

            DS.unify(edge.second.first, edge.second.second);
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

    // vector containing all edges formatted: (weight, (u, v))
    vector< pair<ll, pair<ll ,ll> > > Edges;

    int n, m, u, v, w;
    while(scanf("%d %d", &n, &m)){

        // Break
        if (n == 0 && m == 0) {
            break;
        }

        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);

            Edges.push_back(make_pair((ll)w, make_pair((ll)u, (ll)v)));
        }
        // Sort input
        sort(Edges.begin(), Edges.end());
        
        vector< pair<ll, pair<ll ,ll> > > mst_edge_list = mst((ll)n, Edges);
        
        if (mst_edge_list.empty()) {
            printf("Impossible\n");
        }
        else
        {
            ll mst_cost = 0;
            for(int i = 0; i < mst_edge_list.size(); i++)
            {
                mst_cost += mst_edge_list[i].first;
            }
            printf("%lld\n", mst_cost);

            sort(mst_edge_list.begin(), mst_edge_list.end(), [](auto &left, auto &right){
                if (left.second.first == right.second.first) {
                    return left.second.second < right.second.second;
                }
                return left.second.first < right.second.first;
            });

            for(int i = 0; i < mst_edge_list.size(); i++)
            {
                printf("%lld %lld\n", mst_edge_list[i].second.first, mst_edge_list[i].second.second);
            }
        }
        Edges.clear();
    }
    return 0;
}
