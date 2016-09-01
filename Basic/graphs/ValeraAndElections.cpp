/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Code forces
 * Problem: 369C - C. Valera and Elections
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <vector>
#include <map>

#define MAX_N 100001

using namespace std;

vector<int> subset;
map<int, vector<int>> graph;
int visited[MAX_N], type[MAX_N];

int dfs(int u, int t)
{
    int sum = 0;
    visited[u] = 1;
    for(int v = 0; v < graph[u].size(); v++)
    {
        if(visited[graph[u][v]])
            continue;
        else if(type[graph[u][v]])
            sum += dfs(graph[u][v], 1);
        else
            sum += dfs(graph[u][v], 0);
    }
    if(t and sum == 0) {
        subset.push_back(u);
        return 1;
    }
    return sum;
}

int main() {
    int N;
    cin >> N;

    int u, v, t;
    for(int i = 0; i < N-1; i++)
    {
        cin >> u >> v >> t;
        graph[u].push_back(v);
        graph[v].push_back(u);

        if(t == 2)
            type[u] = type[v] = 1;
    }

    cout << dfs(1, type[0]) << endl;
    for(int i = 0; i < subset.size(); i++)
    {
        cout << subset[i] << " ";
    }
    cout << endl;
    return 0;
}