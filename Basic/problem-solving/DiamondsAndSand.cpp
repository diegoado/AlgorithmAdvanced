/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1069 - Diamonds and Sand
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
    // Number of test cases
    int N;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        // The input representing the peaces of diamonds and particles of sand.
        string S;
        // The amount of diamonds that can be extracted in each test case.
        int extracts = 0;
        // Stack that contains the left peace to form a new diamond.
        stack<char> diamonds;

        cin >> S;
        for(int j = 0; j < S.size(); j++)
        {
           if(S[j] == '<')
           {
               diamonds.push('<');
           }
           else if(S[j] == '>' and not diamonds.empty())
           {
               extracts++;
               diamonds.pop();
           }
        }
        cout << extracts << endl;
    }
    return 0;
}