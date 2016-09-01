/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * UVA - Online Judge
 * Problem: 11506 - Angry Programmer
 * Time limit per test: 4 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>

#define MAX_V 99

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
int ford_fulkerson(int s, int t)
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
    int n, w, i, j, c;

    while (cin >> n >> w, n || w) {
        for (int k = 0; k < n - 2; k++) {
            scanf("%d %d", &i, &c);
            residual_graph[(i - 1) * 2 - 1][(i - 1) * 2] = c;
        }
        for (int k = 0; k < w; k++) {
            scanf("%d %d %d", &i, &j, &c);

            if (i == 1 && j == n) {
                residual_graph[i - 1][(n - 2) * 2 + 1] += c;
                residual_graph[(n - 2) * 2 + 1][i - 1] += c;
            } else if (i == 1) {
                residual_graph[i - 1][(j - 1) * 2 - 1] += c;
                residual_graph[(j - 1) * 2][i - 1] += c;
            } else if (j == n) {
                residual_graph[(i - 1) * 2][(n - 2) * 2 + 1] += c;
                residual_graph[(n - 2) * 2 + 1][(i - 1) * 2 - 1] += c;
            } else {
                residual_graph[(i - 1) * 2][(j - 1) * 2 - 1] += c;
                residual_graph[(j - 1) * 2][(i - 1) * 2 - 1] += c;
            }
        }
        printf("%d\n", ford_fulkerson(0, (n - 2) * 2 + 1));
        memset(residual_graph, 0, sizeof(residual_graph));
    }
    return 0;
}
