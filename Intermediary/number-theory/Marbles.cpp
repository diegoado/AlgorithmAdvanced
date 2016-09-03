/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * UVA - Online Judge
 * Problem: 10090 - Marbles
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

/* Tutorial
 *
 * We want to find m1 and m2 that satisfy the equation  n1 * m1 + n2 * m2 = n,
 * and give us the minimum cost where cost = c1 * m1 + c2 * m2 .
 *
 *  Using extended Euclid to find gcd(n1, n2) and get m1`,m2` where n1 * m1` + n2 * m2` = gcd(n1, n2)
 *  to get m1 and m2 multiply both sides by n/gcd m1`=m1`*n/gcd , m2`=m2`*n/gcd.
 *
 *  Now m1 = m1 + n2 / g * t, m2 = m2 –  n1 / g * t
 *  any integer t satisfy the desired equation, but we want to minimize the cost
 *  c = c1 * m1 + c2 * m2 + t * (c1* n2 / g – c2 * n1 / g).
 *
 *  Since c1 * m1 +c2 * m2  is constant we want to minimize  t * (c1* n2 / g – c2 * n1 / g)
 *
 *  How to get t ?
 *
 *  As we mention above m1 = m1 + n2 / g * t  , m2 = m2 –  n1 / g * t , m1 && m2 >=0
 *
 *  So m1 + n2 / g * t >= 0,  n2 / g * t >= – m1 ,  t >= – m1 *g / n2
 *
 *  Also m2 –  n1 / g * t >= 0,  – n1 / g * t >= – m2 , t <= m2 * g / n1
 *
 *  so ceil(-m1 *g / n2) <= t <= floor(m2 * g / n1),
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

bool solve(ll n, ll c1, ll n1, ll c2, ll n2, ll &m1, ll &m2) {
    ll gcd;
    gcd = extended_gcd(n1, n2, m1, m2);
    if (n % gcd != 0)
        return false;

    m1 *= n / gcd, m2 *= n / gcd;
    n2 /= gcd, n1 /= gcd;

    ll c = (ll) ceil(-(double) m1 / n2), f = (ll) floor((double) m2 / n1);
    if (c > f)
        return false;

    ll cost = c1 * n2 - c2 * n1;
    if (cost * c < cost * f)
        m1 = m1 + n2 * c, m2 = m2 - n1 * c;
    else
        m1 = m1 + n2 * f, m2 = m2 - n1 * f;
    return true;
}

int main() {
    ll n;
    ll m1, m2;
    ll n1, c1, n2, c2;

    while (true) {
        scanf("%lld", &n);

        if (n == 0) break;
        scanf("%lld %lld %lld %lld", &c1, &n1, &c2, &n2);

        if (solve(n, c1, n1, c2, n2, m1, m2))
            printf("%lld %lld\n", m1, m2);
        else
            printf("failed\n");
    }
    return 0;
}
