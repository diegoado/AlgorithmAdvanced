/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: MTOTALF - Total Flow
 * Time limit per test: 0.252 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <limits.h>
#include <iostream>
#include <string.h>
#include <queue>

#define MAX_V 52

using namespace std;

bool mark[MAX_V];
int  path[MAX_V];
int residual_graph[MAX_V][MAX_V];

// Returns true if there is a path from source 's' to sink 't' in residual graph.
// Also fills path[] to store the path.
bool bfs(int s, int t)
{
    // Create a visited array and mark all vertices as not visited
    memset(mark, 0, sizeof(mark));
    // Create a q, enqueue source vertex and mark source vertex as visited
    queue <int> q;

    q.push(s);
    path[s] = -1;
    mark[s] = true;

    // Standard BFS Loop
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v=0; v < MAX_V; v++) {
            if (!mark[v] && residual_graph[u][v] > 0) {
                q.push(v);
                path[v] = u;
                mark[v] = true;
            }
        }
    }
    // If we reached sink in BFS starting from source, then return true, else false
    return mark[t];
}

// Returns tne maximum flow from s to t in the given graph
int ford_fulkerson(int s = 0, int t = 25)
{
    int u, v;
    // There is no flow initially
    int max_flow = 0, path_flow;
    // Augment the flow while there is path from source to sink
    while (bfs(s, t)) {
        // Find minimum residual flow of the edges along the path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        path_flow = INT_MAX;
        for (v = t; v != s; v = path[v]) {
            u = path[v];
            path_flow = min(path_flow, residual_graph[u][v]);
        }
        // Update residual capacities of the edges and reverse edges along the path
        for (v = t; v != s; v = path[v]) {
            u = path[v];
            residual_graph[u][v] -= path_flow;
            residual_graph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main() {
    int n;
    scanf("%d", &n);

    char s, d;
    int i, j, f;

    for (int k = 0; k < n; k++ ) {
        cin >> s >> d >> f;

        (s >= 'A' && s <= 'Z') ? i = s - 'A' : i = s - 'a' + 26;
        (d >= 'A' && d <= 'Z') ? j = d - 'A' : j = d - 'a' + 26;

        residual_graph[i][j] += f;
    }
    printf("%d\n", ford_fulkerson());
    return 0;
}