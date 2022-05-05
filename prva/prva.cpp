#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    int R, C;
    string line;

    getline(cin, line);

    istringstream is( line );
    string current_string;
    getline(is, current_string, ' ');
    R = stoi(current_string);
    getline(is, current_string, ' ');
    C = stoi(current_string);

    //cout <<"R: " << R << " C: "<< C << "\n";

    vector<vector<char> >crossword(R, vector<char>(C));
    
    for (size_t i = 0; i < R; i++)
    {       
            getline(cin, line);
            for (size_t j = 0; j < line.size(); j++)
            {
                crossword[i][j] = line[j];
            }
    }

    string current_word;
    string smallest_word;

    for (size_t i = 0; i < R; i++)
    {
        current_word = "";
        for (size_t j = 0; j < C; j++)
        {
            //cout << current_word << "\n";
            if (crossword[i][j] == '#')
            {
                if (current_word.length() < 2)
                {
                    current_word = "";
                    continue;
                }
                else if( (current_word < smallest_word) || (smallest_word.length() == 0) )
                {
                    //cout << "1 " << smallest_word << " 1" << "\n";
                    smallest_word = current_word;
                }
            }
            else if (j == (C - 1))
            {
                //cout << j << " " << crossword[i][j] << "\n";
                current_word.push_back(crossword[i][j]);
                if ((current_word.length() > 1) && ( (current_word < smallest_word) || (smallest_word.length() == 0) ))
                {
                    //cout << "2 " << smallest_word  << " 2"<< "\n"; 
                    smallest_word = current_word;
                }
            }
            else
            {
                current_word.push_back(crossword[i][j]);
            }
        }
    }

    //cout << "king" << smallest_word <<"\n";

    for (size_t i = 0; i < C; i++)
    {
        current_word = "";
        for (size_t j = 0; j < R; j++)
        {
            //cout << current_word << "\n";
            if (crossword[j][i] == '#')
            {
                if (current_word.length() < 2)
                {
                    current_word = "";
                    continue;
                }
                else if ( (current_word < smallest_word) || (smallest_word.length() == 0) )
                {
                    smallest_word = current_word;
                }
            }
            else if (j == (R - 1))
            {
                current_word.push_back(crossword[j][i]);
                if ( (current_word.length() > 1) && ( (current_word < smallest_word) || (smallest_word.length() == 0) ))
                {
                    smallest_word = current_word;
                }
            }
            else
            {
                current_word.push_back(crossword[j][i]);
            }
        }
    }
    cout << smallest_word << "\n";
}