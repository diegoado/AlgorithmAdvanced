/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: FACTCG2 - Medium Factorization
 * Time limit per test: 0.517 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define MAX_N 10000000

using namespace std;

typedef long long ll;

int factors[MAX_N] = {0};

void fastPrimeFactors(int size = MAX_N) {
    for (ll i = 2; i <= size + 1; i++) {
        if (factors[i] == 0) {
            for (ll j = i * i; j <= size + 1; j += i) {
                if (factors[j] == 0)
                    factors[j] = (int) i;
            }
            factors[i] = (int) i;
        }
    }
}

int main() {
    int n;

    // Find all primes lest than MAX_N
    fastPrimeFactors();
    while (scanf("%d", &n) != EOF) {
        printf("1");
        while (n > 1 && n % factors[n] == 0) {
            printf(" x %d", factors[n]);
            n /= factors[n];
        }
        printf("\n");
    }
    return 0;
}
