/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: CEQU - Crucial Equation
 * Time limit per test: 3 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

// C function for extended Euclidean Algorithm
int extended_gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1, gcd = extended_gcd(b, a % b, x1, y1);
    // Update x and y using results of recursive
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main() {
    int x, y, gcd;
    int t, a, b, c;

    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        scanf("%d %d %d", &a, &b, &c);

        gcd = extended_gcd(a, b, x, y);
        // Resolving the given equation
        int eq = a * (x * c/gcd) + b * (y * c/gcd);

        if (c == eq)
            printf("Case %d: Yes\n", k);
        else
            printf("Case %d: No\n", k);
    }
    return 0;
}