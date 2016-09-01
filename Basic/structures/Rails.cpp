/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1062 - I Can Guess the Data Structure
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <queue>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    // N is the number of train cars and Bi is a flag to indicate if there are more permutations.
    int N, Bi;

    while(true)
    {
        cin >> N;
        if(N == 0) break;

        while(true)
        {
            cin >> Bi;
            if(Bi == 0) break;

            bool match;
            // Queue representing the train coming from the direction A and a possible permutation goes to the direction B.
            queue<int> A, B;
            // Determines if the queue B may be achieved.
            stack<int> permutation;

            B.push(Bi);
            for(int i = 1; i < N; i++)
            {
                cin >> Bi;
                B.push(Bi);
            }
            for(int i = 1; i < N+1; i++)
            {
                A.push(i);
            }
            while(not A.empty())
            {
                match = true;
                if (A.front() == B.front())
                {
                    match = false;
                    A.pop(); B.pop();
                }
                while(not permutation.empty() and permutation.top() == B.front())
                {
                    B.pop();
                    match = false;
                    permutation.pop();
                }
                if(match)
                {
                    permutation.push(A.front());
                    A.pop();
                }
            }
            if(A.empty() and B.empty() and permutation.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        cout << endl;
    }
    return 0;
}