/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1135 - Ants Colony
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <vector>
#include <iostream>

#define LOG 15
#define MAX_N 20000

using namespace std;

typedef pair<int, int> pii;

// Variable to store the nodes levels.
int level[MAX_N];
// Variable to store the nodes parents.
int path[MAX_N][LOG];
// Variable to represent a maximum spanning tree to find the best path to u from v.
vector<pii> tree[MAX_N];

// A structure to represent a weighted edge in graph
struct Edge
{
    int source, destiny, weight;
};

// A structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges. Since the graph is undirected,
    // the edge from src to destiny is also edge from destiny to source. Both are counted as 1 edge here.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));
    return graph;
}

// A structure to represent a subset for union-find
struct subset
{
    int parent;
    int rank;
};

// A utility function to find set of an element i
// (uses path compression technique)
int find(struct subset subsets[], int i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of x and y (uses union by rank)
void Union(struct subset subsets[], int x, int y)
{
    x = find(subsets, x);
    y = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[x].rank < subsets[y].rank)
        subsets[x].parent = y;
    else if (subsets[x].rank > subsets[y].rank)
        subsets[y].parent = x;
    // If ranks are same, then make one as root and increment its rank by one
    else {
        subsets[y].parent = x;
        subsets[x].rank++;
    }
}

// Compare two edges according to their weights. Used in qsort() for sorting an array of edges
int cmp(const void *a, const void *b)
{
    struct Edge *u = (struct Edge *) a;
    struct Edge *v = (struct Edge *) b;

    return u->weight < v->weight;
}

// The main function to construct MST using Kruskal's algorithm
void kruskalMST(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V];  // This will store the resultant MST
    int e = 0;  // An index variable, used for result[]
    int i = 0;  // An index variable, used for sorted edges

    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), cmp);

    // Allocate memory for creating V subsets
    struct subset *subsets =
            (struct subset*) malloc(V * sizeof(struct subset) );

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.source);
        int y = find(subsets, next_edge.destiny);

        // If including this edge does't cause cycle, include it in result and increment the index of result
        // for next edge. Else discard the next edge.
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    for (i = 0; i < e; ++i) {
        tree[result[i].source].push_back(make_pair(result[i].destiny, result[i].weight));
        tree[result[i].destiny].push_back(make_pair(result[i].source, result[i].weight));
    }
    return;
}

int main() {
    int n, m, s, u, v, p;
    while (!cin.eof()) {
        cin >> n >> m >> s;

        struct Graph *graph = createGraph(n, m);

        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &p);
            graph->edge[i].source  = u-1;
            graph->edge[i].destiny = v-1;
            graph->edge[i].weight  = p;
        }
        kruskalMST(graph);
        while (s--) {
            scanf("%d %d", &u, &v);
        }
        for (int j = 0; j < n; j++) {
            tree[j].clear();
        }
    }
    return 0;
}
