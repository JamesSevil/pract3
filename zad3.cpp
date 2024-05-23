#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    vector<string> fruits = { "Банан", "Апельсин", "Яблоко", "Груша", "Мандарин"}; // инициализация вектора студентом

    fill(fruits.begin(), fruits.end(), "/*@%^"); // одногруппник испортил вектор

    cout << "Изменённый вектор: ";
    for (auto it = fruits.begin(); it != fruits.end(); ++it) {
        cout << *it << " ";
    }

    return 0;
}