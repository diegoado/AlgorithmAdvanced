/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 587C - C. Duff in the Army
 * Time limit per test: 4 seconds
 * Memory limit per test: 512 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <bits/stdc++.h>

#define LOG 18
#define MAX_P 10
#define MAX_N 100000

using namespace std;

// Variable to store the nodes levels.
int level[MAX_N];
// Variable to store the nodes parents.
int parent[MAX_N][LOG];
// Variable to store the cities between u and v
vector<int> cities[MAX_N];
// Variable to represent a rooted tree to find the furthest node from the root that is an ancestor for both u and v.
vector<int> tree[MAX_N];
// Variable to represent the people living at the i-th city
vector<int> people[MAX_N][LOG];

vector<int> merge(vector<int> &u, vector<int> &v) {
    vector<int> result;
    int i = 0, j = 0, k = 0;

    while (i < MAX_P and j < u.size() and k < v.size()) {
        if (u[j] < v[k]) {
            if ((i and u[j] != result[i - 1]) or !i) {
                result.push_back(u[j]);
                i++;
            }
            j++;
        } else {
            if ((i and v[k] != result[i - 1]) or !i) {
                result.push_back(v[k]);
                i++;
            }
            k++;
        }
    }
    while (i < MAX_P and j < u.size()) {
        if ((i and u[j] != result[i - 1]) or !i) {
            result.push_back(u[j]);
            i++;
        }
        j++;
    }
    while (i < MAX_P and k < v.size()) {
        if ((i and v[k] != result[i - 1]) or !i) {
            result.push_back(v[k]);
            i++;
        }
        k++;
    }
    return result;
}

void dfs(int u = 0, int p = 0)
{
    for (int i = 0; i < tree[u].size(); i++) {
        int v = tree[u][i];
        if (v != p) {
            parent[v][0] = u;
            level[v] = level[u] + 1;
            people[v][0] = cities[u];
            dfs(v, u);
        }
    }
}

void create(int n)
{
    dfs();
    for (int j = 1; (1 << j) < n; j++) {
        for (int i = 0; i < n; i++) {
            people[i][j] = merge(people[i][j-1], people[parent[i][j-1]][j-1]);
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

vector<int> query(int u, int v)
{
    int l = 1;
    if (level[u] < level[v]) {
        swap(u, v);
    }
    while (level[u] >= (1 << l)) {
        l++;
    }
    l--;
    vector<int> k = merge(cities[u], cities[v]);
    for (int i = l; i >= 0; i--) {
        if (level[u] - (1 << i) >= level[v]) {
            k = merge(k ,people[u][i]);
            u = parent[u][i];
        }
    }
    if (u == v) {
        return k;
    }
    for (int i = l; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            k = merge(k, people[u][i]);
            k = merge(k, people[v][i]);
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    k = merge(k, people[u][0]);
    k = merge(k, people[v][0]);
    return k;
}

int main() {
    int n, m, q, u, v, c , a;
    scanf("%d %d %d", &n, &m, &q);

    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u, &v);
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &c);
        cities[c-1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        sort(cities[i].begin(), cities[i].end());
    }

    create(n);
    while (q--) {
        scanf("%d %d %d", &u, &v, &a);
        vector<int> result = query(u-1, v-1);

        printf("%d", min(a, (int) result.size()));
        for (int i = 0; i < a and i < result.size(); i++) {
            printf(" %d", result[i] + 1);
        }
        printf("\n");
    }
    return 0;
}