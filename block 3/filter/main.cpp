#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

void SortAlgo(int[], int);

int main() 
{ 
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