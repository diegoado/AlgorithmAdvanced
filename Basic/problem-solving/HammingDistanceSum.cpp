/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 608B - B. Hamming Distance Sum
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <string>
#include <string.h>
#include <iostream>

#define ulli unsigned long long int

using namespace std;

int main() {
    // Two strings that represent a binary number.
    string A, B;
    cin >> A; cin >> B;
    // the sum of Hamming distances between a and all contiguous substrings of b of length |a|.
    ulli distance = 0;
    // The size of A and B
    ulli As = A.size(), Bs = B.size();
    // The array F[x][c] count the number of occurrences of the character c in the prefix [0, x) of B.
    int F[Bs+1][2];
    for(int i = 1; i <= Bs; i++)
    {
        for (int j = 0; j < 2; ++j)
        {
            F[i][j] = F[i-1][j];
        }
        F[i][B[i-1]-'0']++;
    }
    for(int i = 0; i < As; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            distance += abs(A[i]-'0' - j) * (F[Bs-As+i+1][j] - F[i][j]);
        }
    }
    cout << distance << endl;
    return 0;
}