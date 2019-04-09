#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

class prime_sieve{
    private:
        vector<bool> prime;
        long long count;
    public: 
        prime_sieve(long long size){
            prime.assign(size + 1, true);
            count = size - 1;
            prime[0] = false;
            prime[1] = false;

            for(long long i = 2; i < sqrt(size); i++){
                if(prime[i]){
                    long long j = pow(i, 2);
                    while(j <= size){
                        if(prime[j]){
                            count--;
                            prime[j] = false;
                        }
                        j += i;
                    }
                }
            }
        }

        long long primes(){
            return count;
        }

        bool get_bit(long long pos){
            return prime[pos];
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, q;
    scanf("%lld %lld", &n, &q);
    prime_sieve primes = prime_sieve(n);
    printf("%lld\n", primes.primes());

    long long pos;
    for(int i = 0; i < q; i++){
        scanf("%lld", &pos);
        printf("%d\n", primes.get_bit(pos));
    }
    return 0;
}
