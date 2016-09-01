/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1898 - Kickback Sum
 * Time limit per test: 1 second
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <string>
#include <iostream>

using namespace std;

int main() {
    string row;
    // The sum of the two numbers that were diverted from public funds.
    double sum;
    // The cpf of the corrupt.
    string kickbalck = "", cpf = "cpf ";

    int j = 0;
    bool dot = false;

    cin >> row;
    for(int i = 0; i < row.size() && j < 2; i++)
    {
       if(isdigit(row[i]))
       {
           if(cpf.size() < 15)
           {
               cpf.push_back(row[i]);
           }
           else if(dot)
           {
               j++;
               kickbalck.push_back(row[i]);
           }
           else
           {
               kickbalck.push_back(row[i]);
           }

       }
       else if(row[i] == '.')
       {
           dot = true;
           kickbalck.push_back(row[i]);
       }
    }

    j = 0;
    dot = false;
    sum = stod(kickbalck);

    cin >> row;
    kickbalck.clear();
    for(int i = 0; i < row.size() && j < 2; i++)
    {
        if(isdigit(row[i]))
        {
            if(dot)
            {
                j++;
                kickbalck.push_back(row[i]);
            }
            else
            {
                kickbalck.push_back(row[i]);
            }

        }
        else if(row[i] == '.')
        {
            dot = true;
            kickbalck.push_back(row[i]);
        }
    }
    sum += stod(kickbalck);
    printf("%s\n%.2f\n", cpf.c_str(), sum);

    return 0;
}