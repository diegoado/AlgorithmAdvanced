/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1829 - Biggest Number Game
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <math.h>
#include <iostream>

using namespace std;

int main() {
    // The number of rounds played.
    int N;
    // Strings contains Lucas's exponential and Pedro's factorial.
    string L, P;

    cin >> N;
    // Array contains the winner of the round r.
    string round[N];
    // Score of rounds that Lucas and Pedro won.
    int Lr = 0, Pr = 0;

    for(int i = 0; i < N; i++)
    {
        // Representation of exponential in the form A^B and factorial in the form K!
        string A, B, K;
        cin >> L; cin >> P;

        for(int j = 0; j < L.find('^'); j++)
            A.push_back(L[j]);
        for(int l = L.find('^') + 1; l < L.size(); l++)
            B.push_back(L[l]);
        for(int j = 0; j < P.size() - 1; j++)
            K.push_back(P[j]);

        if(atoi(B.c_str()) * log(atoi(A.c_str())) > lgamma(atoi(K.c_str()) + 1))
        {
            Lr++;
            round[i] = ": Lucas";
        }
        else
        {
            Pr++;
            round[i] = ": Pedro";
        }
    }

    if(Lr == Pr)
        cout << "A competicao terminou empatada!" << endl;
    else if(Lr > Pr)
        cout << "Campeao: Lucas!" << endl;
    else
        cout << "Campeao: Pedro!" << endl;

    for(int k = 0; k < N; k++)
        cout << "Rodada #" << k+1 << round[k] << " foi o vencedor" << endl;

    return 0;
}
