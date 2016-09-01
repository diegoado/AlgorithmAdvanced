/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * SPOJ - Online Judge
 * Problem: PT07Y - Is it a tree
 * Time limit per test: 0.166 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isTree;
int visited[10001];
map<int, vector<int>> graph;

void dfs(int v, int parent)
{
    visited[v] = 1;
    for(int u : graph[v])
    {
        if(!visited[u])
            dfs(u, v);
        else if(visited[u] and u != parent)
            isTree = false;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    int u, v;
    for(int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    isTree = true;
    dfs(1, 0);

    for(int j = 1; j <= N; j++) {
        if(!visited[j]) isTree = false;
    }

    if(isTree)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}