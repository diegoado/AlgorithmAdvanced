/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1120 - Contract Revision
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    // D is the digit that has failed in the machine.
    char D;
    // N is the number that was originally agreed for the contract.
    string N, number = "";

    while(true)
    {
        cin >> D >> N;
        if(D == '0' and N == "0") break;

        for(int i = 0; i < N.size(); i++)
        {
            if(N[i] != D)
            {
                if(number.empty() and N[i] == '0')
                {
                    continue;
                }
                else
                {
                    number.push_back(N[i]);
                }
            }
        }
        if(number.empty())
        {
            cout << "0" << endl;
        }
        else
        {
            cout << number << endl;
        }
        number.clear();
    }
    return 0;
}