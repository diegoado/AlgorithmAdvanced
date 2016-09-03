/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * ACM-ICPC Live Archive
 * Problem: 3501 - Sequence Sum Possibilities
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <vector>
#include <bitset>

#define MAX_N 46350

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

bitset<MAX_N> bs;
vll primes;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;

    for (ll i = 2; i < MAX_N; i++) {
        if (bs[i]) {
            for (ll j = i * i; j < MAX_N; j+= i) {
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}

// Count the sum of two or more consecutive positive integers
ll numOddDiv(ll n) {
    ll ans = 1;
    ll i = 0, pf = primes[i];
    while (pf * pf <= n) {
        ll pw = 0;
        while (n % pf == 0) {
            n /= pf;
            if (pf % 2 == 1 )
                pw++;
        }
        ans *= (pw + 1);
        pf = primes[++i];
    }
    if (n != 1 && n % 2 == 1) {
        ans *= 2;
    }
    return ans - 1;
}


int main() {
    ll n;
    int t, c;

    sieve();
    scanf("%d", &t);
    while (t--) {
        scanf("%d %lld", &c, &n);
        printf("%d %lld\n", c, numOddDiv(n));
    }
    return 0;
}