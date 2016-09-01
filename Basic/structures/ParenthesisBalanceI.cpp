/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1068 - Parenthesis Balance I
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <stack>
#include <string>
#include <iostream>

using namespace std;

char OPEN = '(', CLOSE = ')';

int main() {
    // Flag that testing if an expression is according with rules.
    bool match;
    //  The expression input and program answer.
    string expression, reply;

    while(cin >> expression)
    {
        match = true;
        reply = "incorrect";
        // Stack contains the expression's parenthesis.
        stack<char> parenthesis;

        for(int i = 0; i < expression.size(); i++)
        {
            if(expression[i] == OPEN)
            {
                parenthesis.push(expression[i]);
            }
            else if(expression[i] == CLOSE)
            {
                if(parenthesis.empty() or parenthesis.top() != OPEN)
                {
                    match = false;
                    break;
                }
                else
                {
                    parenthesis.pop();
                }
            }
        }
        if(parenthesis.empty() and match)
        {
            reply = "correct";
        }
        cout << reply << endl;
    }
    return 0;
}