/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1307 - All You Need is Love
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <string>
#include <iostream>

#define ull unsigned long

using namespace std;

ull toDec(string bin)
{
    ull dec = 0, pow = 1;
    for(int i = bin.length() - 1; i >= 0; i--)
    {
        dec += (bin[i] - '0') * pow;
        pow <<= 1;
    }
    return dec;
}

ull gdc(ull x, ull y)
{
    if(y == 0)
        return x;
    else
        return gdc(y, x % y);
}

int main() {
    // The number of tests cases
    int N;
    cin >> N;
    // S1 and S2 is a input for the love machine in binary representation
    string S1, S2;
    for(int i = 0; i < N; i++)
    {
        cin >> S1; cin >> S2;

        if(gdc(toDec(S1), toDec(S2)) != 1)
            cout << "Pair #" << i+1 << ": All you need is love!" << endl;
        else
            cout << "Pair #" << i+1 << ": Love is not all you need!" << endl;
    }
    return 0;
}
