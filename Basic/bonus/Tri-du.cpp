/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1933 - Tri-du
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    // The integers A and B indicates the value of the two one received cards.
    unsigned int A, B;

    cin >> A >> B;
    if(A != B and A > B)
    {
        cout << A << endl;
    }
    else
    {
        cout << B << endl;
    }
    return 0;
}