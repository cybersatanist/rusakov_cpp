#include <iostream>
#include <cstring>
#include <locale>

using namespace std;

struct Date 
{
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Record 
{
    char transport[16];
    char route[9];
    float extent;
    unsigned int time;
    struct Date date;
};

void my_centr(string s, int wLine) 
{
    int w = s.length();
    int delta = (wLine - w) / 2;  
    cout << left;
    cout.width(delta); cout << " "; 
    cout << s; 
    cout.width(delta + 1); cout << " ";
}

void print_date(unsigned short day, unsigned short month, unsigned short year, int wLine) 
{
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

void draw(struct Record* records) 
{
    cout << endl; cout.width(94); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(125); cout << left << "|Ведомость общественного транспорта"; cout << "|" << endl;
    cout.width(94); cout.fill('-'); cout << "-" << endl;
    cout.fill(' ');

    cout << left << "|"; my_centr("Вид транспорта", 16);
    cout << left << "|"; my_centr("Маршрут", 9);
    cout << left << "|"; my_centr("Протяженность маршрута (км)", 29);
    cout << left << "|"; my_centr("Время в дороге (мин)", 22);
    cout << left << "|"; my_centr(" Дата", 15);
    cout << "|" << endl;
    cout.width(94); cout.fill('-'); cout << "-" << endl;
    cout.fill(' ');

    for (int i = 1; i < 4; i++) {
        cout << left << "|"; cout.width(16); cout << left << records[i].transport;
        cout << left << "|"; cout.width(9); cout << left << records[i].route;
        std::cout.precision(3); cout << "|"; cout.width(29); cout << right << fixed << records[i].extent;
        cout << left << "|"; cout.width(22); cout << left << records[i].time;
        cout << left << "|";
        print_date(records[i].date.day, records[i].date.month, records[i].date.year, 15);
        cout << "|";
        cout << endl;
    }

    cout.width(94); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(132); cout << left << "|Примечание: Тр - трамвай, Тс - троллейбус, А - автобус"; cout << "|" << endl;
    cout.width(94); cout.fill('-'); cout << "-" << endl;
}

void delete_string_values(struct Record* records) 
{
    for (int i = 1; i < 4; i++) {
        strcpy(records[i].transport, "");
        strcpy(records[i].route, "");
    }
}

int main() 
{

    setlocale(LC_ALL, "Russian");

    struct Record records[10];

    records[1] = { "Tr.", "12", 27.550, 75, {03,04,2022} };
    records[2] = { "T-s", "17", 13.600, 57, {03,04,2020} };
    records[3] = { "A", "12a", 57.300, 117, {04,03,2022} };
    cout << "Исходные данные:" << endl;
    draw(records);

    cout << "\n" << "Вариант задания: Удалить все записи (элементы массива структур), содержащее введенное строковое значение." << "\n" << endl;

    cout << "Данные по варианту задания:" << endl;
    delete_string_values(records);
    draw(records);
}
