/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 56E - E. Domino Principle
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <algorithm>

#define MAX_N 100010

using namespace std;

struct Domino {
    // the domino's coordinate and height
    int x, h;
    // the domino's input index and a count of how many other domains will be overturned when this domino downfall
    int idx, cnt = 1;

} dom[MAX_N];

bool cmp(Domino dom1, Domino dom2) {
    // reverse sort;
    return dom1.x > dom2.x;
}

int falls[MAX_N];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        dom[i].idx = i;
        scanf("%d %d", &dom[i].x, &dom[i].h);
    }
    sort(dom, dom + n, cmp);

    for (int i = 0; i < n; i++) {
        for (int j = i-1; j >= 0; j -= dom[j].cnt) {
            if (dom[j].x > dom[i].x + dom[i].h - 1)
                break;

            dom[i].cnt += dom[j].cnt;
        }
    }
    for (int i = 0; i < n; i++)
        falls[dom[i].idx] = dom[i].cnt;
    for (int i = 0; i < n; i++)
        printf("%d ", falls[i]);

    cout << endl;
    return 0;
}