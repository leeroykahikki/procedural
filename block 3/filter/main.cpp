#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

void SortAlgo(int[], int);

int main() 
{ 
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL,"rus");

  string line;
  ifstream in("./filter.txt");

  if (in.is_open()) {
    while (getline(in, line)) {
      bool isNumber = true;

      for (auto c: line) {
        if (!isdigit(c)) {
          isNumber = false;
        }
      }
      
      if (isNumber) {
        cout << line << endl;
      }
    }
  }

  in.close();

  return 0; 
}