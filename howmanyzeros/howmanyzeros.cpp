#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

unsigned long long cnt(unsigned m) {
  unsigned long long mc = 1;
  unsigned mleft = m, mright = 0, pow10 = 1; 
  while(mleft){
    int digi = mleft%10;
    mleft /= 10;
    mc += digi ? mleft*pow10 : (mleft-1)*pow10+mright+1;
    mright = digi*pow10+mright;
    pow10 *=10;
  }
  return mc;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    return 0;
}
