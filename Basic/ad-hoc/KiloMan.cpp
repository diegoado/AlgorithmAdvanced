/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1250 - KiloMan
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {

    // Number of test cases and shots.
    unsigned int N, S;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> S;
        // Jumps that KiloMan will attempt;
        char jumps[S];
        // Pattern of heights at which the shots are being fired;
        unsigned int shots[S];

        for(int j = 0; j < S; j++)
        {
            cin >> shots[j];
        }
        for(int j = 0; j < S; j++)
        {
            cin >> jumps[j];
        }

        // Integer representing the number of times KiloMan is hit.
        unsigned int count = 0;
        for(int k = 0; k < S; k++)
        {
            if(jumps[k] == 'S' and shots[k] <= 2)
            {
                count++;
            } else if(jumps[k] == 'J' and shots[k] > 2)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}