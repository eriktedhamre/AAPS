// Basd on geeksforgeeks.org/prime-factor/
#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

void primeFactors(long n, vector<long> &factors)
{
    while (n%2 == 0)
    {
        factors.push_back(2);
        n = n/2;
    }
    
    for (long i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            factors.push_back(i);
            n = n/i;
        }
        
    }

    if (n > 2)
    {
        factors.push_back(n);
    }   
}

int main()
{
    long n;
    cin >> n;

    if (n == 1)
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<long> factors;

    primeFactors(n, factors);

    long sum = 1;
    for (size_t i = 0; i < factors.size(); i++)
    {
        cout << factors[i] << "\n";
    }    
    return 0;
}
