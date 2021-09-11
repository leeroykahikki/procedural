#include <iostream>
#include <math.h>
#include <windows.h>
#define _USE_MATH_DEFINES

using namespace std;

int main () {
	SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL,"rus");

	float x, a;
	cout << "Введите x, a: ";
	cin >> x >> a;
	
	if (fabs(x) < 1) {
		if (x != 0)
			cout << "W = " << (a * log(fabs(x))) << endl;
		else 
			cout << "Ошибка";
	}
	else {
		if ((a - pow(x, 2)) >= 0)
			cout << " W = "<< (sqrt(a - pow(x, 2))) << endl;
		else 
			cout << "Ошибка";
	}
	
	return 0;
}
