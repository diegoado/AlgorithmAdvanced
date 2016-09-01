/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 570B - B. Simple Game
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    int N, M;
    // The range of numbers in the game, and the number selected by Misha respectively.
    scanf("%d %d", &N, &M);

    if(M - 1 >= N - M)
        printf("%d\n", max(1, M - 1));
    else
        printf("%d\n", min(N, M + 1));

    return 0;
}
