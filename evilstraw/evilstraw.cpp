#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

vector<char> alphabet{'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    scanf("%d", &n);

    list<char> s;
    vector<int> freq;
    for(int i = 0; i < n; i++){
        freq.assign(26, 0);
        s.clear();
        char c;
        while(scanf("%c", &c) && isspace(c)){}

        do{
            int index = (int)c % 32 - 1;
            freq[index] += 1;
            s.push_back(c);
        }
        while(scanf("%c", &c) > 0 && !isspace(c));
        char mid_elem = '-';
        int odd = 0;
        for(int j = 0; j < freq.size(); j++){
            if(freq[j] % 2 == 1){
                odd++;
                mid_elem = alphabet[j];
                if(odd > 1){
                    printf("Impossible\n");
                    break;
                }
            }
        }
        if(odd > 1){
            continue;
        }

        int total_swaps = 0;
        while(s.size() > 1){
            if(s.front() == mid_elem){
                // Swap to fix right element
                list<char>::iterator it_r_s = find(s.begin(), s.end(), s.back());
                total_swaps += distance(s.begin(), it_r_s);
                s.erase(it_r_s);
                s.pop_back();
            }
            else if(s.back() == mid_elem){
                // Swap to fix left element
                list<char>::reverse_iterator it_l_s = find(s.rbegin(), s.rend(), s.front());
                total_swaps += distance(s.rbegin(), it_l_s);
                list<char>::iterator forward_it_l_s = it_l_s.base();
                forward_it_l_s--;
                s.erase(forward_it_l_s);
                s.pop_front();
            }
            else if(s.back() == s.front()){
                // Delete both and continue
                char elem = s.front();
                freq[int(elem) % 32 - 1] -= 2;
                s.pop_front();
                s.pop_back();
            }
            else{
                // Swap the element that requires fewest swaps
                char l = s.front();
                char r = s.back();
                int occur_l = 1;
                list<char>::iterator it_r_s;
                list<char>::iterator it_l_s;
                int swap_r_to_l;
                int swap_l_to_r;
                for(list<char>::iterator it = s.begin(); it != s.end(); it++){
                    if(it == s.begin()){
                        continue;
                    }
                    // Instance of element we want to swap to the left;
                    if(*it == r){
                        swap_r_to_l = distance(s.begin(), it);
                        it_r_s = it;
                        break;
                    }
                    // Instance of element we want to swap to the right
                    else if(*it == l){
                        occur_l++;
                        it_l_s = it;
                        swap_l_to_r = distance(it, s.end()) - 1;
                    }
                }
                // Might be a better instance of element we to swap to the right
                if(freq[(int)l % 32 - 1] - occur_l > 0){
                    for(auto it = s.rbegin(); it != s.rend(); it++){
                        if(*it == l){
                            swap_l_to_r = distance(s.rbegin(), it);
                            it_l_s = it.base();
                            it_l_s--;
                            break;
                        }
                    }
                }
                //Swap the right most instance of element l to the right
                if(swap_l_to_r <= swap_r_to_l){
                    total_swaps += swap_l_to_r;
                    s.erase(it_l_s);
                    s.pop_front();
                    freq[int(l) % 32 - 1] -= 2;  
                }
                // Swap the left most instance of element r to the left
                else{
                    total_swaps += swap_r_to_l;
                    s.erase(it_r_s);
                    s.pop_back();
                    freq[int(r) % 32 - 1] -= 2;
                }
            }
        }
        printf("%d\n", total_swaps);
    }
    return 0;
}
