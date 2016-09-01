/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI Online Judge
 * Problem: 1800 [P1][P2] - Where Are My Keys
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

// The maximum offices that Gabriel works in the last week
#define MAX_E 1001

using namespace std;

int main() {
    // The number of offices that Gabriel works in the last week and in the last two days.
    unsigned int Q, E;
    cin >> Q >> E;

    int index;
    int offices[MAX_E];
    for (int i = 0; i < MAX_E; ++i)
    {
        offices[i] = 1;
    }

    for(int j = 0; j < E; j++)
    {
        cin >> index;
        offices[index] = 0;
    }
    for(int k = 0; k < Q; k++)
    {
        cin >> index;
        cout << offices[index] << endl;

        offices[index] = 0;
    }
    return 0;
}
