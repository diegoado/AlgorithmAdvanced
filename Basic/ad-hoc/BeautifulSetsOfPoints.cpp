/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 268C - C. Beautiful Sets of Points
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    // The size of the found beautiful set.
    unsigned int K;
    // Integers n and m that for all points (x, y) satisfy the inequalities: 0 ≤ x ≤ n; 0 ≤ y ≤ m; x + y > 0
    unsigned int N, M;

    cin >> N >> M;
    K = min(N, M) + 1;

    cout << K << endl;
    // One point (x, y) in the beautiful set.
    unsigned int X = 0, Y = M;
    for (int i = 0; i < K; i++)
    {
        cout << X << " " << Y << endl;
        X += 1, Y -= 1;
    }
    return 0;
}