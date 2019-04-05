#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

using ll = long long;

ll gcd(ll a, ll b){
    return (b == 0 ? a : gcd(b, a % b));
}

ll modular_add(ll a, ll b, ll m){
    if( a >= m ){ a %= m; }
    if( b >= m ){ b %= m; }

    return (a + b) % m;
}

ll modular_sub(ll a, ll b, ll m){
    if( a >= m ){ a %= m; }
    if( b >= m ){ b %= m; }
    ll res = (a - b) % m;

    return (res < 0) ? res + m : res;
}

ll modular_mult(ll a, ll b, ll m){
    if( a >= m ){ a %= m; }
    if( b >= m ){ b %= m; }

    return (a * b) % m;
}

ll mult_inv(ll a, ll m){
    ll a_m_gcd = gcd(a, m);

    if(a_m_gcd != 1){ return -1; }
    if(m == 1){ return 0; }

    ll m_original= m, y = 0, x = 1;

    while(a > 1){
        ll q = a / m;
        // Saving m for next steo
        ll m_next = m;
        // Modulu with this next iteration
        m = a % m;
        // new l.h.s. is old r.h.s.
        a = m_next;
        m_next = y;
        y = x - q * y;
        x = m_next;
    }

    if(x < 0){
        x += m_original;
    }
    return x;
}

ll modular_div(ll a, ll b, ll m){
    if( a >= m ){ a %= m; }
    ll b_inv = mult_inv(b, m);
    if(b_inv == -1){
        return -1;
    }
    return (a *(b_inv % m)) % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t;

    while(scanf("%lld %lld", &n, &t) > 0 && n != 0 && t != 0){
        ll x, y;
        char op;
        for(int i = 0; i < t; i++){
            scanf("%lld %c %lld", &x, &op, &y);
            switch(op){
                case '+':
                    printf("%lld\n", modular_add(x, y, n));
                    break;
                case '-':
                    printf("%lld\n", modular_sub(x, y, n));
                    break;
                case '*':
                    printf("%lld\n", modular_mult(x, y, n));
                    break;
                case '/':
                    printf("%lld\n", modular_div(x, y, n));
                    break;
                default:
                    break;
            }
        }
    }

    return 0;
}
