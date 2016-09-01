/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1285 - Different Digits
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

using namespace std;

bool isDifferent(unsigned int x) {
    unsigned int digit;
    string original = to_string(x);

    // Array of possibles digits
    int digits[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i = 0; i < original.size(); i++)
    {
        digit = x % 10; x = x / 10;

        digits[digit]++;
        if(digits[digit] > 1)
        {
            return false;
        }
    }
    return true;
}

int main() {
    // Range of possible number that can be assigned, that do not have repeated digits.
    unsigned int N, M;

    while(cin >> N >> M) {

        /* Integer representing the number of street house
         * numbers between N and M, inclusive, with no repeated digits.
         */
        unsigned int count = 0;

        for (int i = N; i <= M; i++) {
            if (isDifferent(i)) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}