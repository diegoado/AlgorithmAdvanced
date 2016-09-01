/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1890 - Putting Plates on the Tuk-tuks
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <math.h>
#include <iostream>

#define DIGITS 10
#define CONSONANTS 26

using namespace std;

int main() {
    // T corresponding to the number of instances.
    int N;
    // C and D represent the number of consonants and digits in the new system.
    int C, D;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> C >> D;
        // A license plate cannot be empty.
        if(C == 0 and D == 0)
            cout << 0 << endl;
        else
            printf("%.f\n", pow(DIGITS, D) * pow(CONSONANTS, C));
    }
    return 0;
}
