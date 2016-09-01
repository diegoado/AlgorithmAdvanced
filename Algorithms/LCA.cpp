#include <vector>
#include <string.h>

using namespace std;

// Variable to store the nodes levels.
int* level;
// Variable to store the nodes parents.
int** parent;
// Variable to represent a rooted tree to find the furthest node from the root that is an ancestor for both u and v.
vector<int>* tree;

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
