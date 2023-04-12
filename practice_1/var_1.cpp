#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

unsigned int min_quantity = 0;
float min_price = 0;

struct Date {
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Records {
    char name[11];
    char producer[10];
    unsigned int quantity;
    float price;
    struct Date date;
};

void center(const char* s, int wLine) {
    int w = strlen(s);
    int delta = (wLine - w) / 2 - 1;
    cout << left;
    cout.width(delta); cout << " ";
    cout << s;
    cout.width(delta); cout << " ";
}

void print_date(unsigned short day, unsigned short month, unsigned short year, int wLine) {
    int w = 10;
    int delta = (wLine - w) / 2 - 1;
    cout << left;
    cout.width(delta); cout << " ";
    if (day > 9) {
        cout << day;
    } else {
        cout << "0" << day;
    }
    cout << ".";
    if (month > 9) {
        cout << month;
    } else {
        cout << "0" << month;
    }
    cout << ".";
    cout << year;
    cout.width(delta); cout << " ";
}

void draw_table(struct Records* records, int count) {
    cout << endl; cout.width(79); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(78); cout << left << "|Office packages"; cout << "|" << endl;
    cout.width(79); cout.fill('-'); cout << "-" << endl;
    cout.fill(' ');

    cout << left << "|"; center("Name", 14);
    cout << left << "|"; center("Producer", 16);
    cout << left << "|"; center("Number of components", 26);
    cout << left << "|"; center("Price ($)", 13);
    cout << left << "|"; center("Date", 14);
    cout << "|" << endl;
    cout.width(79); cout.fill('-'); cout << "-" << endl;
    cout.fill(' ');

    for (int i = 0; i < count; i++) {
        cout << left << "|"; cout.width(12); cout << left << records[i].name;
        cout << left << "|"; cout.width(14); cout << left << records[i].producer;
        cout << "|"; cout.width(24); cout << left << records[i].quantity;
        std::cout.precision(2); cout << left << "|"; cout.width(11); cout << fixed << left << records[i].price;
        cout << left << "|";
        print_date(records[i].date.day, records[i].date.month, records[i].date.year, 11);
        cout << "|";
        cout << endl;
    }

    cout.width(79); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(78); cout << left << "|Note: it is possible to get a StarOffice product for free via the Internet"; cout << "|" << endl;
    cout.width(79); cout.fill('-'); cout << "-" << endl;
}

void find_min_value(Records* records) {
    min_quantity = records[0].quantity;
    for (int i = 1; i < 3; i++) {
        if (min_quantity > records[i].quantity) {
            min_quantity = records[i].quantity;
        }
    }

    min_price = records[0].price;
    for (int i = 1; i < 3; i++) {
        if (min_price > records[i].price) {
            min_price = records[i].price;
        }
    }
}


int main() {

    setlocale(LC_ALL, "Russian");

    struct Records records[3];
    records[0] = { "Office", "Microsoft", 4, 870.99, {11,01,2011} };
    records[1] = { "SmartSute", "Lotus", 5, 1020.99, {21,12,2012} };
    records[2] = { "StarOffice", "Sun", 4, 9.99, {12,10,2020} };
    cout << "Исходные данные:" << endl;
    draw_table(records, 3);

    cout << "\n" << "Вариант задания: Добавить новую запись (элемент массива структур), содержащие минимальные числовые значения в столбцах." << "\n" << endl;
    cout << "Данные по варианту задания:" << endl;

    find_min_value(records);

    struct Records newRecords[4];
    for (int i = 0; i < 3; i++) {
        newRecords[i] = records[i];
    }
    newRecords[3] = {"NULL","NULL", min_quantity, min_price, {11,11,1111} };
    draw_table(newRecords, 4);

    cout << endl;

    return 0;
}
