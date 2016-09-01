/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI Online Judge
 * Problem: 1802 [P1] - Books Catalog
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <vector>
#include <iostream>
#include <algorithm>

#define PORTUGUESE 0
#define PHYSICS 2
#define CHEMISTRY 3
#define BIOLOGY 4
#define DISCIPLINES 5

using namespace std;

struct Catalog
{
    int P, M, F, Q, B;

    vector<int> math;
    vector<int> biology;
    vector<int> physics;
    vector<int> chemistry;
    vector<int> portuguese;

    vector<int> getCatalog();
};

int cmp(int b1, int b2)
{
    return b1 > b2;
}

vector<int> Catalog::getCatalog()
{
    vector<int> catalog;
    for(int p = 1; p <= P; p++)
    {
        for(int m = 1; m <= M; m++)
        {
            for(int f = 1; f <= F; f++)
            {
                for(int q = 1; q <= Q; q++)
                {
                    for(int b = 1; b <= B; b++)
                    {
                       catalog.push_back(
                               portuguese[p] +
                               math[m] +
                               physics[f] +
                               chemistry[q] +
                               biology[b]);
                    }
                }
            }    
        }    
    }

    sort(catalog.begin(), catalog.end(), cmp);
    return catalog;
}

vector<int> getBooks()
{
    char in;
    vector<int> books;
    string number = "";

    while((in = getchar()) != '\n')
    {
        if(in != ' ')
        {
            number.push_back(in);
        }
        else
        {
            books.push_back(stoi(number));
            number = "";
        }
    }
    if(not number.empty())
    {
        books.push_back(stoi(number));
    }
    return books;
}

int main() {

    int K;
    Catalog catalog;

    for (int i = 0; i < DISCIPLINES; i++)
    {
        vector<int> books = getBooks();
        if(i == PORTUGUESE)
        {
            catalog.P = books[0];
            catalog.portuguese = books;
        }
        else if(i == PHYSICS)
        {
            catalog.F = books[0];
            catalog.physics = books;
        }
        else if(i == BIOLOGY)
        {
            catalog.B = books[0];
            catalog.biology = books;
        }
        else if(i == CHEMISTRY)
        {
            catalog.Q = books[0];
            catalog.chemistry = books;
        }
        else
        {
            catalog.M = books[0];
            catalog.math = books;
        }
    }

    cin >> K;
    unsigned long sum = 0;
    vector<int> sets = catalog.getCatalog();

    for (int j = 0; j < K; j++)
    {
        sum += sets[j];
    }

    cout << sum << endl;
    return 0;
}