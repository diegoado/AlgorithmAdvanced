/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1107 - Laser Sculpture
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    unsigned int A, C;

    while(true)
    {
        cin >> A >> C;
        if(A == 0 and C == 0) break;

        unsigned int block[C+1];

        block[0] = A;
        for(int i = 1; i <= C; i++)
        {
            cin >> block[i];
        }

        int steps = 0;
        for(int j = 1; j <= C; j++)
        {
            if(block[j] < block[j -1])
            {
                steps += block[j -1] - block[j];
            }
        }
        cout << steps << endl;
    }
    return 0;
}