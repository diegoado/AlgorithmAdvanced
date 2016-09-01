/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * Codeforces
 * Problem: 350B - B. Balls Game
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    /*
     * N is number the balls put in row;
     * K is number of possible color for one ball;
     * X is the ball's color in the hand of Iahub;
     */
    int N, K, X;
    cin >> N >> K >> X;

    // The balls row.
    int balls[N];
    // First and last point coordinate with balls of same colors.
    int first = -1, last = -1;
    // Location of the balls of the same color with the color of the ball X.
    vector<pair<int, int>> positions;

    for(int i = 0; i < N; i++)
    {
        cin >> balls[i];
        if(balls[i] == X)
        {
            if(first < 0)
                first = i;
            else
                last = i;
        }
        else
        {
            if(first > 0 and last > first)
            {
                pair<int, int> point;
                point.first = first, point.second = last;

                positions.push_back(point);
            }
            first = last = -1;
        }
    }
    // The maximum number of balls Iahub can destroy
    int destroyed = 0;
    for(int j = 0; j < positions.size(); j++)
    {
        first = positions[j].first, last = positions[j].second;
        if(first > 0 and last < N-1)
        {
            bool contiguous;
            do
            {
                contiguous = false;
                int color = balls[first-1];
                if(balls[last+1] == color and ((first > 1 and balls[first-2] == color) or (last < N-1 and balls[last+2] == color)))
                {
                    contiguous = true;
                    while(first > 0 and balls[first-1] == color)
                        first--;
                    while(last < N-1 and balls[last+1] == color)
                        last++;
                }
            } while(contiguous);
        }
        if(last - first + 1 > destroyed)
        {
            destroyed = last - first + 1;
        }
    }
    cout << destroyed << endl;
    return 0;
}