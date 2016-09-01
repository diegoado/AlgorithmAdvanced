/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 552B - B. Vanya and Books
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define ull unsigned long long

using namespace std;

ull countDigits(ull number)
{
    ull digits = 0;
    do
    {
        digits++;
        number /= 10;
    } while(number != 0);

    return digits;
}

ull pow(int base, ull exponent)
{
    ull sum;
    if(exponent == 0) return 1;

    sum = pow(base, exponent/2);
    sum = sum * sum;

    if(exponent % 2 == 1) sum = sum * base;

    return sum;
}

int main() {
    // The number of books in the library
    ull N;
    cin >> N;
    // The number of digits in N
    ull sz = countDigits(N);
    // The number of digits that Vanya will need to write down in the labels of all the books.
    ull digits = sz * (N + 1);

    for(ull i = 0; i < sz; i++)
    {
        digits -= pow(10, i);
    }

    cout << digits << endl;
    return 0;
}

