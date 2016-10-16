/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: FINDSR - Find String Roots
 * Time limit per test: 0.613 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define MAX_N 100010

using namespace std;

int lpsArr[MAX_N];

void computeLPSArray(string pattern) {
    for (int i = 1, j = 0; i < pattern.size(); i++) {
        while(j > 0 and pattern[i] != pattern[j])
            j = lpsArr[j - 1];

        if (pattern[i] == pattern[j])
            j++;

        lpsArr[i] = j;
    }
}

int main() {
    string s;

    while (true) {
        cin >> s;
        if (s == "*") break;
        // Pre process the pattern (calculate lpsArr[])
        computeLPSArray(s);

        int strlen  = (int) s.size();
        int rootlen = strlen - lpsArr[strlen - 1];

        if (rootlen < strlen && strlen % rootlen == 0)
            printf("%d\n", strlen / rootlen);
        else
            printf("1\n");
    }
    return 0;
}
