/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 588B - B. Duff in Love
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <math.h>
#include <iostream>

#define ull unsigned long long

using namespace std;

int main() {
    // N is a integer between 1 and 10000000000000
    ull N;
    cin >> N;

    // The biggest lovely number in Duff's store.
    ull lovely = 1;
    ull limit = sqrt(N) + 1;

    for(ull i = 2; i < limit; i++)
    {
        if(N % i == 0)
        {
            do
                N /= i;
            while(N % i == 0);

            lovely *= i;
        }
    }
    cout << (N > 1 ? lovely *= N : lovely) << endl;
    return 0;
}