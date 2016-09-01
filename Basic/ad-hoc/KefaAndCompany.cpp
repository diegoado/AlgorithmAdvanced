/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 580B - B. Kefa and Company
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
    long int M;
    long int S;
} Friend;

int cmp(const void *frd1, const void *frd2)
{
    return (*(Friend *)frd1).M - (*(Friend *)frd2).M;
}

int main() {
    /*
     * The number of Kefa's friends and
     * the amount of money that a friend feels poor when compared with other Kefa's friend.
     */
    unsigned int N, D;

    cin >> N >> D;
    // All friendship factors
    long long factor[N+1];
    // List of Kefa's friend
    Friend frd[N+1];

    for(int i = 1; i <= N; i++)
    {
        cin >> frd[i].M >> frd[i].S;
    }

    factor[0] = 0;
    qsort(frd+1, N, sizeof(Friend), cmp);

    for(int i = 1; i <= N; i++)
    {
        factor[i] = factor[i-1] + frd[i].S;
    }
    // The maximum friendship factor that Kefa can be reached.
    long long friendship = 0;

    int k = 1;
    for(int j = 1; j <= N; j++)
    {
        while(k <= N and frd[k].M - frd[j].M < D)
        {
            k++;
        }
        if(factor[k-1] - factor[j-1] > friendship)
        {
            friendship = factor[k-1] - factor[j-1];
        }
    }
    cout << friendship << endl;
    return 0;
}
