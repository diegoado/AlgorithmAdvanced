/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Code Chef - Educational Initiative
 * Problem: SSTORY - A Story with Strings
 * Time limit per test: 2 seconds
 * Memory limit per test: 50 kilobytes
 * Input: standard input
 * Output: standard output
 */

#include <map>
#include <iostream>

#define MAX_N 500000

using namespace std;

struct state {
    int len, link;
    map<char, int> next;
};

int size, last;
state arr[MAX_N];

inline void sa_init() {
    size = last = 0;
    arr[0].len = 0;
    arr[0].link = -1;
    size++;
}

inline void sa_extend(char c) {
    int p, curr = size++;
    arr[curr].len = arr[last].len + 1;

    for (p = last; p != -1 && !arr[p].next.count(c); p = arr[p].link)
        arr[p].next[c] = curr;
    if (p == -1)
        arr[curr].link = 0;
    else {
        int q = arr[p].next[c];
        if (arr[p].len + 1 == arr[q].len)
            arr[curr].link = q;
        else {
            arr[size].len  = arr[p].len + 1;
            arr[size].next = arr[q].next;
            arr[size].link = arr[q].link;
            for (; p != -1 && arr[p].next[c] == q; p = arr[p].link)
                arr[p].next[c] = size;

            arr[q].link = arr[curr].link = size;
            size++;
        }
    }
    last = curr;
}

string getLcs(string &s, string &t) {
    sa_init();
    for (int i = 0; i < s.length(); i++)
        sa_extend(s[i]);

    int v = 0, l = 0, lcp = 0, sa = 0;
    for (int i = 0; i < t.length(); i++) {
        while (v && ! arr[v].next.count(t[i])) {
            v = arr[v].link;
            l = arr[v].len;
        }
        if (arr[v].next.count(t[i])) {
            v = arr[v].next[t[i]];
            l++;
        }
        if (l > lcp)
            lcp = l,  sa = i;
    }
    return t.substr(sa - lcp + 1, lcp);
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    
    string lcs = getLcs(s1, s2);
    if (lcs.length())
        printf("%s\n%lu\n", lcs.c_str(), lcs.length());
    else
        printf("0\n");

    return 0;
}

