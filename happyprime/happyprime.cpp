#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1){
        return false; 
    }
  
    // Check from 2 to n-1 
    for (int i = 2; i < n; i++){
         if (n % i == 0){
            return false; 
        } 
    } 
    return true; 
}

bool happy(int n){
    string number;
    int sum = n;

    vector<bool> visited;
    visited.assign(10000, false);
    while(sum != 0 && !visited[sum]){
        number = to_string(sum);
        visited[sum] = true;
        sum = 0;
        for(int i = 0; i < number.size(); i++)
        {
             sum += pow((int)(number[i] - '0'), 2);
        }

        if (sum == 1) {
            return true;
        }
        
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    int P;
    cin >> P;
    for(int i = 0; i < P; i++)
    {
        int set = 0, number = 0;
        cin >> set >> number; 
        if (isPrime(number) && happy(number)) {
            cout << set << " " << number << " YES\n";
        }
        else
        {
            cout << set << " " << number << " NO\n";
        } 
    }


    return 0;
}
