/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1807 [P2] - Trinomial Triangle, the Revenge
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

#define ll long long
#define R_MOD 2147483647

ll trinomial_sum(int base, ll exponent)
{
    ll sum;
    if(exponent == 0) return 1;

    sum = trinomial_sum(base, exponent/2) % R_MOD;
    sum = sum * sum % R_MOD;

    if(exponent % 2 == 1) sum = sum * base;

    return sum % R_MOD;
}

int main() {
    // The row's number in the trinomial triangle.
    ll R;
    cin >> R;
    // The sum modulo (231 - 1) of all elements at row R
    cout << trinomial_sum(3, R) << endl;
    return 0;
}
