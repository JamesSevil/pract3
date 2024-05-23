#include <iostream>
#include <vector>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    int n;
    cout << "Введите кол-во студентов: ";
    cin >> n;

    vector<int> estimation(n); // оценки
    for (auto it = estimation.begin(); it != estimation.end(); ++it) { // преподаватель выставляет оценки студентам
        *it = 1 + rand() % 5;
    }

    for (auto it = estimation.begin(); it != estimation.end(); ++it) { // игра
        int est;
        cout << "Угадайте оценку: ";
        cin >> est;
        if (*it == 5) {
            cout << "У вас оценка 5, независимо от вашего выбора!" << endl;
        } else if (*it == 1) {
            cout << "У вас оценка 1, независимо от вашего выбора вы отправляетесь на пересдачу!" << endl;
        } else if (est == *it) {
            cout << "Вы угадали! Оценка повышена" << endl;
            est++;
            *it = est;
        } else if (est != *it) {
            cout << "Вы не угадали! Оценка понижена" << endl;
            est = *it;
            est--;
            *it = est;
        }
    }

    cout << "Оценки студентов: ";
    for (auto it = estimation.begin(); it != estimation.end(); ++it) { // вывод итоговых оценок
        cout << *it << " ";
    }

    return 0;
}