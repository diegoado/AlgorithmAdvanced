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
#include <algorithm>

#define MAX_N 100010

using namespace std;

int zArr[MAX_N];

void computeZArr(string str, int n) {
    int l, r, k;

    l = r = 0;
    for (int i = 1; i < n; ++i) {
        if (i > r) {
            l = r = i;

            while (r < n && str[r - l] == str[r])
                r++;

            zArr[i] = r - l;
            r--;
        }
        else {
            k = i - l;

            if (zArr[k] < r - i + 1) {
                zArr[i] = zArr[k];
            }
            else {
                l = i;
                while (r < n && str[r - l] == str[r])
                    r++;

                zArr[i] = r - l;
                r--;
            }
        }
    }
}

int main() {
    int t;
    string s;

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        cin >> s;
        reverse(s.begin(), s.end());

        int slen = (int) s.size();
        computeZArr(s, slen);

        int n, q;
        zArr[0] = (int) s.size();

        scanf("%d",&q);
        for(int j = 0; j < q; j++) {
            scanf("%d", &n);
            printf("%d\n", zArr[slen - n]);
        }
    }
    return 0;
}