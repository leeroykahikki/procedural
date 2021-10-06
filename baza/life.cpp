#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;

void fileWrite();
void genSwap();
void genLogic();
bool genAlive();
int genFind(int, int);

// Создаём массивы поколений
int genFuture[21][21];
int genPres[21][21];
int genCount = 0;

int main()
{
	int n = 0;
	cout << "Enter number of generations: ";
	cin >> n;
	if (n <= 0) {
		cout << "Error" << endl;
		return 0;
	}

	// Получаем первое поколение из файла work.dat
	ifstream in("C:\\Users\\leero\\Desktop\\Процедурка\\baza\\work.dat");
	if (in.is_open()) {
		string line;
		int countMain = 0;
		while (getline(in, line)) {

			// Убираем табуляцию
			//while (line.find("\t") != 4294967295) {
			//	line.erase(line.find("\t"), 1);
			//}

			int count = 0;
			for (int i = 0; i < line.size(); i++) {
				if (line[i] == 'x') {
					genFuture[countMain][count] = 1;
				}
				else {
					genFuture[countMain][count] = 0;
				}
				count++;
			}
			countMain++;
		}
	}
	in.close();

	fileWrite();
	genSwap();
	bool isNull = !genAlive();

	while (genCount < n && !isNull) {
		genLogic();
		isNull = !genAlive();
		fileWrite();
		genSwap();
	}

	if (isNull) {
		cout << "All microbes are dead" << endl;
	}

	return 0;
}

void fileWrite() {
	// Выводит поколения в файл work.out
	ofstream out;
	out.open("C:\\Users\\leero\\Desktop\\Процедурка\\baza\\work.out", ios::app);
	if (out.is_open()) {
		out << "Generation #" << ++genCount << "\n";
		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				out << genFuture[i][j] << '\t';
			}
			out << "\n";
		}
		out << "\n";
	}
	out.close();
}

void genSwap() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			genPres[i][j] = genFuture[i][j];
		}
	}
}

bool genAlive() {
	bool isAlive = false;
	for (int i = 0; i < 21; i++) {
		if (isAlive) break;
		for (int j = 0; j < 21; j++) {
			if (genFuture[i][j] == 1) {
				isAlive = true;
				break;
			}
		}
	}
	return isAlive;
}

void genLogic() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			if (genPres[i][j] == 0) {
				genFuture[i][j] = 1;
			}
			else if (genPres[i][j] == 11) {
				genFuture[i][j] == 0;
			}
			else {
				int countMic = genFind(i, j);
				if (countMic == 2 || countMic == 3) {
					genFuture[i][j] = (genPres[i][j] + 1);
				}
				else {
					genFuture[i][j] = 0;
				}
			}
		}
	}
}

int genFind(int i, int j) {
	int countMic = 0;

	// Верхний ряд
	if (i != 0) {
		if (j != 0) {
			if (genPres[i - 1][j - 1] > 0) {
				countMic++;
			}
		}
		if (genPres[i - 1][j] > 0) {
			countMic++;
		}
		if (j != 20) {
			if (genPres[i - 1][j + 1] > 0) {
				countMic++;
			}
		}
	}

	// Средний ряд
	if (j != 0) {
		if (genPres[i - 1][j - 1] > 0) {
			countMic++;
		}
	}
	if (j != 20) {
		if (genPres[i - 1][j + 1] > 0) {
			countMic++;
		}
	}

	// Нижний ряд
	if (i != 20) {
		if (j != 0) {
			if (genPres[i + 1][j - 1] > 0) {
				countMic++;
			}
		}
		if (genPres[i + 1][j] > 0) {
			countMic++;
		}
		if (j != 20) {
			if (genPres[i + 1][j + 1] > 0) {
				countMic++;
			}
		}
	}

	return countMic;
}