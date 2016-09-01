/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 359B - B. Permutation
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    int N, K;
    // Two integers n and k that representing a permutation.
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            printf(" ");
        if (K > 0)
        {
            K--;
            printf("%d %d", 2*i + 2, 2*i + 1);
        }
        else
        {
            printf("%d %d", 2*i + 1, 2*i + 2);
        }
    }
    return 0;
}