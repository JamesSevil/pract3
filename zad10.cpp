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

void info(vector<Student> students) { // �-�� ������ ����������� ���������
    int count = 0;
    cout << endl << "�������������: " << endl;
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (!it->check) {
            cout << it->group << " " << it->surname << endl;
            count++;
        }
    }
    if (count == 0) {
        cout << "��� �����, ��� �����!" << endl;
    }
}

int main() {
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
        while (true) {
            cout << "��� �� ������� " << it->surname << " �� ����?(1 - ��, 0 - ���): ";
            cin >> it->check;
            if (cin.fail() || (it->check != 0 && it->check != 1)) { // ��������� ������ ����� �� bool
                cin.clear(); // ���������� ���� ������
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����� �����
                cout << "������! ������� ���������� �������� (1 - ��, 0 - ���)." << endl;
            } else {
                break;
            }
        }
    }

    info(students);

    return 0;
}