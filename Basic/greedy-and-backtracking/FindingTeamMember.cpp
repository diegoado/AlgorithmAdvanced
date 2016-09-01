/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 579B - B. Finding Team Member
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define MAX_PEOPLE 801

using namespace std;

typedef struct {
    int one, two, strength;
} Team;

int cmp(const void *a, const void *b)
{
    return (*(Team*)b).strength - (*(Team*)a).strength;
}

int used[MAX_PEOPLE];

int main() {
    int N, K = 0;
    scanf("%d", &N);

    Team groups[2*N*N - N];
    for(int i = 2; i <= 2*N; i++)
    {
        for(int j = 1; j < i; j++)
        {
            groups[K].one = i;
            groups[K].two = j;
            scanf("%d", &groups[K++].strength);
        }
    }
    int teams[2*N+1];
    qsort(groups, K, sizeof(Team), cmp);

    for(int i = 0; i < K; i++)
    {
        if(!used[groups[i].one] && !used[groups[i].two])
        {
            teams[groups[i].two] = groups[i].one;
            teams[groups[i].one] = groups[i].two;
            used[groups[i].one] = used[groups[i].two] = 1;
        }
    }
    for(int j = 1; j <= 2*N; j++)
    {
        printf("%d ", teams[j]);
    }
    printf("\n");
    return 0;
}
