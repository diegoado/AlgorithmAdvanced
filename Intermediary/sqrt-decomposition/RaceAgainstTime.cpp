/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: RACETIME - Race Against Time
 * Time limit per test: 1.242 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <vector>
#include <iostream>
#include <algorithm>

#define B_SIZE 320
#define MAX_N 100001

using namespace std;

int A[MAX_N], Ai[MAX_N];

vector< int > group[B_SIZE];
int lower[B_SIZE], upper[B_SIZE];

int binary_search(int i, int v) {
    int ret = upper_bound(group[i].begin(), group[i].end(), v) - group[i].begin();
    return ret;
}

int main() {
    char op;
    int n, Q, p, q, x;

    scanf("%d %d", &n, &Q);
    for( int i = 1; i <= n; i++ )
        scanf("%d", &A[i]);

    //initialize blocks
    int k = 0;
    int bkn_size = (int) sqrt(n);
    for (int i = 1; i <= n; i += bkn_size) {
        k++;
        lower[k] = i;
        upper[k] = min(n, i + bkn_size - 1);
        for (int j = lower[k]; j <= upper[k]; j++ ) {
            group[k].push_back(A[j]);
            Ai[j] = k;
        }
        sort(group[k].begin(), group[k].end());
    }

    while (Q--) {
        scanf(" %c", &op);

        if (op == 'M') {
            scanf("%d %d", &p, &x);
            for (int i = 0; i < group[Ai[p]].size(); i++)
                if (group[Ai[p]][i] == A[p] ) {
                    A[p] = group[Ai[p]][i] = x;
                    break;
                }
            sort(group[Ai[p]].begin(), group[Ai[p]].end());
        } else {
            int answer = 0;
            scanf("%d %d %d", &p, &q, &x);

            for (int i = Ai[p]; i <= Ai[q]; i++) {
                if (p <= lower[i] && q >= upper[i] ) {
                    answer += binary_search(i, x);
                } else {
                    for (int j = max(lower[i], p); j <= min(upper[i], q); j++ )
                        answer += A[j] <= x;
                }
            }
            printf("%d\n", answer);
        }
    }
    return 0;
}