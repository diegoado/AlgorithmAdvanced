/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1888 - Renzo and the Palindromic Decoration
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <iostream>

#define MAX_LENGHT 64
#define ULI unsigned long int

using namespace std;

string decToAll(int base, ULI number)
{
    int i = 0; ULI value;
    char baseValue[MAX_LENGHT];

    while (number) {
        value = number % base;

        if (value < 10)
            baseValue[i]= value + '0';
        else
            baseValue[i]= value - 10 + 'A';

        number /= base;
        i++;
    }
    string baseValueRev;
    for (int j = i-1; j >= 0; j--)
        baseValueRev += baseValue[j];

    return baseValueRev;
}

bool isPalindrome(string baseValue)
{
    int i = 0, j = baseValue.size() - 1;
    while (i <= j)
    {
        if (baseValue[i] != baseValue[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    ULI T, N;
    // T corresponding to the number of instances.
    scanf("%lu", &T);
    // Check if have a palindromic representation for any of the bases from 2 to 16
    bool flag;
    for (int i = 0; i < T; i++)
    {
        flag = false;
        // N is a single instance of an integer between 0 and 2^31 written in base 10.
        scanf("%lu", &N);
        for (int base = 2; base < 17; base++)
        {
            if (isPalindrome(decToAll(base, N)))
            {
                if (!flag) {
                    flag = true;
                    printf("%d", base);

                } else
                    printf(" %d", base);
            }
        }
        if (!flag)
            printf("-1");

        printf("\n");
    }
    return 0;
}