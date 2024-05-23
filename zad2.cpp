#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");

    vector<pair<string, string>> jurnal = { // журнал по кусочкам
                                            {"АБс-324", "Клаус"}, 
                                            {"АБс-124", "Бурлаков"}, 
                                            {"АБс-224", "Деревянкин"}, 
                                            {"АБ-222", "Иванов"}, 
                                            {"АБ-124", "Петров"}, 
                                            {"АБс-324", "Арахнидов"} 
    };
    
    sort(jurnal.begin(), jurnal.end()); // сортируем кусочки

    cout << "Восстановленный журнал потока: " << endl;
    for (auto it = jurnal.begin(); it != jurnal.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}