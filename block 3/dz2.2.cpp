#include <iostream>
using namespace std;

int main()
{
  double S, m, p;
  int n;
  cout << "Enter S, m, n: ";
  cin >> S >> m >> n;

  p = ((((12. * m) / S)) - 1) * 100;
  if (p > 100) {
    cout << "Error" << endl;
  } else {
    cout << p << "%" << endl;
  }

	return 0;
}