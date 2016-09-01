/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 350B - B. Resort
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <vector>
#include <iostream>

using namespace std;

struct Resort
{
    int type = 0;
    int parent = 0;
    vector<int> path;

    bool isValid = true;
};

int main() {
    // The number of objects (a hotel or a mountain) in the resort.
    unsigned int N;

    cin >> N;
    Resort resort[N+1];

    for(int i = 1; i <= N; i++)
    {
        cin >> resort[i].type;
    }
    for(int j = 1; j <= N; j++)
    {
        cin >> resort[j].parent;
        resort[resort[j].parent].path.push_back(j);

        if(resort[resort[j].parent].path.size() > 1)
        {
            resort[resort[j].parent].isValid = false;
        }
    }

    // K is the maximum possible path length for Valera.
    int K = 0;
    int length = 0;
    resort[0].isValid = false;
    // The path contains integers v1, v2, ..., vk that are a possible solution for Valera.
    vector<int> path, solution;

    for(int l = N; l >= 1; l--) {
        if(resort[l].type == 1)
        {
            length++;
            path.push_back(l);
            Resort V = resort[l];

            while(resort[V.parent].isValid)
            {
                length++;
                path.push_back(V.parent);

                V = resort[V.parent];
            }
            if(length > K)
            {
                K = length;
                solution = path;
            }

            length = 0;
            path.clear();
        }
    }
    // Print output format
    cout << K << endl;
    for(int m = K-1; m > 0; m--)
    {
        cout << solution[m] << " ";
    }
    cout << solution[0] << endl;
    return 0;
}
