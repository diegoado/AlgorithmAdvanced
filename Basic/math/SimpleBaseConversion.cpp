/*
 * University Federal of Campina Grande
 * Student: Diego Adolfo Silva de Araújo
 * Registry: 113210090
 * Discipline: Algoritmos Avançados
 *
 * URI - Online Judge
 * Problem: 1199 - Simple Base Conversion
 * Time limit per test: 2 seconds
 * Memory limit per test: 256 megabytes
 * Input: standard input
 * Output: standard output
 */

#include <string>
#include <iostream>

#define ull unsigned long

using namespace std;

ull pow(int base, ull exponent)
{
    ull sum;
    if(exponent == 0) return 1;

    sum = pow(base, exponent/2);
    sum = sum * sum;

    if(exponent % 2 == 1) sum = sum * base;

    return sum;
}

ull toDec(string hex)
{
    ull dec = 0;
    ull len = hex.size();
    for(int i = 2; i < len; i++)
    {
       if(hex[i] >= 48 and hex[i] <= 57)
       {
           dec += (hex[i] - 48) * pow(16, len-i-1);
       }
       else if(hex[i] >= 65 and hex[i] <= 70)
       {
           dec += (hex[i] - 55) * pow(16, len-i-1);
       }
       else if(hex[i] >= 97 and hex[i] <= 102)
       {
           dec += (hex[i] - 87) * pow(16, len-i-1);
       }
    }
    return dec;
}

string toHex(ull dec)
{
    if(dec == 0) return "0x0";

    string hex = "";
    while(dec > 0)
    {
        ull mod = dec % 16;
        if(mod > 9)
        {
            switch(mod)
            {
                case 10:
                    hex = 'A' + hex;
                    break;
                case 11:
                    hex = 'B' + hex;
                    break;
                case 12:
                    hex = 'C' + hex;
                    break;
                case 13:
                    hex = 'D' + hex;
                    break;
                case 14:
                    hex = 'E' + hex;
                    break;
                case 15:
                    hex = 'F' + hex;
                    break;
            }
        }
        else
        {
            hex = char(mod + '0') + hex;
        }
        dec /= 16;
    }
    return "0x" + hex;
}

int main() {
    // A single non-negative number, which may be a decimal or hexadecimal number.
    string N;
    while(true)
    {
        cin >> N;
        if(N == "-1") break;

        if(N.find("0x") != string::npos)
            cout << toDec(N) << endl;
        else
            cout << toHex(stoul(N)) << endl;
    }
    return 0;
}
