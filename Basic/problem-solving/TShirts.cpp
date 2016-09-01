/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1258 - T-Shirts
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

struct Order {
    char size;
    string name, color;

    bool operator<(Order other) const
    {
        if(color != other.color)
            return color < other.color;
        if(size != other.size)
            return size > other.size;
        return name < other.name;
    }
};

int main() {
    // N indicates the amount of shirts that will be made for that class.
    int N;
    // Check if a test case is the one.
    bool first = true;

    while(true)
    {
        cin >> N;
        if(N == 0) break;

        if(first)
            first = false;
        else
            cout << endl;
        // Input data that contains information of each shirt.
        string in[2*N+1];
        for(int i = 0; i < 2*N+1; i++)
        {
            getline(cin, in[i]);
        }

        int j = -1;
        // Orders of T-shirts to be sorted by color, size and onw name.
        Order shirts[N];
        for(int k = 1; k < 2*N+1; k +=2)
        {
            j++;
            shirts[j].name = in[k];

            istringstream iss(in[k+1]);
            iss >> shirts[j].color >> shirts[j].size;
        }
        sort(shirts, shirts + N);
        for(int j = 0; j < N; j++)
        {
            cout << shirts[j].color << ' ' << shirts[j].size << ' ' << shirts[j].name << endl;
        }
    }
    return 0;
}
