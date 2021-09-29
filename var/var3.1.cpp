#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string* column = new string[1000];
    int count = 0;

    ifstream in("C:\\Users\\leero\\Desktop\\Процедурка\\test.txt");
    if (in.is_open())
    {
        string line;

        while (getline(in, line))
        {
            column[count] = line;
            count++;
        }
    }
    in.close();

    ofstream out;
    out.open("C:\\Users\\leero\\Desktop\\Процедурка\\test.txt");
    if (out.is_open())
    {
        for (int i = 0; i < count; i++) {
            for (int j = 0; j < column[i].size(); j++) {
                if (column[i][j] == ' ') {
                    column[i][j] = '\n';
                }
            }
            
            column[i] += '\n';
        }

        for (int i = 0; i < count; i++) {
            out << column[i];
        }
    }

    cout << "End of program" << endl;
    return 0;
}