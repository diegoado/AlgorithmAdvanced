/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1357 - In Braille
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <map>
#include <iostream>

using namespace std;

string decToBraille(string decimal, unsigned int size)
{
    map<char, string[3][1]> dictionary = {{'0', {{".*"}, {"**"}, {".."}}}, {'1', {{"*."}, {".."}, {".."}}},
                                          {'2', {{"*."}, {"*."}, {".."}}}, {'3', {{"**"}, {".."}, {".."}}},
                                          {'4', {{"**"}, {".*"}, {".."}}}, {'5', {{"*."}, {".*"}, {".."}}},
                                          {'6', {{"**"}, {"*."}, {".."}}}, {'7', {{"**"}, {"**"}, {".."}}},
                                          {'8', {{"*."}, {"**"}, {".."}}}, {'9', {{".*"}, {"*."}, {".."}}}};

    string braille;
    for(int i = 0; i < 3; i++)
    {
        for (int key = 0; key < size-1; key++)
        {
            braille.append(dictionary[decimal[key]][i][0]).append(" ");
        }

        braille.append(dictionary[decimal[size-1]][i][0]).append("\n");
    }
    return braille;
}

void brailleToDec(string braille[], unsigned int size)
{
    map<string, char> dictionary = {{".***..", '0'}, {"*.....", '1'}, {"*.*...", '2'},
                                    {"**....", '3'}, {"**.*..", '4'}, {"*..*..", '5'},
                                    {"***...", '6'}, {"****..", '7'}, {"*.**..", '8'},
                                    {".**...", '9'}};
    for (int i = 0; i < size; ++i)
    {
        cout << dictionary[braille[i]];
    }
    cout << endl;
}

int main() {

    // The number of digits in the message
    unsigned int D;

    while(true) {
        cin >> D;
        if(D == 0) break;

        // The type of message that your program must translate to Braille or decimal.
        char type;
        cin >> type;

        // The message in decimal.
        string number;
        // The message in Braille.
        string braille[D];

        if(type == 'S')
        {
            cin >> number;
            cout << decToBraille(number, D);
        }
        else
        {
            string input;
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < D; j++)
                {
                    cin >> input;
                    braille[j].append(input);
                }
            }
            brailleToDec(braille, D);
        }
    }
    return 0;
}