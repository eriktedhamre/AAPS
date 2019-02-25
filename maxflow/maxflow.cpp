#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

// Struct for representing an edge
// for Dinc's algorithm
struct Edge{

    int dest; // destination node

    int cap; // flow capacity for edge

    int flow; // Current flow

    int source; // Index for edge
                // connecting to this edge 
    
};

// Graph class used for Dinc's algorithm
class Graph
{
private:
    
public:
    Graph(/* args */);
    ~Graph();
};

Graph::Graph(/* args */)
{
}

Graph::~Graph()
{
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    return 0;
}
