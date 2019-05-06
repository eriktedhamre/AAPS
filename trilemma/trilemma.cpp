#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

int main() {
    
    int N;
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
    {
        int x1,y1,x2,y2,x3,y3;

        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

        double area = 0.5*abs((x1 - x3)*(y2 - y1) - (x1 - x2)*(y3 - y1));

        if (area == 0) {
            printf("Case #%d: not a triangle\n", i);
            continue;
        }
        
        // Pythagoran, we don't need to SQRT
        // since we only calculate with j^2
        // where j is the side length
        int a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int b = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
        int c = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);

        // In ABC with longest side c
        // If c^2 < a^2 + b^2 triangle is acute
        // If c^2 = a^2 + b^2 triangle is right
        // If c^2 > a^2 + b^2 triangle is obtuse
        if (a == b || b == c || c == a) {
            //isosceles

            // a longest side
            if (a >= b && a >= c) {
                if (a == b + c) {
                    printf("Case #%d: isosceles right triangle\n", i);
                }
                else if(a > b + c)
                {
                    printf("Case #%d: isosceles obtuse triangle\n", i);
                }
                else
                {
                    printf("Case #%d: isosceles acute triangle\n", i);
                }
            } // b longest side
            else if (b >= a && b >= c)
            {
                if (b == a + c) {
                    printf("Case #%d: isosceles right triangle\n", i);
                }
                else if(b > a + c)
                {
                    printf("Case #%d: isosceles obtuse triangle\n", i);
                }
                else
                {
                    printf("Case #%d: isosceles acute triangle\n", i);
                }
            }
            else // c longest side
            {
                if (c == a + b) {
                    printf("Case #%d: isosceles right triangle\n", i);
                }
                else if(c > b + a)
                {
                    printf("Case #%d: isosceles obtuse triangle\n", i);
                }
                else
                {
                    printf("Case #%d: isosceles acute triangle\n", i);
                }
            }
        }
        else
        {
            //scalene
            // a longest side
            if (a >= b && a >= c) {
                if (a == b + c) {
                    printf("Case #%d: scalene right triangle\n", i);
                }
                else if(a > b + c)
                {
                    printf("Case #%d: scalene obtuse triangle\n", i);
                }
                else
                {
                    printf("Case #%d: scalene acute triangle\n", i);
                }
            } // b longest side
            else if (b >= a && b >= c)
            {
                if (b == a + c) {
                    printf("Case #%d: scalene right triangle\n", i);
                }
                else if(b > a + c)
                {
                    printf("Case #%d: scalene obtuse triangle\n", i);
                }
                else
                {
                    printf("Case #%d: scalene acute triangle\n", i);
                }
            }
            else // c longest side
            {
                if (c == a + b) {
                    printf("Case #%d: scalene right triangle\n", i);
                }
                else if(c > b + a)
                {
                    printf("Case #%d: scalene obtuse triangle\n", i);
                }
                else
                {
                    printf("Case #%d: scalene acute triangle\n", i);
                }
            }
        }
    }
    
    return 0;
}
