#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

int to_dec(string str, int j, int s)
{
    map<char, int> dec;
    dec['1'] = 1;
    dec['2'] = 2;
    dec['3'] = 3;
    dec['4'] = 4;
    dec['5'] = 5;
    dec['6'] = 6;
    dec['7'] = 7;
    dec['8'] = 8;
    dec['9'] = 9;
    dec['A'] = 10;
    dec['B'] = 11;
    dec['C'] = 12;
    dec['D'] = 13;
    dec['E'] = 14;
    dec['F'] = 15;
    dec['G'] = 16;
    dec['H'] = 17;
    dec['I'] = 18;
    dec['J'] = 19;
    dec['K'] = 20;
    dec['L'] = 21;
    dec['M'] = 22;
    dec['N'] = 23;
    dec['O'] = 24;
    dec['P'] = 25;
    dec['Q'] = 26;
    dec['R'] = 27;
    dec['S'] = 28;
    dec['T'] = 29;
    dec['U'] = 30;
    dec['V'] = 31;
    dec['W'] = 32;
    dec['X'] = 33;
    dec['Y'] = 34;
    dec['Z'] = 35;

    int i, p;
    p = strlen(str.c_str()) - 1;

    for (i = 0; str[i] != '\0'; i++)
    {
        s = s + dec[toupper(str[i])] * pow(j, p);
        p--;
    }

    return s;
}

int main()
{
	int sys1, sys2, res = 0, count = 0;
    char str[100];
    cout << "Enter number system: ";
	cin >> sys1;

    if (sys1 < 10)
    {
        int num;
        cout << "Enter number: ";
        cin >> num;

        while (num > 0)
        {
            res += num % 10 * pow(sys1, count++);
            num /= 10;
        }

        cout << "Enter new number system: ";
        cin >> sys2;

        _itoa_s(res, str, sys2);
        cout << str << endl;
    }
    else if (sys1 > 10)
    {
        string num;
        cout << "Enter number: ";
        cin >> num;
        cout << "Enter new number system: ";
        cin >> sys2;

        _itoa_s(to_dec(num, sys1, res), str, sys2);
        cout << str << endl;
    }
    else if (sys1 == 10)
    {
        int num;
        cout << "Enter number: ";
        cin >> num;
        cout << "Enter new number system: ";
        cin >> sys2;

        _itoa_s(num, str, sys2);
        cout << str << endl;
    }
    else
    {
        cout << "Error" << endl;
    }
 

	return 0;
}