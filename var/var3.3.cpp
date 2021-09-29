#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>

using namespace std;

int main()
{
    // Чтобы не создавать новый файл каждый раз заного
    const unsigned int DIM1 = 10, DIM2 = 5;
    char nach[DIM1][DIM2] = {
        {'5','10','1','3','7'},
        {'2','6','8','6','7'},
        {'4','4','8','3','4'},
        {'6','6','8','5','4'},
        {'5','5','3','9','1'},
        {'1','7','6','3','4'},
        {'5','4','6','6','5'},
        {'4','7','6','5','4'},
        {'6','2','2','4','7'},
        {'6','3','2','4','1'}
    };

    ofstream out;
    out.open("C:\\Users\\leero\\Desktop\\Процедурка\\var\\1.txt");
    if (out.is_open())
    {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 5; j++) {
                out << nach[i][j];
                out << ";";
            }
            out << "\n";
        }
    }
    out.close();
    ////////////////////////

    ifstream in("C:\\Users\\leero\\Desktop\\Процедурка\\var\\1.txt");
    if (in.is_open())
    {
        string line;
        while (getline(in, line))
        {
            // Создание массива из строки
            vector<string> a;
            string num;
			for (auto c : line) {
				if (c == ';') {
                    a.push_back(num);
                    num = "";
				}
				else {
                    num += c;
				}
			}

            // Нахождение min и max
            istringstream ist1(a.at(0));
            int number1;
            ist1 >> number1;
            int min = number1, max = number1;
            for (int i = 0; i < a.size(); i++) {
                istringstream ist(a.at(i));
                int number;
                ist >> number;

                if (number > max) {
                    max = number;
                }

                if (number < min) {
                    min = number;
                }
            }

            // Замена min и max на 0
            for (int i = 0; i < a.size(); i++) {
                istringstream ist(a.at(i));
                int number;
                ist >> number;

                if (number == max || number == min) {
                    a.at(i) = "0";
                }
            }

            // Запись новых массивов в файл 2
            out.open("C:\\Users\\leero\\Desktop\\Процедурка\\var\\2.txt", ios::app);
            if (out.is_open())
            {
                for (int i = 0; i < a.size(); i++) {
                    out << a.at(i) << ";";
                }

                out << "\n";
            }
            out.close();

            // Создание матрицы
            int count = 0;
            string matrix[10][10];
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (count < a.size()) {
                        matrix[i][j] = a.at(count);
                        count++;
                    }
                    else {
                        matrix[i][j] = to_string(rand() / 1000);
                    }
                }
            }

            // Запись матрицы в файл 3
            out.open("C:\\Users\\leero\\Desktop\\Процедурка\\var\\3.txt", ios::app);
            if (out.is_open())
            {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        out << matrix[i][j] << "\t";
                    }

                    out << "\n";
                }

                out << "\n";
            }
            out.close();

            // Вывод в консоль
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    cout << matrix[i][j] << "\t";
                }

                cout << endl;
            }

            cout << endl << endl;
        }
    }
    in.close();

    cout << "End of program" << endl;
    return 0;
}