#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <algorithm>

/* 
 * Algorithm: give each set a unique integer ID, represent a set of
 *            sets as a set of IDs.
*/

using namespace std;

set<int> sets[100000];  // Array of sets where its index is its ID

class Computer {
public:
  Computer() {}

  void PUSH() {
    set_stack.push_back(0);
  }

  void DUP() {
    set_stack.push_back(set_stack.back());
  }

  void UNION() {
    int first = pop();
    int second = pop();
    set<int> u;
    set_union(sets[first].begin(), sets[first].end(),
              sets[second].begin(), sets[second].end(),
              std::inserter(u, u.begin()));
    set_stack.push_back(set_id(u));

  }

  void INTERSECT() {
    int first = pop();
    int second = pop();
    set<int> i;
    set_intersection(sets[first].begin(), sets[first].end(),
                     sets[second].begin(), sets[second].end(),
                     std::inserter(i, i.begin()));
    set_stack.push_back(set_id(i));
  }

  void ADD() {
    int first = pop();
    int second = pop();
    set<int> res = sets[second];
    res.insert(first);
    set_stack.push_back(set_id(res));
  }

  int set_id(const set<int> &s) {
    // See if this set is new
    auto it = set_map.find(s);
    int set_id;

    if (it != set_map.end()) {
      // Set exists
      set_id =  it->second;
    } else {
      // New set, add to sets and set_map
      sets[set_map.size()] = s;
      set_map[s] = set_map.size();
      // set_map.size() updated
      set_id = set_map.size() - 1;
    }
    return set_id;
  }

  int pop() {
    int top = set_stack.back();
    set_stack.pop_back();
    return top;
  }

  void clear() {
    set_stack.clear();
    set_map.clear();
    sets[0] = set<int>();
    set_map[sets[0]] = 0;
  }

  int print() {
    return sets[set_stack.back()].size();
  }

  void debug(){
    for (auto it = set_stack.begin(); it != set_stack.end(); ++it) {
      cout << "****Set: " << *it << " ****\n";
      for (auto set_it = sets[*it].begin(); set_it != sets[*it].end(); ++set_it) {
        cout << *set_it << " ";
      }
    }
  }

  void set_map_print(){
    for (auto it = set_map.rbegin(); it != set_map.rend(); it++)
    {
      cout << "set_map_size: " << it->first.size() << " value: " << it->second << "\n";
    }
    
  }

private:
  vector<int> set_stack;      // Stack where int represents an ID in sets
  map<set<int>, int> set_map; // Map from a set<int> to its ID in sets
};

int main() {
  int T;
  std::cin >> T;

  int N;
  string command;
  Computer set_computer = Computer();
  for (size_t i = 0; i < T; i++) {
    set_computer.clear();

    cin >> N;
    for (size_t j = 0; j < N; j++)
    {
      cin >> command;
      if (command == "PUSH") {
        set_computer.PUSH();
        
      } else if (command == "DUP") {
        set_computer.DUP();
        
      } else if (command == "UNION") {
        set_computer.UNION();
        
      } else if (command == "INTERSECT") {
        set_computer.INTERSECT();
        
      } else if (command == "ADD") {
        set_computer.ADD();
      }
      
      std::cout << set_computer.print() << "\n";
    }

    cout << "***\n";
  }
}