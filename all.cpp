#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

void SortAlgo(string, int);
void SortAlphabet();
void bank1();
void file();
void signMain();
int sign(int);

int main()
{
	//double S, m, n, r;
	//cout << "Enter S, m, n: ";
	//cin >> S >> m >> n;

	//r = ((m * (n * 12)) - S) / (S * n);

	return 0;
}

void signMain() {
	int num;
	cout << "Enter number: ";
	cin >> num;

	if (cin.good()) {
		cout << sign(num) << endl;
	}
	else {
		cout << "Error" << endl;
	}
}

int sign(int num) {
	if (num > 0) {
		return 1;
	}
	else if (num < 0) {
		return -1;
	}
	else {
		return 0;
	}
}

void file() {
	string path = "C:\\Users\\leero\\Desktop\\Процедурка\\test.txt";
	ofstream out(path);

	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;
		out << num << endl;
	}

	out.close();

	string line;
	ifstream in(path);
	int sum = 0;

	if (in.is_open()) {
		while (getline(in, line)) {
			sum += int(atoi(line.c_str()));
		}

		cout << sum << endl;
	}
}

void bank1() {
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
}

void SortAlphabet() {
	string line;
	ifstream in("C:\\Users\\leero\\Desktop\\Процедурка\\block 3\\sort\\sort.txt");

	if (in.is_open()) {
		while (getline(in, line)) {
			SortAlgo(line, line.length());
		}
	}

	in.close();
}

void SortAlgo(string line, int len)
{
	char tmp;
	for (int i = 0; i < len; i++) {
		for (int j = (len - 1); j >= (i + 1); j--) {
			if (line[j] < line[j - 1]) {
				tmp = line[j];
				line[j] = line[j - 1];
				line[j - 1] = tmp;
			}
		}
	}

	cout << line << endl;
}