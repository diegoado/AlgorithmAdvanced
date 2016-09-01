/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 501B - B. Misha and Changing Handles
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <map>
#include <iostream>

using namespace std;

int main() {
    // The number of handle change requests.
    int Q;
    // Old handle and new handle of a user
    string old, recent;
    // Map contains the old and the new handles of the users and the changes historic.
    map<string, string> request, historic;

    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        cin >> old >> recent;
        if(not historic.count(old))
        {
            request[old] = recent;
            historic[recent] = old;
        }
        else
        {
            request[historic[old]] = recent;
            historic[recent] = historic[old];
        }
    }

    cout << request.size() << endl;
    for(auto it = request.begin(); it != request.end() ; it++)
    {
        cout<< it->first << " " << it->second << endl;
    }
    return 0;
}

