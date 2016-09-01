/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1899 - Hit the Target
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <limits>

using namespace std;

int main() {
    // Number of walls between the ball and the target;
    int N;
    // The walls properties (base, and where is beginning and ending its opening);
    double D, A, B;
    // The walls properties of the target (its same of the walls);
    double DT, AT, BT;

    cin >> N;
    // Variables to check the intersection between the walls and target;
    double minimum = numeric_limits<double>::min();
    double maximum = numeric_limits<double>::max();

    for (int i = 0; i < N; i++)
    {
        cin >> D >> A >> B;
        minimum = A/D > minimum ? A/D : minimum;
        maximum = B/D < maximum ? B/D : maximum;
    }

    cin >> DT >> AT >> BT;
    minimum = AT/DT > minimum ? AT/DT : minimum;
    maximum = BT/DT < maximum ? BT/DT : maximum;

    if(minimum <= maximum)
    {
         cout << 'Y' << endl;
    }
    else
    {
        cout << 'N' << endl;
    }
    return 0;
}

