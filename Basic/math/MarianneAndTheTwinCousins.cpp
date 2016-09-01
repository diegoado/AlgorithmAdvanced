/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1926 - Marianne and The Twin Cousins
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <string.h>
#include <iostream>

#define ll long long
#define UPPER_BOUND 1000001

using namespace std;

int main() {
    ll twins[UPPER_BOUND];
    memset(twins, 1, sizeof(twins));

    ll prime = 2;
    twins[0] = twins[1] = 0;

    // Find all twins primes numbers less than UPPER_BOUND
    for(ll i = 2; i < UPPER_BOUND; i++)
    {
        if(twins[i])
        {
            for(ll j = i * i; j < UPPER_BOUND; j+=i)
            {
                twins[j] = 0;
            }
            if(abs(prime - i) == 2)
                twins[prime] = twins[i] = 1;
            else
                twins[i] = 0;

            prime = i;
        }
    }

    // Accumulate the amount of twins primes numbers
    for(int k = 2; k < UPPER_BOUND; k++)
    {
       twins[k] += twins[k-1];
    }
    // The number of querys
    ll Q;
    // The lower and upper bound to find twins primes numbers
    ll X, Y;

    cin >> Q;
    while(Q--)
    {
        cin >> X >> Y;
        if(X > Y) swap(X, Y);

        cout << twins[Y] - twins[X-1] << endl;
    }
    return 0;
}