#include <iostream>
#include <cmath>

using namespace std;

long long int factorial(int);
long double ssin(int, long double = 0.);
long double ryad(long long int, long double);
long double sum = 0;

int main()  
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    if (n <= 0) {
        return 0;
    }

    long double sum = ryad(factorial(1), ssin(1));
    for (int i = 2; i <= n; i++) {
        sum *= ryad(factorial(i), ssin(i));
    }

    cout << sum << endl;
    return 0;
}

long long int factorial(int n) {
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

long double ssin(int n, long double s) {
    if (n == 0) {
        return s;
    }
    else {
        s += sin(2 * n);
        n -= 1;
        s = ssin(n, s);
    }

    return s;
}

long double ryad(long long int n, long double s) {
    return (n / s);
}