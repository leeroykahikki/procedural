#include <iostream>
#include <vector>
using namespace std;

//int monach[600][3] = {
//    /*1*/{2, 3 , 4},
//    /*2*/{5, 6, 7},
//    /*3*/{8, 9, 0},
//    /*4*/{10, 11, 0},
//    /*5*/{12, 13, 0},
//    /*6*/{14, 15, 16},
//};
                   /*{  1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20,21,22,23, 24, 25}*/
//int monachOdn[600] = { -1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 9, 9, 9, 10, 10, 11 };
int monachOdn[600] = {-1};
vector<int> teachers;
vector<int> teachersA;
vector<int> teachersB;

void addMonach();
int findMonach(int);
int findMonach(int, int);

int main()
{
    addMonach();
    while (true) {
        teachers.clear();
        teachersA.clear();
        teachersB.clear();
        int n, a, b;
        cout << "Enter count: ";
        cin >> n;
        if (n == 1) {
            cout << "Enter id: ";
            cin >> a;
            if (a == 1) {
                cout << "This is Petr" << endl;
            }
            if (monachOdn[a-1] == 0) {
                cout << a << " - not monach" << endl;
            }
            else {
                findMonach(a-1);
                cout << a << " - is monach, his teachers is";
                for (int i = 0; i < teachers.size(); i++) {
                    cout << " " << teachers.at(i);
                }
                cout << endl;
            }
        }
        else if (n == 2) {
            cout << "Enter two id: ";
            cin >> a >> b;
            if (a == 1 || b == 1) {
                cout << "One this id is Petr" << endl;
            }

            if (monachOdn[a-1] == 0 && monachOdn[b-1] == 0) {
                cout << a << " and " << b << " - not monachi" << endl;
            }
            else if (monachOdn[a-1] == 0) {
                cout << a << " - not monach" << endl;
            }
            else if (monachOdn[b-1] == 0) {
                cout << b << " - not monach" << endl;
            }
            else {
                int nearbyTeacherId = findMonach(a-1, b-1);
                cout << a << " and " << b << " - both is monachi, their common teacher is " << nearbyTeacherId << endl;
            }
        }
        else {
            cout << "Error" << endl;
        }
    }

    return 0;
}

void addMonach() {
    bool isWorking = true;
    cout << "Enter start data: " << endl;
    while (isWorking) {
        int s, a, b, c;
        cin >> s >> a >> b >> c;

        if (s == 0) {
            isWorking = false;
            break;
        }
        else if (s < 0 || a < 0 || b < 0 || c < 0 || s > 600 || a > 600 || b > 600 || c > 600 || s == a || s == b || s == c) {
            cout << "Not valid monach id";
            continue;
        }

        if (a != 0) {
            monachOdn[a - 1] = s;
        }
        if (b != 0) {
            monachOdn[b - 1] = s;
        }
        if (c != 0) {
            monachOdn[c - 1] = s;
        }
    }
}

int findMonach(int a) {
    if (monachOdn[a] == -1) {
        return 0;
    }
    else {
        teachers.push_back(monachOdn[a]);
        findMonach(monachOdn[a]-1);
    }

    return 0;
}

int findMonach(int a, int b) {
    findMonach(a);
    teachersA = teachers;
    teachers.clear();

    findMonach(b);
    teachersB = teachers;
    teachers.clear();

    int nearbyTeacherId = 0;
    for (int i = 0; i < teachersA.size(); i++) {
        for (int j = 0; j < teachersB.size(); j++) {
            if (teachersA.at(i) == teachersB.at(j)) {
                if (nearbyTeacherId == 0) {
                    nearbyTeacherId = teachersB.at(j);
                }
            }
        }
    }

    return nearbyTeacherId;
}