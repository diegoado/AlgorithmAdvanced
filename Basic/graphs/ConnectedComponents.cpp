/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1082 - Connected Components
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <algorithm>
#include <iostream>
#include <string.h>
#include <map>

using namespace std;

int visited[26];
vector<char> node;

void dfs(map<char, vector<char>> graph, char v)
{
    node.push_back(v);
    visited[v - 'a'] = 1;

    for(char u : graph[v])
    {
        if(!visited[u - 'a']) dfs(graph, u);
    }
}

int main() {
    int N;
    cin >> N;

    char u, v;
    int vertex, edges, cases = 1;
    map<char, vector<char>> graph;

    while(N--)
    {
        cin >> vertex >> edges;
        for(int node = 0; node < vertex; node++)
            graph[node + 'a'] = {};
        for(int i = 0; i < edges; i++)
        {
            cin >> u >> v;
            graph[v].push_back(u);
            graph[u].push_back(v);
        }

        int components = 0;
        cout << "Case #" << cases << ':' << endl;
        for(int j = 0; j < vertex; j++)
        {
            if(!visited[j]) {
                components++;
                dfs(graph, j + 'a');

                sort(node.begin(), node.end());
                for(int j = 0; j < node.size(); j++)
                    cout << node[j] << ',';

                cout << endl;
                node.clear();
            }
        }
        cout << components << " connected components" << endl;
        cout << endl;
        memset(visited, 0, sizeof(visited));

        graph.clear();
        cases++;
    }
    return 0;
}
