/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1091 - Division of Nlogonia
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    // The number of queries that will be made.
    unsigned int K;
    // Representing the coordinates of the division point.
    int M, N;

    while(cin >> K)
    {
        // Representing the coordinates of a residence.
        int X, Y;
        cin >> M >> N;
        for(int i = 0; i < K; i++)
        {
            cin >> X >> Y;
            if(X > M and Y > N)
            {
                cout << "NE" << endl;
            }
            else if(X < M and Y > N)
            {
                cout << "NO" << endl;
            }
            else if(X < M and Y < N)
            {
                cout << "SO" << endl;
            }
            else if(X > M and Y < N)
            {
                cout << "SE" << endl;
            } else
            {
                cout << "divisa" << endl;
            }
        }
    }
    return 0;
}
