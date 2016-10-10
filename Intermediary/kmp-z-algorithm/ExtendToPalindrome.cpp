/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: EPALIN - Extend to Palindrome
 * Time limit per test: 0.450 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include<iostream>

#define MAX_N 100005
#define optimize_io ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

int lspArr[2 * MAX_N];

int prepareLPSArray(string pattern) {
    int len = (int) pattern.length();

    for (int j = 0, i = 1; i < len; i++) {
        if (pattern[i] == pattern[j]) {
            lspArr[i] = j + 1;
            j++;
        } else {
            while (true) {
                if (j == 0 || pattern[j] == pattern[i]) {
                    break;
                }
                j = lspArr[j-1];
            }
            if (pattern[j] == pattern[i]) {
                lspArr[i] = j + 1;
                j++;
            } else {
                lspArr[i] = 0;
            }
        }
    }
    return lspArr[len - 1];
}

string extendToPalindrome(string s){
    string res = s;
    string revS = string(s.rbegin(), s.rend());

    int lpsLen = (int )s.length() - prepareLPSArray(revS + '#' + s);
    for(int i = lpsLen - 1; i >= 0; i--)
        res.append(1, s[i]);

    return res;
}

int main(){
    optimize_io

    char str[MAX_N];
    while (scanf("%s", str) != EOF) {
        string s = str;
        cout << extendToPalindrome(s) << endl;
    }
    return 0;
}