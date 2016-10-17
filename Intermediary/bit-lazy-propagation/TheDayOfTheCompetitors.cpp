/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: NICEDAY - The Day of the Competitors
 * Time limit per test: 0.109 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <climits>
#include <iostream>
#include <algorithm>

#define MAX_N 100010

using namespace std;

int bit[MAX_N];

void update(int pos, int val, int MAX) {
    while (pos <= MAX) {
        bit[pos] = min(bit[pos], val);
        pos += (pos & -pos);
    }
}

int verify(int pos) {
    int check = INT_MAX;

    while (pos) {
        check = min(bit[pos] , check);
        pos -= (pos & -pos);
    }

    return check;
}

struct Rank {
    int first, second, third;
};

bool cmp(const Rank &a , const Rank &b) {
    return a.first == b.first ? (a.second == b.second ? a.third < b.third : a.second < b.second ) : a.first < b.first;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int k = 0; k < t; k++) {
        int n;
        scanf("%d", &n);

        Rank arr[n + 9];
        for (int i = 0;i < n; i++)
            scanf("%d %d %d", &arr[i].first, &arr[i].second, &arr[i].third);

        sort(arr, arr + n, cmp);

        int res = 0;
        fill(bit, bit + n + 9, INT_MAX);
        for (int i = 0; i<n ; i++) {
            if (verify(arr[i].second) > arr[i].third)
                res++;

            update(arr[i].second,arr[i].third, n + 9);
        }
        printf("%d\n",res);
    }
    return 0;
}