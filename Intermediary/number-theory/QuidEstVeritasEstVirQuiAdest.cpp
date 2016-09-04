/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1580 - Quid Est Veritas? Est Vir Qui Adest!
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <cstring>

#define ALPH 26
#define MAX_SIZE 1001
#define MOD 1000000007

using namespace std;

typedef long long int lli;

int alphabet[26];
lli factorials[MAX_SIZE];

lli fast_pow(lli base, lli exp) {
    long long ans = 1;
    while (exp) {
        if (exp & 1) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return ans;
}

lli inv_mod(lli x) {
    return fast_pow(x, MOD - 2);
}

int main() {
    factorials[0] = factorials[1] = 1;
    for (int i = 2; i < MAX_SIZE; i++)
        factorials[i] = factorials[i-1] * i % MOD;

    string line;
    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); i++)
            alphabet[line[i] - 'A']++;

        lli den = 1;
        lli n = factorials[line.size()];

        for (int j = 0; j < ALPH; j++)
            den = den * factorials[alphabet[j]] % MOD;

        n = n * inv_mod(den) % MOD;
        printf("%lld\n", n);

        // Cleaning array that storage char repetitions
        memset(alphabet, 0, sizeof(alphabet));
    }
    return 0;
}