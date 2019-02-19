#include <bits/stdc++.h>
//#define REP(var, k) for (int var = 0; var < (int) k; ++var)
using namespace std;

//using vi=vector<int>;

long long gcd(long long a, long long b){
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Insert code here

    // 0.ddddd is of maximum length 9

    string input;
    
    while(cin >> input){
        if (input.size() == 1){
            break;
        }

        input.pop_back();
        input.pop_back();
        input.pop_back();
        //Find size of repeating fraction
        bool nine = false;
        bool proper = false;
        if((int)*(input.end() - 1) == '9'){
            nine = true;
            proper = true;
        }
        int r_size = input.size() - 2;
        if((int)*(input.end() - 1) == '0'){
            proper = true;
        }
        if(!nine){
            while(input.size() < 10){
            input.push_back(*(input.end() -1));
            }
        }
        double input_d = stod(input);

        if(nine){
            input_d += 0.000000001;
        }

        //printf("input_s %s\n", input.c_str());
        //printf("input_d %lf\n", input_d);

        long long precision = 1 * pow(10, r_size);
        //printf("precision %lld \n", precision);
        long double scaled_input = (long double)(input_d * (long double)precision);
        //printf("scaled_input %Lf \n", scaled_input);
        long double right_side_d = scaled_input - input_d;
        //printf("right_side_d %Lf \n", right_side_d);
        long long right_side = round(right_side_d);
        //printf("Right_side %lld \n", (long long)right_side);
        long long left_side;
        if(!proper){
            left_side = precision - 1;
        }
        else{
            left_side = precision;
        }
        long long input_gcd = gcd(right_side, left_side);

        long long denominator = left_side/input_gcd;

        long long numerator =  right_side/input_gcd;

        printf("%lld/%lld\n", numerator, denominator);
        }
    /*
    printf("dec_length %d \n", dec_length);
    long long precision = 1 * pow(10, dec_length);
    
    long double scaled_input = (long double)(input * (long double)precision);
    printf("scaled_input %Lf", scaled_input);
    long long right_side = (scaled_input - input);
    printf("Right_side %lld", (long long)right_side);
    long long left_side = precision - 1;
    long long input_gcd = gcd(right_side, left_side);
    long long denominator = left_side/input_gcd;
    long long numerator =  right_side/input_gcd;

    printf("%lld/%lld\n", numerator, denominator);
    */
    return 0;
}
