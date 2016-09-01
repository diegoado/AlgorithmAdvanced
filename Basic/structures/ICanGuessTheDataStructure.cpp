/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1340 - I Can Guess the Data Structure
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <stack>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    // The size of test case.
    int N;
    // The command type and an integer to push or pop in the data structure.
    int command, value;
    bool is_stack, is_queue, is_priority_queue;

    while(cin >> N)
    {
        stack<int> stack;
        queue<int> queue;
        priority_queue<int> priority_queue;

        // The program answer
        string structure;
        // Flags to check if input belong a stack, queue and/or priority queue.
        is_stack = is_queue = is_priority_queue = true;

        for (int i = 0; i < N; i++)
        {
            cin >> command >> value;
            if(command == 1)
            {
                stack.push(value);
                queue.push(value);
                priority_queue.push(value);
            }
            else
            {
                if(is_stack and not stack.empty() and value != stack.top())
                    is_stack = false;
                else if(is_stack)
                    stack.pop();
                if(is_queue and not queue.empty() and value != queue.front())
                    is_queue = false;
                else if(is_queue)
                    queue.pop();
                if(is_priority_queue and not priority_queue.empty() and value != priority_queue.top())
                    is_priority_queue = false;
                else if(is_priority_queue)
                    priority_queue.pop();

            }
        }
        if((is_stack and is_queue) or (is_stack and is_priority_queue) or (is_queue and is_priority_queue))
            structure = "not sure";
        else if(not is_stack and not is_queue and not is_priority_queue)
            structure = "impossible";
        else if(is_stack)
            structure = "stack";
        else if(is_queue)
            structure = "queue";
        else
            structure = "priority queue";

        cout << structure << endl;
    }
    return 0;
}
