/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 518B - B. Tanya and Postcard
 * Time limit per test: 2 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <map>

using namespace std;

int main() {

    // The text of Tanya's message and the text written in the newspaper.
    string S, T;
    cin >> S >> T;
    // The newspaper contains uppercase and lowercase English letters.
    map<char, int> newspaper;
    for(int i = 0; i< T.size(); i++)
    {
        newspaper[T[i]]++;
    }

    /*
     * The number of times Tanya shouts "YAY!" while making the message
     * The number of times Tanya says "WHOOPS" while making the message.
     */
    unsigned int yay = 0, whoops = 0;

    for(int j = 0; j < S.size(); j++)
    {
        if(newspaper.count(S[j]) and newspaper[S[j]] > 0)
        {
            yay += 1;
            newspaper[S[j]]--;

            S[j] = '*';
        }
    }
    for (int k = 0; k < S.size(); k++)
    {
        char swap = isupper(S[k]) ? tolower(S[k]) : toupper(S[k]);
        if(S[k] == '*')
        {
            continue;
        } else if(newspaper.count(swap) and newspaper[swap] > 0)
        {
            whoops += 1;
            newspaper[swap]--;
        }
    }
    cout << yay << " " << whoops << endl;
    return 0;
}