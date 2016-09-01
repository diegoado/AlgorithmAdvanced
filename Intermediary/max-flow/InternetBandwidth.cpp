/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * UVA - Online Judge
 * Problem: 820 - Internet Bandwidth
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <string.h>
#include <limits.h>
#include <queue>

#define MAX_V 100

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
    int n, s, t, c;
    int u, v, band, test = 1;

    while(cin >> n && n != 0) {
        scanf("%d %d %d", &s, &t, &c);

        for (int k = 0; k < c; k++) {
            scanf("%d %d %d", &u, &v, &band);
            residual_graph[u-1][v-1] += band;
            residual_graph[v-1][u-1] += band;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", test, ford_fulkerson(s-1, t-1));

        test++;
        memset(residual_graph, 0, sizeof(residual_graph));
    }
    return 0;
}