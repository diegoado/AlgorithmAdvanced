/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 2006 - Identifying Tea
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

int main() {
    unsigned int T;
    unsigned int tea, response = 0;

    cin >> T;
    for(int i = 0; i < 5; i++)
    {
        cin >> tea;
        if(T == tea)
        {
            response++;
        }
    }
    cout << response << endl;
    return 0;
}
