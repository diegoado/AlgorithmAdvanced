/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1152 - Dark Roads
 * Time limit per test: 3 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define ULI unsigned long int

using namespace std;

// A structure to represent a weighted edge in graph
struct Edge
{
    ULI source, destiny, weight;
};

// A structure to represent a connected, undirected and weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    ULI V, E;
    // Graph is represented as an array of edges. Since the graph is
    // undirected, the edge from source to destiny is also edge from destiny
    // to source. Both are counted as 1 edge here.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges.
struct Graph* createGraph(ULI V, ULI E)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));

    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*) malloc(graph->E * sizeof(struct Edge));

    return graph;
}

// A structure to represent a subset for union-find
struct Subset
{
    ULI parent, rank;
};

// A utility function to find set of an element i
ULI find(struct Subset subsets[], ULI i)
{
    // find root and make root as parent of i (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

// A function that does union of two sets of x and y
void unionFind(struct Subset subsets[], int x, int y)
{
    int xRoot = find(subsets, x);
    int yRoot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    if (subsets[xRoot].rank < subsets[yRoot].rank)
        subsets[xRoot].parent = yRoot;
    else if (subsets[xRoot].rank > subsets[yRoot].rank)
        subsets[yRoot].parent = xRoot;
    // If ranks are same, then make one as root and increment
    else
    {
        subsets[yRoot].parent = xRoot;
        subsets[xRoot].rank++;
    }
}

// Compare two edges according to their weights.
int cmp(const void* a, const void* b)
{
    struct Edge* one = (struct Edge*) a;
    struct Edge* two = (struct Edge*) b;

    return one->weight > two->weight;
}

// The main function to construct MST using Kruskal's algorithm
ULI kruskal(struct Graph* graph)
{
    int V = graph->V;
    struct Edge result[V]; // This will store the resultant MST
    int e = 0; // An index variable, used for result[]
    int i = 0; // An index variable, used for sorted edges

    // Step 1:  Sort all the edges in non-decreasing order of their weight
    // If we are not allowed to change the given graph, we can create a copy of
    // array of edges
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), cmp);

    // Allocate memory for creating V subsets
    struct Subset *subsets = (struct Subset*) malloc(V * sizeof(struct Subset));

    // Create V subsets with single elements
    for(int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while(e < V - 1)
    {
        // Step 2: Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.source);
        int y = find(subsets, next_edge.destiny);

        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if(x != y)
        {
            result[e++] = next_edge;
            unionFind(subsets, x, y);
        }
        // Else discard the next_edge
    }
    // Weight sum minimum-spanning-tree of graph
    ULI sum = 0;

    for(i = 0; i < e; ++i)
        sum += result[i].weight;

    return sum;
}


int main() {
    // M are the number of junctions in Byteland and N the number of roads in Byteland.
    ULI M, N;

    while(true)
    {
        scanf("%lu %lu", &M, &N);

        // The input is terminated by m=n=0.
        if(M == 0 and N == 0) break;
        // X, Y and Z specifying that there will be a bidirectional road between x and y with length z meters.
        ULI X, Y, Z;
        struct Graph* graph = createGraph(M, N);
        // Sum of cost to illuminate all roads during one night.
        ULI sum = 0;
        for(int i = 0; i < N; ++i)
        {
            scanf("%lu %lu %lu", &X, &Y, &Z);
            sum += Z;

            graph->edge[i].source = X;
            graph->edge[i].destiny = Y;
            graph->edge[i].weight = Z;
        }
        // Maximum daily amount of money the government of Byteland can save, without making their inhabitants feel unsafe.
        printf("%lu\n", sum - kruskal(graph));
    }
    return 0;
}