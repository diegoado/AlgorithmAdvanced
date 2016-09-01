/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Spoj - Online Judge
 * Problem: FASTFLOW - Fast Maximum Flow
 * Time limit per test: 2.766 seconds
 * Memory limit per test: 1536 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long int llong;

struct Dinic {
    const static int MAX_N = 5000;
    const static int INF = (int) 1e9 + 1;

    struct Edge {
        int to;
        int rev, cap, flow;

        // Struct constructor
        Edge(int to, int rev, int cap, int flow): to(to), rev(rev), cap(cap), flow(flow) {}
    };
    int src = 0, dest, n;
    int pos[MAX_N], d[MAX_N];

    vector<Edge> graph[MAX_N];

    Dinic(int n): dest(n-1), n(n) {}

    void add_edge(int u, int v, int cap) {
        Edge l = Edge(v, (int) graph[v].size(), cap, 0);
        Edge r = Edge(u, (int) graph[u].size(), 0, 0);

        graph[u].push_back(l);
        graph[v].push_back(r);
    }

    bool bfs() {
        queue<int> q;
        for (int i = 0; i < n; i++)
            d[i] = -1;

        d[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < graph[u].size(); i++) {
                Edge e = graph[u][i];
                if (d[e.to] == -1 && e.cap > e.flow) {
                    d[e.to] = d[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return d[dest] != -1;
    }

    int dfs(int u, int flow) {
        if (!flow)
            return 0;
        if (u == dest)
            return flow;

        for (; pos[u] < graph[u].size(); pos[u]++) {
            Edge &e = graph[u][pos[u]];
            if (d[u] + 1 == d[e.to]) {
                int f = dfs(e.to, min(flow, e.cap - e.flow));
                if (f) {
                    e.flow += f;
                    graph[e.to][e.rev].flow -= f;
                    return f;
                }
            }
        }
        return 0;
    }

    llong flow() {
        llong max_flow = 0;

        while (bfs()) {
            for (int i = 0; i < n; i++) {
                pos[i] = 0;
            }
            while (int f = dfs(0, INF)) {
                max_flow += f;
            }
        }
        return max_flow;
    }
};

int main() {
    int n, m, u, v, c;
    scanf("%d %d", &n, &m);

    Dinic dinic = Dinic(n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &c);
        dinic.add_edge(u - 1, v - 1, c);
        dinic.add_edge(v - 1, u - 1, c);
    }
    printf("%lld\n", dinic.flow());
    return 0;
}