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
  cout << "������� ���� ���: ";
  cin >> name;

  cout << "��� �����: " << name << endl;

  return 0; 
}