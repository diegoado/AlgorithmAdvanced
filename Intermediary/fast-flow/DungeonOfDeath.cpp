/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: QUEST4 - Dungeon of Death
 * Time limit per test: 1 second
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <vector>
#include <cstdio>
#include <string.h>

#define MAX_V 121

using namespace std;

struct BipartiteGraph {

    int match[MAX_V];
    bool seen[MAX_V];
    vector<int> graph[MAX_V];

    void clean() {
        for (int i = 0; i < MAX_V; i++)
            graph[i].clear();
    }

    void add_edge(int u, int v){
        graph[u].push_back(v);
    }

    bool bpm(int u) {
        for (int i = (int) graph[u].size() - 1; i >= 0; i--) {
            int v = graph[u][i];

            if (!seen[v]) {
                seen[v] = true;
                if (match[v] == -1 || bpm(match[v])){
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }

    int maxBPM() {
        int result = 0;
        memset(match, -1, sizeof(match));

        for (int i = 0; i < MAX_V; i++) {
            memset(seen, 0, sizeof(seen));
            result += bpm(i);
        }
        return result;
    }
};


int main() {
    int t;
    int n, x, y;
    scanf("%d", &t);

    BipartiteGraph bpGraph;
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            scanf("%d %d", &x, &y);
            bpGraph.add_edge(x, y);
        }
        printf("%d\n", bpGraph.maxBPM());
        bpGraph.clean();
    }
    return 0;
}
