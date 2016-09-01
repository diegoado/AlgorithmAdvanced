/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1323 - Feynman
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <math.h>
#include <iostream>

using namespace std;

int main() {
    // The number of squares in each side of the grid.
    unsigned int N;
    while(true)
    {

        cin >> N;
        if(N == 0) break;

        // The number of different squares for the corresponding input.
        int square = 0, K = 0;
        while (K != N) {
            K++;
            square += pow(K, 2);

        }
        cout << square << endl;
    }
    return 0;
}
