#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    scanf("%d", &T);
    int NG, NM;

    vector<int> NGArmy;
    vector<int> NMArmy;

    for(int i = 0; i < T; i++){
        scanf(" %d %d", &NG, &NM);
        int unit;
        for(int i = 0; i < NG; i++){
            scanf("%d ", &unit);
            NGArmy.push_back(unit);
        }
        for(int i = 0; i < NM; i++){
            scanf("%d ", &unit);
            NMArmy.push_back(unit);
        }
        sort(NGArmy.begin(), NGArmy.end(), greater<int>());
        sort(NMArmy.begin(), NMArmy.end(), greater<int>());
        while((!NGArmy.empty()) && (!NMArmy.empty())){
            //Godzilla has weakest unit
            if(NGArmy.back() < NMArmy.back()){
                NGArmy.pop_back();
            }
            //MechaGodzilla has weakest unit
            else if(NMArmy.back() < NGArmy.back()){
                NMArmy.pop_back();
            }
            // Both have the weakest unit Mecha loses
            else if (NMArmy.back() == NGArmy.back()){
                NMArmy.pop_back();
            }
        }
        if(NMArmy.empty() && !NGArmy.empty()){
            printf("Godzilla\n");
        }
        else if(NGArmy.empty() && !NMArmy.empty()){
            printf("MechaGodzilla\n");
        }
        else{
            printf("uncertain\n");
        }
        NGArmy.clear();
        NMArmy.clear();
    }
    // Insert code here

    return 0;
}
