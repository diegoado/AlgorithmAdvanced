/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 401C - C. Team
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <string.h>

using namespace std;

int main() {
    // The number of cards containing number 0 and the number of cards containing number 1.
    long N, M;
    cin >> N >> M;
    // Array contains the cards organized.
    int cards[N+M];
    memset(cards, 0, sizeof(cards));

    if(N-1 <= M and M <= 2*(N+1))
    {
        if(M == N-1)
        {
            for(long i = 1; i < N+M; i+=2)
            {
                cards[i] = 1;
            }
        }
        else if(M == N)
        {
            for(long i = 0; i < N+M ; i+=2)
            {
                cards[i] = 1;
            }
        }
        else
        {
            // Number of cards surpluses that containing number 1.
            long i = 0, Mi = M - (N+1);
            cards[N+M-1] = 1;

            while(i < N+M-1)
            {
                if(Mi > 0)
                {
                    cards[i] = cards[i+1] = 1;
                    Mi--;
                    i +=3;
                }
                else
                {
                    cards[i] = 1;
                    i +=2;
                }
            }
        }
        for(long j = 0; j < N+M; j++)
        {
           cout << cards[j];
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}
