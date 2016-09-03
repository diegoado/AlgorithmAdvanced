/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * ACM-ICPC Live Archive
 * Problem: 3571 - Visible Lattice Points
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define MAX_N 1001

using namespace std;

int grip[MAX_N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int t, n;

    grip[0] = 1;
    // (x,y) is not visible when there is an integer k dividing both x and y,
    // and is visible when there is no such integer.
    for (int i = 1; i < MAX_N; i++) {
        grip[i] = grip[i-1];

        for (int j = 1; j <= i; j++) {
            if (gcd(j, i) == 1)
                // the point (x, y) and (y, x) is visible in the grip.
                grip[i] += 2;
        }
    }
    scanf("%d", &t);
    for (int k = 1; k <= t; k++) {
        scanf("%d", &n);
        printf("%d %d %d\n", k, n, grip[n]);
    }

    return 0;
}