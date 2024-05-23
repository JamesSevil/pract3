#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    bool check;
};

int main(){
    setlocale(LC_ALL, "Rus");

    vector<Student> journal = { {"Иванов", false}, {"Петров", true}, {"Клаус", false}, {"Смыков", true}};
    
    auto newEnd = remove_if(journal.begin(), journal.end(), [](const Student& student) { return student.check; });

    journal.erase(newEnd, journal.end());

    for (auto it = journal.begin(); it != journal.end(); ++it) {
        cout << it->name << " ";
    }

    return 0;
}