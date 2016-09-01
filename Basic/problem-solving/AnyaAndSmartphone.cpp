/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 518C - C. Anya and Smartphone
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define ulli unsigned long long int

using namespace std;

int main() {
    // N is the number of applications that Anya has on her smartphone,
    // M is the number of applications that will be launched and
    // K is the number of icons that are located on the same screen.
    ulli N, M, K;
    cin >> N >> M >> K;

    ulli app;
    // phone[] will store current number of application and
    // pos[] store in which position of array phone[] stay icon of application number i.
    ulli phone[N+1], pos[N+1];

    for(int i = 1; i <= N; i++)
    {
        cin >> app;
        pos[app] = i;
        phone[i] = app;
    }
    // The number of gestures that Anya needs to make to launch all the applications in the desired order
    ulli gestures = 0;
    for(int j = 0; j < M; j++)
    {
        cin >> app;
        gestures += (pos[app] - 1) / K+1;

        if(pos[app] == 1) continue;

        swap(phone[pos[app]], phone[pos[app]-1]);
        swap(pos[phone[pos[app]]], pos[phone[pos[app]-1]]);
    }
    cout << gestures << endl;
    return 0;
}