/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * UVA - Online Judge
 * Problem: 10104 - Euclid Problem
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

typedef long long ll;

// C function for extended Euclidean Algorithm
ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1, gcd = extended_gcd(b, a % b, x1, y1);
    // Update x and y using results of recursive
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main() {
    ll a, b, x, y, gcd;
    while (scanf("%lld %lld", &a, &b) != EOF) {
        gcd = extended_gcd(a, b, x, y);

        // Print the integers X, Y and D
        printf("%lld %lld %lld\n", x, y, gcd);
    }
    return 0;
}