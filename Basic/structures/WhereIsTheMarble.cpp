/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1025 - Where is the Marble?
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <algorithm>

using namespace std;

// Binary search to found number Qi in the list of marbles.
int query(int marble[], int tail, int Qi)
{
    int head = 0, mid = tail/2;
    while(head < tail)
    {
        if(marble[mid] < Qi)
        {
            head = mid+1;
            mid = (head + tail) / 2;
        }
        else if(marble[mid] > Qi or (mid > 0 and marble[mid-1] == Qi))
        {
            tail = mid-1;
            mid = (head + tail) / 2;
        }
        else
        {
            return mid+1;
        }
    }
    if(marble[mid] == Qi)
        return  mid+1;
    else
        return -1;
}

int main() {
    // Make the current test case in the game.
    int CASE = 1;
    // N is the number of marbles and Q is the number of queries Meena that would make.
    unsigned int N, Q;

    while(true)
    {
        cin >> N >> Q;
        if(N == 0 and Q == 0) break;
        // The list that contains the numbers written on the N marbles.
        int marble[N];
        for(int i = 0; i < N; i++)
        {
            cin >> marble[i];
        }

        int ask, reply;
        sort(marble, marble + N);
        cout << "CASE# " << CASE << ":" << endl;

        for(int j = 0; j < Q; j++)
        {
            cin >> ask;
            reply = query(marble, N-1, ask);

            if(reply == -1)
            {
                cout << ask << " not found" << endl;
            }
            else
            {
                cout << ask << " found at " << reply << endl;
            }
        }
        CASE++;
    }
    return 0;
}

