/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1091 - Bingo!
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

bool isPossible(int n, int b, int *list)
{
    // The bag containing N+1 balls, numbered from 0 to N
    int bag[n+1];
    memset(bag, 0, sizeof(bag));

    for (int i = 0; i < b; i++)
    {
        for (int j = i; j < b; j++)
        {
            bag[abs(list[i]-list[j])] = 1;
        }    
    }
    int *found = find(bag, bag + (n + 1), 0);
    if(found != bag + (n + 1))
    {
        return false;
    }
    return true;
}

int main() {
    /*
     * N is a combination of numbers arranged in columns and rows.
     * B represents the number of balls which remained in the bag.
     */
    int N, B;

    while(true)
    {
        cin >> N >> B;
        if(N == 0 and B == 0)
        {
            break;
        }
        // List of distinct integers, indicating the balls which remained in the bag.
        int balls[B];
        for (int i = 0; i < B; ++i)
        {
            cin >> balls[i];
        }
        if(isPossible(N, B, balls))
        {
            cout << "Y" << endl;
        } else
        {
            cout << "N" << endl;
        }
    }
    return 0;
}