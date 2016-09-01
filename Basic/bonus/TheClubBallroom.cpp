/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1086 - The Club Ballroom
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <algorithm>

using namespace std;

int cover_hall(int list[], int k, int d, int t)
{
    int i = 0, planks = 0;

    while(i < k and t > 0)
    {
        if(list[i] + list[k] == d)
        {
            i++;
            k--;
            t--;
            planks += 2;
        }
        else if(list[k] == d)
        {
            k--;
            t--;
            planks += 1;
        }
        else if(list[i] == d)
        {
            i++;
            t--;
            planks += 1;
        }
        else if(list[i] + list[k] > d)
        {
            k--;
        }
        else
        {
            i++;
        }

    }
    if(i == k and t > 0 and list[k] == d)
    {
        t--;
        planks += 1;
    }

    if(t > 0)
    {
        return -1;
    }
    else
    {
        return planks;
    }
}

int main() {
    // The ballroom dimensions in meters.
    unsigned int M,N;
    // L representing the planks width in centimeters.
    int L;
    // The number total of planks.
    unsigned int K;

    while(true)
    {
        cin >> M >> N;
        if(M == 0 and N == 0) break;

        cin >> L; cin >> K;
        // The array of K integers, representing the length of the planks, in meters;
        int planks[K];
        for (int i = 0; i < K; i++)
        {
            cin >> planks[i];
        }
        /*
         * H and V representing the smallest number of planks needed to cover the whole ballroom floor
         * in the horizontal and vertical.
         */
        int H, V;
        sort(planks, planks + K);

        if(M*100 % L == 0)
        {
            H = cover_hall(planks, K - 1, N, M*100/L);
        }
        else
        {
            H = -1;
        }
        if(N*100 % L == 0)
        {
            V = cover_hall(planks, K - 1, M, N*100/L);
        }
        else
        {
            V = -1;
        }

        if(H == -1 and V == -1)
        {
            cout << "impossivel" << endl;
        }
        else if(H == -1)
        {
            cout << V << endl;
        }
        else if(V == -1)
        {
            cout << H << endl;
        }
        else
        {
            cout << min(H, V) << endl;
        }
    }
    return 0;
}