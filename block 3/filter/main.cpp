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
  ifstream in("./sort.txt");

  if (in.is_open()) {
    while (getline(in, line)) {
      cout << line.length() << endl;
      cout << line[2] << endl;
      
    }
  }

  in.close();

  return 0; 
}

void SortAlgo(int data[], int lenD)
{
  int tmp = 0;
  for(int i = 0;i<lenD;i++){
    for(int j = (lenD-1);j>=(i+1);j--){
      if(data[j]<data[j-1]){
        tmp = data[j];
        data[j]=data[j-1];
        data[j-1]=tmp;
      }
    }
  }
}