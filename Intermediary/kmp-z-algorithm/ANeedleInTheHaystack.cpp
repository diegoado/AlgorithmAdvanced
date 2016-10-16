/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: NHAY - A Needle in the Haystack
 * Time limit per test: 5 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <vector>
#include <iostream>

using namespace std;

vector<int> lpsArr;

void computeLPSArray(string pattern, int len) {
    lpsArr[0] = 0;

    for (int i = 1, j = 0; i < len; i++) {
        if (pattern[i] == pattern[j]) {
            lpsArr[i] = ++j;
        }
        else {
            if (j != 0) {
                j = lpsArr[j - 1];
            }
            else {
                lpsArr[i] = 0;
            }
        }
    }
}

void KMPSearch(string pattern, int len, string txt, bool &found) {
    int i = 0, j = 0;
    int n = (int) txt.size();

    // Pre process the pattern (calculate lpsArr[] vector)
    computeLPSArray(pattern, len);

    while (i < n) {
        if (pattern[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == len) {
            printf("%d\n", i - j);
            // Flag to verify if pattern is found in input txt.
            found = true;
            j = lpsArr[j - 1];
        } else if (i < n && pattern[j] != txt[i]) {
            if (j != 0)
                j = lpsArr[j - 1];
            else
                i++;
        }
    }
}

int main() {
    int len;
    string needle, haystack;

    while (scanf("%d", &len) != EOF) {
        cin >> needle >> haystack;

        bool found = false;
        lpsArr = vector<int>(len + 1);

        KMPSearch(needle, len, haystack, found);
        // Print a empty line in the end of test case if a pattern is found in the input text.
        if (found)
            cout << endl;
    }
    return 0;
}


