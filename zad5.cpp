#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");

    vector<string> garage = { {"BMW", "Mercedes", "BMW", "Audi", "Audi", "Hummer"} }; // гараж автолюбителя

    sort(garage.begin(), garage.end()); // сортируем контейнер

    garage.erase(unique(garage.begin(), garage.end()), garage.end()); // перемещаем дубликаты в конец вектора и удаляем их

    for (auto it = garage.begin(); it != garage.end(); ++it) { // вывод уникальных
        cout << *it << " ";
    }

    return 0;
}