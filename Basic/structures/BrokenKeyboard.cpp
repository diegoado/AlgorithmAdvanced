/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1451 - Subsequences
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    // Path indicates which side of the string R which will be worked.
    bool path;
    // S is the input string and Rl + Rr compose the result string.
    string S, Rl, Rr;

    while(cin >> S)
    {
        path = true;
        Rl = "", Rr = "";

        for(char c : S)
        {
            if(c == '[')
            {
                Rr = Rl + Rr;
                Rl = "";
                path = false;
            }
            else if(c == ']')
            {
                Rr = Rl + Rr;
                Rl = "";
                path = true;
            }
            else if(not path)
            {
                Rl.push_back(c);
            }
            else
            {
                Rr.push_back(c);
            }
        }
        cout << Rl + Rr << endl;
    }
    return 0;
}
