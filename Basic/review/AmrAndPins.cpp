/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 507B - B. Amr and Pins
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <cmath>
#include <iostream>

using namespace std;

int main() {
    int R, Xo, Yo, Xd, Yd;
    /**
     * Circle:
     *
     * R is radius
     * Xo, Yo  is coordinates of original center
     * Xd, Yd is coordinates of destination center
     */
    scanf("%d %d %d %d %d", &R, &Xo, &Yo, &Xd, &Yd);
    // Minimum number of steps required to move the center of the circle to the destination point
    printf("%.0f\n", ceil(sqrt(pow(Xd - Xo, 2) + pow(Yd - Yo, 2))/(2*R)));
    return 0;
}
