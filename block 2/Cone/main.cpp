#include <iostream>
#include <math.h>
#include <windows.h>
#define _USE_MATH_DEFINES

using namespace std;

float Volume (float, float, float);
float Area (float, float, float);

int main () {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  setlocale(LC_ALL,"rus");
	
	float R, r, h;
	cout << "�������: R, r, h: ";
	cin >> R >> r >> h;
	
	if (R > 0 && r > 0 && h > 0 && R > r)  {
		cout << Volume(R, r, h) << endl;
		cout << Area(R, r, sqrt(pow(h, 2) + pow(R, 2))) << endl;
	}
	else {
		cout << "������" << endl;
  }
	
	return 0;
	
}

float Volume (float R, float r, float h) {
	return (1.0/3.0) * M_PI * h * (pow(R, 2) + R*r + pow(r, 2));
}

float Area (float R, float r, float l) {
	return M_PI * (pow(R, 2) + (R+r) * l + pow(r, 2));
}
