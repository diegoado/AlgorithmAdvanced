/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1507 - Subsequences
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <string>
#include <iostream>

using namespace std;

bool strStr(string S, string R)
{
    int i = 0;
    for(char c : S)
    {
        if(R[i] == c)
            i++;
        if(R.size() == i)
            return true;
    }
    return false;
}

int main() {
    // N representing the number of test cases and Q the number of queries.
    int N, Q;
    // S is the main string and R is the two string to be found in S.
    string S, R;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> S;
        cin >> Q;

        for(int j = 0; j < Q; j++)
        {
            cin >> R;
            if(strStr(S, R))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}