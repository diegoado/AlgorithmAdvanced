/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Code Forces
 * Problem: D. 217 - D. Good Substrings
 * Time limit per test: 2 seconds
 * Memory limit per test: 512 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <set>
#include <iostream>

#define P1 27
#define P2 29
#define MOD1 1000000009LL
#define MOD2 1000000007LL

typedef long long int ll;

using namespace std;

char letters[26];
set<pair<ll, ll>> ans;

int main() {
    int k;
    string s;

    cin >> s;
    scanf("%s", letters);
    scanf("%d", &k);

    for (int i = 0; i < s.size(); i++) {
        int bad = 0;
        ll  hc1 = 0, hc2 = 0;
        for (int j = i; j < s.size(); j++) {
            // Here needs calculate two hashing code to avoid conflicts between strings
            hc1 = ((hc1 * P1) % MOD1 + (s[j] - 96)) % MOD1;
            hc2 = ((hc2 * P2) % MOD2 + (s[j] - 96)) % MOD2;

            bad += letters[s[j] - 97] == '0';
            if (bad <= k)
                ans.insert(make_pair(hc1, hc2));
        }
    }
    printf("%lu\n", ans.size());
    return 0;
}