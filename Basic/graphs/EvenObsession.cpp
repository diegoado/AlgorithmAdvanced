/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1931 - Even Obsession
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <limits.h>
#include <queue>

using namespace std;

class Graph
{
public:
    int V;
    vector<pair<int, int>> * adjacent;

    Graph(int V) {
        this->V = V;
        adjacent = new vector<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int cost) {
        adjacent[u].push_back(make_pair(v, cost));
    }

    Graph transform() {
        Graph graph(V);
        for(int i = 0; i < V; i++)
        {
            for(auto it1 = adjacent[i].begin(); it1 != adjacent[i].end(); it1++)
            {
                if(adjacent[it1->first].size() > 0)
                {
                    for(auto it2 = adjacent[it1->first].begin(); it2 != adjacent[it1->first].end(); it2++)
                    {
                        if(it2->first != i)
                            graph.addEdge(i, it2->first, it1->second + it2->second);
                    }
                }
            }
        }
        return graph;
    }

    int dijkstra(int origin, int destiny)
    {
        int cost[V], visited[V];
        priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i = 0; i < V; i++)
        {
            cost[i] = INT_MAX;
            visited[i] = false;
        }

        cost[origin] = 0;
        pq.push(make_pair(cost[origin], origin));

        while(!pq.empty())
        {
            pair<int, int> p = pq.top();
            int u = p.second;
            pq.pop();

            if(visited[u] == false)
            {
                visited[u] = true;
                for(auto it = adjacent[u].begin(); it != adjacent[u].end(); it++)
                {
                    int v = it->first;
                    int costEdge = it->second;

                    if(cost[v] > (cost[u] + costEdge))
                    {
                        cost[v] = cost[u] + costEdge;
                        pq.push(make_pair(cost[v], v));
                    }
                }
            }
        }
        return cost[destiny];
    }
};

int main() {
    // C is the total number of cities and V is the number of roads.
    int C, V;
    scanf("%d %d", &C, &V);

    // C1, C2 and G indicating that the toll value of the road linking cities C1 and C2 is G.
    int C1, C2, G;
    Graph graph(C);

    for(int i = 0; i < V; i++)
    {
        scanf("%d %d %d", &C1, &C2, &G);
        graph.addEdge(C1-1, C2-1, G);
        graph.addEdge(C2-1, C1-1, G);
    }

    graph = graph.transform();
    // The minimum toll value for Patricia to go from city 1 to city C,or, if that is not possible, the value -1.
    int minToll = graph.dijkstra(0, C-1);

    printf("%d\n", minToll != INT_MAX ? minToll : -1);
    return 0;
}
