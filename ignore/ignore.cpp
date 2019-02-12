#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

vector<int> translation;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Sometimes I reaally hate Mac OSX
    translation.push_back(0);
    translation.push_back(1);
    translation.push_back(2);
    translation.push_back(5);
    translation.push_back(9);
    translation.push_back(8);
    translation.push_back(6);
    
    int input;

    while(scanf("%d", &input) != EOF){
        string b7_res;
        int rest = input; 
        while((rest/7) > 0){
            b7_res.append(to_string(rest % 7));
            rest = (rest/7);
        }
        //printf("%d \n", rest);
        b7_res.append(to_string(rest));
        //printf("%s \n", b7.c_str());
        if(b7_res.size() > 1){
            reverse(b7_res.begin(), b7_res.end());
        }
        while(!b7_res.empty()){
            printf("%d", translation[*(b7_res.end() - 1) - '0']);
            b7_res.pop_back();
        }
        printf("\n");
    }
    //printf("We are done \n");
}
