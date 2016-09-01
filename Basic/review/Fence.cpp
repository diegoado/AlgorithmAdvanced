/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 363B - B. Fence
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <limits>
#include <iostream>

using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int height[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> height[i];
    }

    int fence  = 1, minimumSum = 0;
    for (int j = 0; j < K; j++)
    {
        minimumSum += height[j];
    }
    int candidateSum, auxiliarySum = minimumSum;
    for (int i = 1; i <= N-K; i++)
    {
        candidateSum = auxiliarySum - height[i-1] + height[i + K-1];
        if (candidateSum < minimumSum)
        {
            fence = i + 1;
            minimumSum = candidateSum;
        }
        auxiliarySum = candidateSum;
    }
    printf("%d\n", fence);
    return 0;
}
