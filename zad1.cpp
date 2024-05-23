#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

struct Student {
    string group;
    string surname;
    int propusks;
};

void info(vector<Student> students) { // ф-ия вывода должников
    int count = 0;
    cout << endl << "Должники: " << endl;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->propusks > 0) {
            cout << it->surname << " (" << it->propusks*10 << " BTC)" << endl;
            count++;
        }
    }
     if (count == 0) {
        cout << "Нет таких, все зайки!" << endl;
    }
}

int main(){
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
        cout << "Введите кол-во пропущенных кнтр.работ студента " << it->surname << ": ";
        while (true) {
            cin >> it->propusks;
            if (it->propusks < 0) { // обработка ошибки ввода пропусков
                cout << "Ошибка, вы не можете вводить отрицательное значение! Выберите число от 0 до 3: ";
            } else if (it->propusks > 3) {
                cout << "Ошибка, введено слишком много пропусков! Выберите число от 0 до 3: ";
            } else {
                break;
            }
        }
    }

    info(students);

    return 0;
}