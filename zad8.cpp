#include <iostream>
#include <vector>

using namespace std;

struct Tovar {
    string name;
    int quantity;
};

class Buffet {

private:
    vector<Tovar> buffetik;
    vector<Tovar> prodaja;

public:
    void add(string nazvanie, int kolvo) {
        bool check = false;
        for (auto it = buffetik.begin(); it != buffetik.end(); ++it) {
            if (it->name == nazvanie) { // если такой товар есть, то плюсуем кол-во
                it->quantity += kolvo;
                check = true; 
            }
        }
        if (!check) { // если нету, то добавляем структуру в целом в вектор
            buffetik.push_back({nazvanie, kolvo});
        }
    }

    void del(string nazvanie, int kolvo) {
        if (buffetik.empty()) { // Если буфет пустой, то выводим соответствующие сообщение
            cout << "Буфет пуст!" << endl;
        } else {
            bool check = false;
            for (auto it = buffetik.begin(); it != buffetik.end(); ++it) {
                if (it->name == nazvanie && it->quantity - kolvo < 0) { // если не хватает товара для продажи, выводим сообщение
                    cout << "Ошибка, не хватает товара для продажи!" << endl;
                } else if (it->name == nazvanie) { // Если все хватает, то производим продажу
                    it->quantity -= kolvo;
                    check = true;
                    bool check_in_prodaja = false;
                    for (auto iter = prodaja.begin(); iter != prodaja.end(); ++iter) { // записываем продажу в вектор
                        if (iter->name == nazvanie) { // если такой товар есть, то плюсуем кол-во
                            iter->quantity += kolvo;
                            check_in_prodaja = true; 
                        }
                    }
                    if (!check_in_prodaja) { // если нету, то добавляем структуру в целом в вектор
                        prodaja.push_back({nazvanie, kolvo});
                    }
                }
            }
            if (!check) {
                cout << "Ошибка! Такого товара нет в продаже!" << endl;
            }
        }
    }

    void info() {
        if (buffetik.empty()) {
            cout << "Буфет пуст!" << endl;
        } else {
            cout << "Товар на прилавке: " << endl;
            for (auto it = buffetik.begin(); it != buffetik.end(); ++it) {
                cout << it->name << " " << it->quantity << " штук" << endl;
            }
            cout << "Проданный товар: " << endl;
            for (auto it = prodaja.begin(); it != prodaja.end(); ++it) {
                cout << it->name << " " << it->quantity << " штук" << endl;
            }
        }
    }

};

int main(){
    setlocale(LC_ALL, "Rus");

    Buffet bufet;
    Tovar tovar;

    while(true) {
        string comand;
        cout << "Выберите команду(add - добавить, del - удалить, info - вывести информацию, exit - выход): ";
        cin >> comand;
        if (comand == "add") {
            cout << "Введите название товара и его кол-во: ";
            cin >> tovar.name >> tovar.quantity;
            bufet.add(tovar.name, tovar.quantity);
        } else if (comand == "del") {
            cout << "Введите название товара и его кол-во: ";
            cin >> tovar.name >> tovar.quantity;
            bufet.del(tovar.name, tovar.quantity);
        } else if (comand == "info") {
            bufet.info();
        } else if (comand == "exit") {
            cout << "Выход..." << endl;
            break;
        } 
        else {
            cout << "Ошибка! Команда введена неверно" << endl;
        }
    }

    return 0;
}