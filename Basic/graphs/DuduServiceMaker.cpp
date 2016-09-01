/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1610 - Dudu Service Maker
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <map>
#include <set>

using namespace std;

map<int, set<int>> graph;

bool cycleUtil(int v, int visited[], int stack[])
{
    if(!visited[v]) {
        stack[v] = visited[v] = 1;

        for(auto u = graph[v].begin(); u != graph[v].end(); u++)
        {
            if(!visited[*u] and cycleUtil(*u, visited, stack))
                return true;
            else if(stack[*u])
                return true;
        }
    }
    stack[v] = 0;
    return false;
}

bool hasCycle(int vertices)
{
    int visited[vertices+1], stack[vertices+1];

    visited[0] = stack[0] = 1;
    for(int j = 1; j <= vertices; ++j)
        stack[j] = visited[j] = 0;

    for(int v = 1; v < vertices; v++)
    {
        if(cycleUtil(v, visited, stack)) return true;
    }
    return false;
}

int main() {
    int T;
    int N, M;

    cin >> T;
    while(T--)
    {
        int u, v;
        cin >> N >> M;
        for(int i = 0; i < M; i++)
        {
            cin >> u >> v;
            graph[u].insert(v);
        }
        if(hasCycle(N))
            cout << "SIM" << endl;
        else
            cout << "NAO" << endl;

        graph.clear();
    }
    return 0;
}
