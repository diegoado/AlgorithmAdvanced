/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 576A - A. Vasya and Petya's Game
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    // Vasya thought of number x between 1 and n
    int N;
    cin >> N;

    int sieve[N+1];
    // The minimum number of questions he should ask to make a guaranteed guess of Vasya's number
    vector<int> pprimes;

    memset(sieve, 1, sizeof(sieve));
    sieve[0] = sieve[1] = 0;

    // Find all potential primes numbers less than N+1
    for(int i = 2; i < N+1; i++)
    {
        if(sieve[i])
        {
            for(int j = i * i; j < N+1; j+=i)
            {
                sieve[j] = 0;
            }
            pprimes.push_back(i);
            for(int k = i * i; k < N+1; k*=i)
            {
                pprimes.push_back(k);
            }
        }
    }

    cout << pprimes.size() << endl;
    for(int i = 0; i < pprimes.size(); i++)
    {
        cout << pprimes[i] << " ";
    }
    cout << endl;

    return 0;
}
