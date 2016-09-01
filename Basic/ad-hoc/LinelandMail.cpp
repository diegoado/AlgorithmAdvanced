/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Code forces
 * Problem: 567A - A. Lineland Mail
 * Time limit per test: 3 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    // The number of n in Linelan
    unsigned int n;
    cin >> n;

    // Sequence of n distinct integers where xi is the x-coordinate of the i-th city
    long X[n];

    for(int i = 0; i < n; i++)
    {
      cin >> X[i];
    }

    for(int i = 0; i < n; i++)
    {
        // Minimum and Maximum cost of sending a letter from the i-th city
        unsigned int minimum, maximum;
        if(i == 0)
        {
            minimum = abs(X[i] - X[i+1]);
            maximum = abs(X[i] - X[n -1]);
        } else if(i == n - 1)
        {
            maximum = abs(X[i] - X[0]);
            minimum = abs(X[i] - X[i-1]);
        } else
        {
            maximum = max(abs(X[i] - X[0]), abs(X[i] - X[n-1]));
            minimum = min(abs(X[i] - X[i-1]), abs(X[i] - X[i+1]));

        }

        cout << minimum << " " << maximum << endl;
    }
    return 0;
}



