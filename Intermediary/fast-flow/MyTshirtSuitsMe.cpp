/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * UVA - Online Judge
 * Problem: 11045 - My T-shirt Suits me
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <queue>
#include <climits>
#include <iostream>
#include <string.h>

#define SINK 37
#define MAX_V 38
#define T_SHIRTS 6

using namespace std;

bool mark[MAX_V];
int  path[MAX_V];
int graph[MAX_V][MAX_V];

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
            if (!mark[v] && graph[u][v] > 0) {
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
int ford_fulkerson(int s = 0, int t = SINK)
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
            path_flow = min(path_flow, graph[u][v]);
        }
        // Update residual capacities of the edges and reverse edges along the path
        for (v = t; v != s; v = path[v]) {
            u = path[v];
            graph[u][v] -= path_flow;
            graph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int shirt_index(char *size) {
    if (strcmp(size, "XXL") == 0)
        return 1;
    else if (strcmp(size, "XL") == 0)
        return 2;
    else if (strcmp(size, "L") == 0)
        return 3;
    else if (strcmp(size, "M") == 0)
        return 4;
    else if (strcmp(size, "S") == 0)
        return 5;
    else
        return 6;
}

int main() {
    int t, n, m;
    scanf("%d", &t);

    char sz[4];
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);

        for (int j = 1; j <= T_SHIRTS; j++) {
            graph[0][j] = n/ T_SHIRTS;
        }
        for (int j = 7; j < 7 + m; j++) {
            scanf("%s", sz);
            graph[shirt_index(sz)][j] = 1;

            scanf("%s", sz);
            graph[shirt_index(sz)][j] = 1;

            graph[j][SINK] = 1;
        }
        if (ford_fulkerson() == m)
            printf("YES\n");
        else
            printf("NO\n");

        memset(graph, 0, sizeof(graph));
    }
    return 0;
}
