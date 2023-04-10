#include <iostream>
#include <iomanip>
#include <locale>
#include <cstring>

using namespace std;

struct Data 
{
    char transport[16];
    char route[9];
    float extent;
    int time;
    char date[10];
} Data[3];

void my_center(const char* s, int wLine) 
{
    int w = strlen(s);
    int delta = (wLine - w) / 2 - 1;
    cout << left;
    cout.width(delta); cout << " ";
    cout << s;
    cout.width(delta); cout << " ";
}

void draw_line() 
{
    cout << "+--------------------------------------------------------------------------------------------+" << endl;
}

void header() 
{
      draw_line();
      cout.width(125); cout << left << "|Ведомость общественного транспорта"; cout << "|" << endl;
      draw_line();
      cout << "| Вид транспорта |";
      cout << " Маршрут |";
      cout << " Протяженность маршрута (км) |";
      cout << " Время в дороге (мин) |";
      my_center("Дата", 18); cout << "|" << endl;
      draw_line();
}

void note() 
{
      cout.width(132); cout << left << "|Примечание: Тр - трамвай, Тс - троллейбус, А - автобус"; cout << "|" << endl;
      draw_line();
}

void inputValues(int i) 
{
    cout << "Ввод значений " << i << " записи" << endl;
    cout << "Вид транспорта: ";
    cin >> Data[i].transport;
    cout << "Маршрут: ";
    cin >> Data[i].route;
    cout << "Протяженность: ";
    cin >> Data[i].extent;
    cout << "Время: ";
    cin >> Data[i].time;
    cout << "Дата: ";
    cin >> Data[i].date;
}

void printStrings(int i) 
{
    cout << "|" << left << setw(16) << Data[i].transport;
    cout << "|" << left << setw(9) << Data[i].route;
    cout.precision(3); cout << "|" << right << fixed << setw(29) << Data[i].extent;
    cout << "|" << left << setw(22) << Data[i].time;
    cout << "| " << left << setw(11) << Data[i].date;
    cout << "|" << endl;
    draw_line();
}

int main() 
{

    setlocale(LC_ALL, "Russian");

    inputValues(1);
    cout << endl;
    inputValues(2);
    cout << endl;
    inputValues(3);
    cout << endl;

    header();

    printStrings(1);
    printStrings(2);
    printStrings(3);

    note();

    cout << endl;

    return 0;
}
