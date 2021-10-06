#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <random>

using namespace std;

bool isExist(string);
vector<int> comp;
int randNum();
vector<int> numbers;

int main()
{
	string quest;
	for (int i = 0; i < 4; i++) {
		stringstream ss;
		ss << randNum();
		quest += ss.str();
	}
	cout << quest << endl << endl;
	cout << "Game started" << endl;

	bool isEnd = false;
	while (!isEnd) {
		comp.clear();
		string ans;
		cout << "Enter answer: " << endl;
		cin >> ans;

		if (ans.size() < 4) {
			cout << "Number length lower than 4" << endl << endl;
			continue;
		}
		else if (ans.size() > 4) {
			cout << "Number length higher than 4" << endl << endl;
			continue;
		}

		string res;
		int countPlus = 0;
		for (int i = 0; i < 4; i++) {
			if (quest[i] == ans[i]) {
				comp.push_back(quest[i]);
				res += "+";
				countPlus++;
			}
		}

		
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (quest[i] == ans[j] && i == j) {
					continue;
				}
				else if (quest[i] == ans[j]) {
					if (!isExist(to_string(ans[j]))) {
						res += "-";
						comp.push_back(ans[j]);
					}
				}
			}
		}

		if (countPlus == 4) {
			isEnd = true;
			cout << res << endl;
			cout << "You won! Number is " << quest << endl;
		}
		else {
			cout << res << endl << endl;
		}
	}

	return 0;
}

bool isExist(string n) {
	for (int i = 0; i < comp.size(); i++) {
		if (comp.at(i) == atoi(n.c_str())) {
			return true;
		}
	}

	return false;
}

int randNum() {
	random_device rd;
	mt19937 mersenne(rd());
	uniform_int_distribution<> dist(0, 9);
	int num;
	bool isNew = true;

	do {
		isNew = true;
		num = dist(mersenne);

		if (numbers.size() == 0) {
			numbers.push_back(num);
		}
		else {
			for (int i = 0; i < numbers.size(); i++) {
				if (numbers.at(i) == num) {
					isNew = false;
				}
			}
		}
	} while (!isNew);

	numbers.push_back(num);
	return num;
}