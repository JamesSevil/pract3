#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");

    vector<pair<string, bool>> students = { // вектор студентов
    {"Клаус", true},
    {"Бурлаков", false},
    {"Петров", false},
    };

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->second == false) { // если не посещал, то выводим
            cout << it->first << endl;
        }
    }

    return 0;
}