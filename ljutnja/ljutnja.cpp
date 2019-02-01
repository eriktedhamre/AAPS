#include <stdio.h>
#include <iostream>
#include <algorithm> 
#include <cmath>
#include <stdint.h>
#include <inttypes.h>

using namespace std;
// Pre allocating array to save time, i think
int children[100010];
int N;
long long M;

// Calculate candy used
// by iterating through the children array
// and adding the candy needed to lower
// the current child to the limit
long long candy_used(int limit){
    long long ans = 0;
    for(int i = 0; i < N; i++){
        if(children[i] > limit){
            ans += (children[i] - limit);
        }
    }
    return ans;
}

int main(){
    // Get input
    scanf("%lld %d", &M, &N);
    int child;
    // Taking into account that a child can have 0 as it's wish
    int i = 0;
    while(i < N){
        scanf("%d", &child);
        // Unsure what to do in case of too large wish
        if (0 < child && child < 2000000000){
        children[i] = child;
        i++;
        }
        else{
        // Remove illegal child
        N--;
        }  
    }
    
    // Sort the input to enable binary searching
    sort(children, children + N);
    //printf("Finished sort \n");
    int low = 0, high = children[N - 1];
    int mid;
    while(high != low){
        // +1 to avoid rounding errors
        mid = (low + high + 1)/2;
        long long candy = M;
        // Candy needed to lower the higher wishes to mid
        long long candy_required = candy_used(mid);
        candy -= candy_required;
        // Candy Left, lower the limit else raise it
        if(candy > 0){
            // Set a stricter limit
            // to consume more candy
            high = mid - 1;
        }
        else{
            // Loosen the limit
            // to consume less candy
            low = mid;
        }
    }
    //printf("%d upper limit for wishes \n", low);
    // Raise it to guarantee success and then deal with the rest
    // Iterate through the children array and see how much candy
    // We have left after lowering the kids to the limit
    low++;
    for(int i = 0; i < N; i++)
    {
        if(children[i] > low){
            M -= (children[i] - low);
            children[i] = low;
        }
    }
    //printf("%lld Candies left after having lowered it to the guaranteed limit \n", M);
    // Lower the limit to lower the kids we can to the upper limit until candy runs out
    // Iterate from right to left to lower higher wishes first
    low--;
    for(int i = N - 1;  i >= 0 && M > 0; i--)
    {
        if(children[i] > low){
            children[i]--;
            M--;
        }
    }
    //printf("%lld M should be 0 \n", M);
    
    // Iterate through the children array
    // calculate the anger
    // by squaring the remaining wishes
    long long anger = 0;
    for(int i = 0; i < N; i++){
        anger += ((long long)children[i]) * ((long long)children[i]);
    }
    printf("%llu \n", anger);
    return 0;
}


/*
Stopping at the end
We can bring all values down to last element.
Then use the remainning candies to get rid of the rest,
which bring us to [0, 0, 1]
Test fall  Output
5 3          1
1
3
2

Stopping at the end
We can bring all values down to last element.
Then use the remaining candies to get rid of the rest,
which brings us to [1, 1, 1, 1]
Test fall   Output 
10 4          4
4
5
2
3
Stopping at the beginning
Testfall    Output
10 3          3
11
1
1

Stopping in the middle
Expected [2, 2, 1, 1, 1, 1] = 12
Testfall    Output
16 6          12
4
4
4
4
4
4

Stopping second to last
Expected [2, 2, 1, 1]
Testfall    Output
10 4          10
5 - 3 = 2
5 - 3 = 2
5 - 4 = 1 
1

Testfall    Output
10 4          91 
8 - 3 = 5
8 - 3 = 5
7 - 2 = 5
6 - 2 = 4

Testfall    Output
10 3          1
11
0
0

Testfall    Output
2 1           1
3

Testfall    Output DOESNT WORK CURRENTLY
10  5        158
8 - 2 = 6       
8 - 2 = 6
8 - 2 = 6
7 - 2 = 5
7 - 2 = 5

Testfall    Output
20 11         17
3 - 2 = 1
3 - 2 = 1
3 - 2 = 1
3 - 2 = 1
3 - 2 = 1
3 - 2 = 1
3 - 2 = 1
3 - 2 = 1
3 - 2 = 1
3 - 1 = 2
3 - 1 = 2

Testfall        Output
1000000000 1      1     
1000000001

Testfall        Output
100000000 2     500000000000000000
100000000
100000000        

Testfall            Output
10 5               151363813
12313
1
1
1
1
*/