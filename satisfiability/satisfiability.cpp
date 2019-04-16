#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

bool satisfiable = false;
vector<bool> state;
int N;
vector<vector<int> >clauses;

void satisfied(){
    for(int i = 0; i < clauses.size(); i++)
    {   
        //Clause is false
        bool fulfilled = false;
        for(int j = 0; j < clauses[i].size(); j++)
        {   
            int literal = clauses[i][j];
            //cout << "literal: " << literal << "\n";
            if (literal > 0 && state[literal - 1]) {
                // Current clause satisfied
                fulfilled = true;
                break;
            }
            else if (literal < 0 && !state[abs(literal) - 1]) {
                fulfilled = true;
                break;
            }
        }
        if(!fulfilled){
            satisfiable = false;
            return;
        }
    }
    satisfiable = true;
    return;
}

void enumerate(int k){
    if(satisfiable){
        return;
    }
    if (k == N) {
        satisfied();
        return;
    }
    enumerate(k + 1);
    state[k] = true;
    enumerate(k + 1);
    // Probably optional;
    state[k] = false; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> n >> m;
        N = n;
        state.assign(n, 0);
        clauses.clear();
        clauses.resize(m);
        satisfiable = false;

        for(int j = 0; j <= m; j++)
        {
            string clause;
            getline(std::cin, clause);
            //cout << "clause: " << clause << "\n";
            bool avoid = false;
            for(int k = 0; k < clause.size(); k++)
            {
                if(avoid){
                    avoid = false;
                    continue;
                }
                else if (clause[k] == '~') {
                    string s_lit;
                    s_lit.push_back(clause[k + 2]);
                    if(clause.size() > k + 2 && clause[k + 3] != ' '){
                        s_lit.push_back(clause[k + 3]);
                    }
                    int literal = stoi(s_lit);
                    //cout << "Negative: " << literal << "\n";
                    clauses[j-1].push_back(-literal);
                    avoid = true;
                    //cout << "Negative success";
                }
                else if(clause[k] == 'X'){
                    string s_lit;
                    s_lit.push_back(clause[k + 1]);
                    if(clause.size() > k + 1 && clause[k + 2] != ' '){
                        s_lit.push_back(clause[k + 2]);
                    }
                    int literal = stoi(s_lit);
                    //cout << "Positive: " << literal << "\n";
                    clauses[j-1].push_back(literal);
                }
            }
        }
        
        /*
        cout << "Finished with input \n";
        for(int j = 0; j < clauses.size(); j++)
        {
            for(int k = 0; k < clauses[j].size(); k++)
            {
                cout << clauses[j][k] << " ";
            }
            cout << "\n";
        }
        */
        
        enumerate(0);
        if(satisfiable){
            cout << "satisfiable" << "\n";
        }
        else
        {
            cout << "unsatisfiable" << "\n";
        }
        
        
    }
    

    return 0;
}
