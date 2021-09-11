#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

void SortAlgo(string, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    string line;
    ifstream in("./sort.txt");

    if (in.is_open()) {
        while (getline(in, line)) {
            SortAlgo(line, line.length());
        }
    }

    in.close();

    return 0;
}

void SortAlgo(string line, int len)
{
    char tmp;
    for (int i = 0; i < len; i++) {
        for (int j = (len - 1); j >= (i + 1); j--) {
            if (line[j] < line[j - 1]) {
                tmp = line[j];
                line[j] = line[j - 1];
                line[j - 1] = tmp;
            }
        }
    }

    cout << line << endl;
}