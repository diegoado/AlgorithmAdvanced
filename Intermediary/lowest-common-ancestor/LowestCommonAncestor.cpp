/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: LCA - Lowest Common Ancestor
 * Time limit per test: 1.113 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <cstdio>
#include <vector>
#include <string.h>

#define LOG 14
#define MAX_N 10000

using namespace std;

// Variable to store the nodes levels.
int level[MAX_N];
// Variable to store the nodes parents.
int parent[MAX_N][LOG];
// Variable to represent a rooted tree to find the furthest node from the root that is an ancestor for both u and v.
vector<int> tree[MAX_N];

void dfs(int u = 0, int p = 0)
{
    for (int i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i];
        if (v != p) {
            level[v] = level[u] + 1;
            parent[v][0] = u;
            dfs(v, u);
        }
    }
}

void create(int n)
{
    memset(parent, -1, sizeof(parent));
    dfs();

    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i < n; i++) {
            if (parent[i][j-1] != -1)
                parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

int lca(int u, int v)
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
    int t, n, m, q, v, w;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++) {
        scanf("%d", &n);
        for (int u = 0; u < n; u++) {
            tree[u].clear();

            scanf("%d", &m);
            for (int j = 0; j < m; j++) {
                scanf("%d", &v);
                tree[u].push_back(v-1);
                tree[v-1].push_back(u);
            }
        }
        create(n);
        scanf("%d", &q);
        printf("Case %d:\n", i);
        for (int k = 0; k < q; k++) {
            scanf("%d %d", &v, &w);
            printf("%d\n", lca(v-1, w-1) + 1);
        }
    }
    return 0;
}