/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 546D - D. Soldier and Number Game
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <bitset>
#include <stdio.h>

#define ll long long
#define UPPER_BOUND 5000001

using namespace std;

bitset <UPPER_BOUND> sieve;
int divs[UPPER_BOUND], min_prime[UPPER_BOUND];

int main() {

    sieve.set();
    sieve[0]= sieve[1] = 0;

    // Find all primes numbers less than UPPER_BOUND
    for(ll i = 2; i < UPPER_BOUND; i++)
    {
        if(sieve[i])
        {
            // Save the one prime divisor of a number i and j
            for(ll j = i * i; j < UPPER_BOUND; j+=i)
            {
                sieve[j] = 0;
                if(min_prime[j] == 0) min_prime[j] = i;
            }
            min_prime[i] = i;
        }
    }
    // Calculate the maximum divisions of a number k
    for(int k = 2; k < UPPER_BOUND; k++)
    {
       divs[k] = divs[k/min_prime[k]] + 1;
    }
    // Accumulate the amount of maximum divisions in a number k
    for(int k = 2; k < UPPER_BOUND; k++)
    {
        divs[k] += divs[k-1];
    }

    // The number of games soldiers play
    int T;
    // Defines the value of n of form a!/b! for a game
    int A, B;

    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &A, &B);
        printf("%d\n", divs[A] - divs[B]);
    }
    return 0;
}