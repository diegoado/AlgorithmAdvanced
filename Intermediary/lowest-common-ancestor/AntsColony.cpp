/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1135 - Ants Colony
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <vector>
#include <string.h>
#include <iostream>

#define LOG 17
#define MAX_N 100000

using namespace std;

typedef pair<int, int> pii;
typedef long long int llong;

// Variable to store the nodes levels.
int level[MAX_N];
// Variable to store the nodes costs from 0 to u.
llong costs[MAX_N];
// Variable to store the nodes parents.
int parent[MAX_N][LOG];
// Variable to represent a rooted tree to find the furthest node from the root that is an ancestor for both u and v.
vector<pii> tree[MAX_N];

void dfs(int u = 0)
{
    for (int i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i].first, c = tree[u][i].second;
        if (costs[v] == -1) {
            costs[v] = costs[u] + c;
            level[v] = level[u] + 1;
            dfs(v);
        }
    }
}

void create(int n)
{
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i < n; i++) {
            if (parent[i][j-1] != -1)
                parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
    costs[0] = level[0] = 0;
    dfs();
}

int query(int u, int v)
{
    int l = 1;
    if (level[u] < level[v]) {
        swap(u, v);
    }
    while (level[u] >= (1 << l)) {
        l++;
    }
    l--;
    for (int i = l; i >= 0; i--) {
        if (level[u] - (1 << i) >= level[v]) {
            u = parent[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = l; i >= 0; i--) {
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    llong c;
    int n, v, q, s, t;

    while (cin >> n && n != 0) {
        memset(costs,  -1, sizeof (costs));
        memset(parent, -1, sizeof(parent));

        for (int u = 1; u < n; u++) {
            scanf("%d %lld", &v, &c);
            parent[u][0] = v;
            tree[u].push_back(make_pair(v, c));
            tree[v].push_back(make_pair(u, c));
        }
        create(n);
        scanf("%d", &q);
        for (int i = 0; i < q - 1; i++) {
            scanf("%d %d", &s, &t);

            int lca = query(s, t);
            printf("%lld ", costs[s] + costs[t] - 2 * costs[lca]);
        }
        scanf("%d %d", &s, &t);

        int lca = query(s, t);
        printf("%lld\n", costs[s] + costs[t] - 2 * costs[lca]);
        // Cleaning the lca tree and auxiliaries variables to compute nodes costs.
        for (int i = 0; i < n; i++)
            tree[i].clear();
    }
    return 0;
}