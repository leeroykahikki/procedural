#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main() 
{ 
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL,"rus");


  char name[] = "";
  cout << "¬ведите ваше им€: ";
  cin >> name;

  cout << "¬ас зовут: " << name << endl;

  return 0; 
}