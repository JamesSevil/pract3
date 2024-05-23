#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");

    vector<pair<string, int>> statistika = { {"Иванов", 70}, {"Петров", 54}, {"Сидоров", 98} };
    vector<int> time;

    for (auto it = statistika.begin(); it != statistika.end(); ++it) { 
        time.push_back(it->second);
    }

    for (auto it = statistika.begin(); it != statistika.end(); ++it) { 
        if (it->second == *min_element(time.begin(), time.end())) {
            cout << "На олимпиаду поедет: " << it->first;
        }
    }


    return 0;
}