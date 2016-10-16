/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 126B - B. Password
 * Time limit per test: 2 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define MAX_N 1000010

using namespace std;

int lpsArr[MAX_N];

void computeLPSArray(string pattern, int len) {
    lpsArr[0] = -1;
    int i = 0, j = -1;

    while(i < len) {
        while(j >= 0 and pattern[i] != pattern[j])
            j = lpsArr[j];

        i++;
        j++;
        lpsArr[i] = j;
    }
}

int main() {
    string s;

    cin >> s;
    int len = (int) s.size();

    computeLPSArray(s, len);
    int found = false, suitable = lpsArr[s.size()];
    while (suitable > 0) {
        for (int i = len - 1; i > suitable && !found; i--) {
            found = lpsArr[i] >= suitable;
        }
        if (found)
            break;

        suitable = lpsArr[suitable];
    }
    if (found)
        cout << s.substr(0, suitable) << endl;
    else
        cout << "Just a legend" << endl;
    return 0;
}
