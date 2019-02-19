#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    int n;
    deque<int> p;

    scanf("%d", &n);

    int pi;
    for(int i = 0; i < n; i++){
        scanf("%d", &pi);
        p.push_back(pi);
    }

    sort(p.begin(), p.end(), greater<int>());
    long long discount = 0;

    while(!p.empty()){
        if(p.size() > 2){
            p.pop_front();
            p.pop_front();
            discount += p.front();
            p.pop_front();
        }else{
            break;
        }
    }
    printf("%lld\n", discount);

    return 0;
}
