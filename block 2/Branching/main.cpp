#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES

using namespace std;

int main () {
	float x, a;
	cout << "Enter x, a: ";
	cin >> x >> a;
	
	if (fabs(x) < 1) {
		if (x != 0)
			cout << "W = " << (a * log(fabs(x))) << endl;
		else 
			cout << "Error";
	}
	else {
		if ((a - pow(x, 2)) >= 0)
			cout << " W = "<< (sqrt(a - pow(x, 2))) << endl;
		else 
			cout << "Error";
	}
	
	return 0;
}
