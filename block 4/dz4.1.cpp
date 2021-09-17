#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

void file();
void signMain();
int sign(int);

int main()
{
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
  
	return 0;
}