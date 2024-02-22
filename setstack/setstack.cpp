
#include <variant>
#include <vector>
#include <iostream>
#include <stack>

struct VariableDepthList : std::variant<std::vector<VariableDepthList>, int> {
private:
    using base = std::variant<std::vector<VariableDepthList>, int>;
public:
    using base::base;
    VariableDepthList(std::initializer_list<VariableDepthList> v) : base(v) {}
};

// This does not look right

/*
 * Got some help :) 
 * Algorithm: give each set a unique integer ID, represent a set of
 *            sets as a set of IDs.
*/
typedef struct setstack;

struct setstack
{
    int value;
    std::vector<setstack> list;
};

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

    }

    void INTERSECT() {

    }

    void ADD() {

    }

    void clear() {
        stack.clear();
    }

private:
    std::vector<setstack> stack;

};

int main() {
    // Creating an instance of SetStack
    Computer obj(42);


    return 0;
}