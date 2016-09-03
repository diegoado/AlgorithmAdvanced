/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * UVA - Online Judge
 * Problem: 10673 - Play with Floor and Ceil
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <math.h>
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
    int t;
    ll a, b, c, p, q, x, y, n, gcc;

    scanf("%d", &t);
    for (int k = 0; k < t; k++) {
        scanf("%lld %lld", &a, &b);
        c = a;
        // Apply floor and ceil to find a and b extGCD coefficients
        a = (ll) floor((double) c/b);
        b = (ll)  ceil((double) c/b);
        // Get GCD of a and b
        gcc = extended_gcd(a, b, x, y);
        // Get n = ceil((x * (double) c/gcc) / -b) or n = floor((y * (double) c/gcc) / a) to determine p and q value
        n = (ll) ceil((x * (double) c/gcc) / -b);
        p = (x * c/gcc) + b * n;
        q = (y * c/gcc) - a * n;
        // Print answer
        printf("%lld %lld\n", p, q);
    }
        return 0;
}