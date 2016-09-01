/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 557B - B. Pasha and Tea
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    // The number of Pasha's friends that are boys and the capacity of Pasha's teapot in milliliters
    scanf("%d %d", &N, &W);

    int ai;
    vector<int> cups;
    // The capacities of Pasha's tea cups in milliliters.
    while (cin >> ai)
        cups.push_back(ai);

    sort(cups.begin(), cups.end());

    // The maximum total amount of water in milliliters that Pasha can pour to his friends
    printf("%.1f\n", min(min(cups[0]/1.0, cups[N]/2.0) * 3*N, W/1.0));
    return 0;
}

