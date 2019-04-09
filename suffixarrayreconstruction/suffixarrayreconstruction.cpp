#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string output;
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++){
        int string_length, suffixes;
        cin >> string_length >> suffixes;
        s.assign(string_length, '-');

        int suf_indx;
        string suffix;
        bool fail = false;
        for(int j = 0; j < suffixes; j++){
            cin >> suf_indx >> suffix;
            //cout <<"suf_index "<< suf_indx << " suffix " <<suffix << "\n";
            suf_indx--;
            bool star = false;
            if(!fail){
                for(int k = 0; k < suffix.size(); k++){
                    if (suffix[k] == '*') { star = true; break;}
                    else if(s[k + suf_indx] == '-'){
                        s[k + suf_indx] = suffix[k];
                    }
                    else if (s[k + suf_indx] != suffix[k]){
                        fail = true;
                        break;
                    }    
                }
                if(star){
                    for(int k = 1; k < suffix.size(); k++)
                    {
                        if(suffix[suffix.size() - k] == '*'){
                            break;
                        }
                        else if(s[s.size() - k] == '-'){
                            s[s.size() - k] = suffix[suffix.size() - k];
                        }
                        else if(s[s.size() - k] != suffix[suffix.size() - k]){
                            fail = true;
                            break;
                        }
                    }  
                }
            }
        }
        if(fail || s.find("-") != string::npos){
            output += "IMPOSSIBLE\n";
        }
        else{
            output += s + "\n";
        }
        
    }
    cout << output;

    return 0;
}
