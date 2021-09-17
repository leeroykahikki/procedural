#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double S, p, n, m, r;
	cout << "Enter S, p, n: ";
	cin >> S >> p >> n;

	r = p / 100.;

	if (n == 0.) {
		cout << "Error" << endl;
	}
	else if (r == 0. && (12. * (pow((1. + r), n) - 1.)) == 0.) {
		cout << S / (12. * n) << endl;
	}
	else if ((12. * (pow((1. + r), n) - 1.)) == 0.) {
		cout << "Error" << endl;
	}
	else {
		m = (S * r * (1. + pow(r, n))) / (12. * (pow((1. + r), n) - 1.));
		cout << m << endl;
	}

	return 0;
}