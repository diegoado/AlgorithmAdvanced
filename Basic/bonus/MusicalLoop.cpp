/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1089 - Musical Loop
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

const int LOOP = -9999;

int main() {
    // The number of samples in the musical loop.
    unsigned int N;

    while(true)
    {
        cin >> N;
        if(N == 0) break;

        long int music[N];
        for(int i = 0; i < N; i++)
        {
            cin >> music[i];
        }
        /*
         * C is the number of peaks that exist in the musical loop.
         * S representing the i-th local maximum or minimum musical peak.
         */
        int C = 0, S = 0;
        /*
         * PA is the previous musical peaks
         * SA mark if the previous peaks is a maximum or minimum musical peak.
         * SI and SF are the one and the last i-th local maximum or minimum peak.
         */
        int PA, SA, SI, SF;
        PA = SA = SI = SF = LOOP;

        for(int j = 0; j < N; j++)
        {
            if(PA != LOOP)
            {
                if(PA < music[j])
                {
                    S = 1;
                }
                else if(PA > music[j])
                {
                    S = -1;
                }
                if(SA != LOOP)
                {
                    if(SA != 0 and S != SA)
                    {
                        C++;
                    }
                }
                SA = S;
            }
            PA = music[j];
            if(SI == LOOP and S != 0)
            {
                SI = S;
            }
            if(j == N-1)
            {
                SF = S;
            }
        }
        if(SI != SF)
        {
            C++;
        }
        else if(SI != 0)
        {
            C += 2;
        }
        cout << C << endl;
    }
    return 0;
}