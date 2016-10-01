/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 245H - H. Queries for number of Palindromes
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define P 27
#define MOD 1000000009
#define MAX_N 5005
// Converts key current character into index use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int) c - (int) 'a')


using namespace std;

typedef long long int ll;

ll base[MAX_N];
ll hashing1[MAX_N], hashing2[MAX_N];

int dp[MAX_N][MAX_N];

void computeHashing(string s, int n) {
    base[0] = 1;
    for (int i = 1; i <= n; i++) {
        hashing1[i] = ((hashing1[i - 1] * P) % MOD + (CHAR_TO_INDEX(s[i - 1]) + 1)) % MOD;
        hashing2[n - i + 1] = ((hashing2[n - i + 2] * P) % MOD + (CHAR_TO_INDEX(s[n - i]) + 1)) % MOD;

        base[i] = (base[i-1] * P) % MOD;
    }
}

int main() {
    string s;
    int q, l, r;

    cin >> s;
    int n = (int) s.length();

    computeHashing(s, n);
    // Count the palindromes and adding in dp to solve futures queries
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ll hc1 = hashing1[j] - ((hashing1[i - 1] * base[j - i + 1]) % MOD);
            if (hc1 < 0)
                hc1 += MOD;
            ll hc2 = hashing2[i] - ((hashing2[j + 1] * base[j - i + 1]) % MOD);
            if (hc2 < 0)
                hc2 += MOD;

            dp[i][j] = hc1 == hc2;
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] += dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
        }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &l, &r);
        printf("%d\n", dp[l][r]);
    }
    return 0;
}
