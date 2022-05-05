#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    string line;
    int counter = 1;
    int prev_white;
    int current_white;
    char current_char;
    bool second_star;
    bool even;

    while (getline(cin, line) && line != "END")
    {
        prev_white = 0;
        current_white = 0;
        even = true;
        second_star = true;

        //cout << line << "\n";

        for (size_t i = 0; i < line.size(); i++)
        {
            current_char = line[i];
            if (current_char == '*' && prev_white == current_white)
            {
                current_white = 0;
                if (i == 1)
                {
                    second_star = false;
                }     
            }
            else if(current_char == '.')
            {
                current_white++;
            }
            else if (current_char == '*' && second_star)
            {
                prev_white = current_white;
                current_white = 0;
                second_star = false;
            }
            else
            {
                even = false;
                break;
            }
        }

        if (even)
        {
            cout << counter << " EVEN\n";
        }
        else
        {
            cout << counter << " NOT EVEN\n";
        }
        counter++; 
    }
}