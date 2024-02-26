
#include <variant>
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

// This does not look right

/*
 * Got some help :) 
 * Algorithm: give each set a unique integer ID, represent a set of
 *            sets as a set of IDs.
*/

using namespace std;

typedef struct setstack;


class Computer {
public:
    // Constructor
    Computer() : {

    }

    void PUSH() {
        stack.push_back()
    }

    void DUP() {

    }

    void UNION() {
        set_union() // std function

    }

    void INTERSECT() {
        set_intersection() // std function
    }

    void ADD() {

    }

    void clear() {
        setstack.clear();
    }

private:
    vector<int> setstack;     // Stack where int represents an ID in sets
    map<set<int>, int> setid; // Map from a set<int> to its ID in sets
    set<int> sets[1000000];   // Array of sets where its index is its ID, how do I reset this.
    // How do I assign indices into sets

};

int main() {
    // Creating an instance of SetStack


    return 0;
}