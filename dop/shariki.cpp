#include <iostream>
#include <conio.h>

using namespace std;

void perestanovka(int*, int, int);
bool perebor(int*, int);

int main() {
	int n;
	cout << "Enter number of balls: ";
	cin >> n;

	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}

	int count = 1;

	while (perebor(a, n)) {
		for (int i = 0; i < n; i++) {
			if (a[i] == i + 1) {
				count++;
				break;
			}
		}
	}

	cout << count << endl;

	return _getch();
}


void perestanovka(int* a, int i, int j)
{
	int s = a[i];
	a[i] = a[j];
	a[j] = s;
}

bool perebor(int* a, int n)
{
	int i = n - 2;
	while (i != -1 && a[i] >= a[i + 1]) {
		i--;
	}

	if (i == -1) {
		return false;
	}

	int j = n - 1;
	while (a[i] >= a[j]) {
		j--;
	}

	perestanovka(a, i, j);
	int b = i + 1, c = n - 1;

	while (b < c) {
		perestanovka(a, b++, c--);
	}

	return true;
}
