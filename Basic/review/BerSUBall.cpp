/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 489B - B. BerSU Ball
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <vector>
#include <iostream>
#include <algorithm>

#define UNREACHABLE_SKILL 1000

using namespace std;

vector<int> entrance(int K)
{
    int S;
    // Si is the i-th person's dancing skill
    vector<int> skills;
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &S);
        skills.push_back(S);
    }
    sort(skills.begin(), skills.end());
    return skills;
}

int main() {
    int N, M;
    // The number of boys
    scanf("%d", &N);
    vector<int> boys = entrance(N);
    // The number of girls
    scanf("%d", &M);
    vector<int> girls = entrance(M);
    // Maximum possible number of pairs formed.
    int pairs = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if (abs(boys[i] - girls[j]) <= 1)
            {
                girls[j] = UNREACHABLE_SKILL;
                pairs += 1;
                break;
            }
        }
    }
    printf("%d\n", pairs);
    return 0;
}
