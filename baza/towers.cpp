#include <iostream>
using namespace std;

int num = 0;

void perestanovka(int number, int from, int to, int free)
{
    if (number > 0)
    {
        num++;
        perestanovka(number - 1, from, free, to);
        cout << from << "=>" << to << endl;
        perestanovka(number - 1, free, to, from);
    }
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    perestanovka(n, 1, 3, 2);
    cout << endl << num << endl;

    return 0;
}