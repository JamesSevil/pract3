#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

struct Student {
    string group;
    string surname;
    int propusks;
};

void info(vector<Student> students) { // �-�� ������ ���������
    int count = 0;
    cout << endl << "��������: " << endl;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->propusks > 0) {
            cout << it->surname << " (" << it->propusks*10 << " BTC)" << endl;
            count++;
        }
    }
     if (count == 0) {
        cout << "��� �����, ��� �����!" << endl;
    }
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student st;

    int n;
    cout << "������� ���-�� ���������: ";
    cin >> n;

    vector<Student> students(n);
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << "������� ������ � ������� ��������: ";
        cin >> it->group >> it->surname;
        cout << "������� ���-�� ����������� ����.����� �������� " << it->surname << ": ";
        while (true) {
            cin >> it->propusks;
            if (it->propusks < 0) { // ��������� ������ ����� ���������
                cout << "������, �� �� ������ ������� ������������� ��������! �������� ����� �� 0 �� 3: ";
            } else if (it->propusks > 3) {
                cout << "������, ������� ������� ����� ���������! �������� ����� �� 0 �� 3: ";
            } else {
                break;
            }
        }
    }

    info(students);

    return 0;
}