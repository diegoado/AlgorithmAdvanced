/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 611B - B. New Year and Old Property
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define ulli unsigned long long

using namespace std;

int main() {
    // The number A is one year and the number B last year in Limak's interval respectively.
    ulli A, B, Y, Yi;
    // All years from Limak's interval that have exactly one zero in the binary representation
    int years = 0;

    cin >> A >> B;
    for(int i = 1; i <= 60; i++)
    {
        // 2^x - 1 — A number without any zeros in the binary representation.
        Y = (1LL << i) - 1;
        for(int j = 0; j < i-1; j++)
        {
            // 2^x — A number power of two
            Yi = Y xor (1LL << j);
            // For each Y - Yi check if it is in Limak's interval respectively.
            years += Yi >= A and Yi <= B;
        }
    }
    cout << years << endl;
    return 0;
}
