/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 555A - A. Case of Matryoshkas
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    int N, K, L = 0;
    // The number of matryoshkas and Matryoshka chains in the initial configuration.
    scanf("%d %d", &N, &K);
    /*
     * The descriptions of the chains:
     *
     *   The i-th line first contains number mi that is the numbers of matryoshkas in the chain
     *   The numbers ai1, ai2, ... , aimi are the number of dolls in each chain the numbers of matryoshkas
     */
    int mi, ai;
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &mi);
        for (int j = 0; j < mi; j++)
        {
            scanf("%d", &ai);
            if (ai == j + 1) L += 1;
        }
    }
    printf("%d\n", 2*N - K - 2*L + 1);
    return 0;
}
