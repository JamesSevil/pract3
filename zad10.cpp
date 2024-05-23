#include <iostream>
#include <vector>
#include <limits>
#include <windows.h>

using namespace std;

struct Student {
    string group;
    string surname;
    bool check;
};

void info(vector<Student> students) { // ф-ия вывода отчисленных студентов
    int count = 0;
    cout << endl << "Ликвидированы: " << endl;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (!it->check) {
            cout << it->group << " " << it->surname << endl;
            count++;
        }
    }
    if (count == 0) {
        cout << "Нет таких, все зайки!" << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    Student st;

    int n;
    cout << "Введите кол-во студентов: ";
    cin >> n;

    vector<Student> students(n);
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << "Введите группу и фамилию студента: ";
        cin >> it->group >> it->surname;
        while (true) {
            cout << "Был ли студент " << it->surname << " на паре?(1 - да, 0 - нет): ";
            cin >> it->check;
            if (cin.fail() || (it->check != 0 && it->check != 1)) { // обработка ошибки ввода на bool
                cin.clear(); // Сбрасываем флаг ошибки
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
                cout << "Ошибка! Введите корректное значение (1 - да, 0 - нет)." << endl;
            } else {
                break;
            }
        }
    }

    info(students);

    return 0;
}