/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1905 - Cops and Robbers
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define Y_WIDTH 5
#define Y_SIZE 25

using namespace std;

string in;
vector<int> visited;

int whoWon()
{
    map<int, vector<int>> graph = {{0, {1, 5}}, {1, {0, 2, 6}}, {2, {1, 3, 7}}, {3, {2, 4, 8}}, {4, {3, 9}},
                                   {5, {0, 6, 10}}, {6, {1, 5, 7, 11}}, {7, {2, 6, 8, 12}}, {8, {3, 7, 9, 13}},
                                   {9, {4, 8, 14}}, {10, {5, 11, 15}}, {11, {6, 10, 12, 16}}, {12, {7, 11, 13, 17}},
                                   {13, {8, 12, 14, 18}}, {14, {9, 13, 19}}, {15, {10, 16, 20}}, {16, {11, 15, 17, 21}},
                                   {17, {12, 16, 18, 22}}, {18, {13, 17, 19, 23}}, {19, {14, 18, 24}}, {20, {15, 21}},
                                   {21, {16, 20, 22}}, {22, {17, 21, 23}}, {23, {18, 22, 24}}, {24, {19, 23}}};

    priority_queue<int> queue;
    queue.push(visited[0]);
    visited[0] = 1;

    while(!queue.empty() and !visited[Y_SIZE - 1]) {
        int u = queue.top();
        queue.pop();

        for(int v = 0; v < graph[u].size(); v++)
        {
            if(!visited[graph[u][v]])
            {
                visited[graph[u][v]] = 1;
                queue.push(graph[u][v]);
            }
        }
    }
    return visited[Y_SIZE - 1];
}

int main() {
    int T;
    int a, b, c, d, e;

    cin >> T;
    while(T--)
    {
        getline(cin, in);
        for(int i = 0; i < Y_WIDTH; i++)
        {
            scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
            visited.push_back(a);
            visited.push_back(b);
            visited.push_back(c);
            visited.push_back(d);
            visited.push_back(e);
        }

        if(visited[Y_SIZE - 1] || !whoWon())
            printf("ROBBERS\n");
        else
            printf("COPS\n");

        visited.clear();
    }
    return 0;
}
