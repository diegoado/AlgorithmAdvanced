/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1861 - Hall of Murderers
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <map>
#include <iostream>

using namespace std;

int main() {
    // The killer and the name of who has been killed.
    string killer, murdered;
    // The map that contains the killer's name and the your amount of murdered
    map<string, int> murders;

    cin >> killer >> murdered;
    while(!cin.eof())
    {
        if(murders.count(killer) and murders[killer] != -1)
        {
            murders[killer]++;
        }
        else if(not murders.count(killer))
        {
            murders[killer] = 1;
        }

        murders[murdered] = -1;
        cin >> killer >> murdered;

    }
    cout << "HALL OF MURDERERS" << endl;
    for(auto it = murders.begin(); it != murders.end(); it++)
    {
        if(it->second != -1)
            cout << it->first << " " << it->second << endl;
    }
    return 0;
}