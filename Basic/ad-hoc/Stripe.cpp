/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 18C - C. Stripe
 * Time limit per test: 2 second
 * Memory limit per test: 64 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <valarray>

using namespace std;

int main() {
    // The number of squares in the paper stripe.
    unsigned int N;

    cin >> N;
    // The numbers written in the squares of the stripe.
    valarray<int> stripe(N);
    for (int i = 0; i < N; i++)
    {
        cin >> stripe[i];
    }

    int possibilities;
    int sumRef, sumPartial;

    sumRef = stripe.sum();
    sumPartial = possibilities = 0;

    if(sumRef % 2 == 0)
    {
        sumRef /= 2;
        for (int j = 0; j < N-1; j++)
        {
            sumPartial += stripe[j];

            if(sumPartial == sumRef)
            {
                possibilities++;
            }
        }
    }
    cout << possibilities << endl;
    return 0;
}
