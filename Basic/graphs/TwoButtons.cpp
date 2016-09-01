/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Code forces
 * Problem: 520B - B. Two Buttons
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <queue>
#include <map>

#define MAX_M 10000

using namespace std;

int dijkstra(int origin, int destiny)
{
    map<int, bool> visited;
    queue<pair<int, int>> queue;

    queue.push(pair<int, int>(origin, 0));
    // Node that representing the operation and its respective cost
    pair<int, int> node;

    while(!queue.empty())
    {
        node = queue.front();
        queue.pop();

        if(visited[node.first] or node.first > MAX_M or node.first < 1)
            continue;
        if(node.first == destiny)
            return node.second;

        visited[node.first] = true;
        queue.push(pair<int, int>(node.first - 1, node.second + 1));
        queue.push(pair<int, int>(node.first * 2, node.second + 1));
    }
}

int main() {
    int N, M;

    cin >> N >> M;
    cout << dijkstra(N, M) << endl;
    return 0;
}