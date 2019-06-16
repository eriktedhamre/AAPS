/*
* Author: Erik Tedhamre
*/
#include <bits/stdc++.h>
using namespace std;

double expectedPrize(int n, double t, int k){
    if (k == 0){
        return pow(2, n);
    }
    double c_prize = expectedPrize(n, t, k-1);
    double s_prize = pow(2, n-k);
    if (t * c_prize > s_prize)
    {
        return (((1 - pow(t, 2))*c_prize)/2)/(1-t);
    }
    else if (c_prize <= s_prize)
    {
        return s_prize;
    }
    else
    {
        double p0 = s_prize/c_prize;
        //printf("p0:%lf\n", p0);
        return ((p0 - t) * s_prize + ((1 - pow(p0, 2))*c_prize)/2)/(1-t); 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here
    int n;
    double t;
    while(scanf("%d %lf", &n, &t)){

        if (n == 0 && t == 0) {
            break;
        }

        printf("%.3lf\n", expectedPrize(n ,t, n));
    }
    return 0;
}
