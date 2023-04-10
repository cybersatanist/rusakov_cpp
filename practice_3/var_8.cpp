// В процессе

#include <iostream>
#include <locale>
#include <cstring>

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

void draw_line() 
{
    for (int i = 0; i <= 80; i++) {
        cout << "-";
    }
    cout << "\n";
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

struct Node
{
    Record data;
    Node *prev_item;
    Node *next_item;
};

struct Node *pPrev, *pTemp, *pCurrent, *pStart, *pEnd;
int count = -1;

void add_item(Record data)
{
    struct Node* pCurrent = new Node;
    pCurrent->data = data;
    if (count == -1) {
        count += 1;
        pStart = pCurrent;
        pEnd = pCurrent;
        pCurrent->prev_item = pCurrent;
        pCurrent->next_item = pCurrent;
        pTemp = pCurrent;
    }
    else {
        count += 1;
        pEnd = pCurrent;
        pCurrent->prev_item = pTemp;
        pCurrent->next_item = pTemp->next_item;
        pStart->prev_item = pEnd;
        pTemp->next_item = pCurrent;
        pTemp = pCurrent;
    }
}

void draw_table() 
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

    pCurrent = pStart;

    for (int i = 0; i <= count; i++) {
        cout << left << "|"; cout.width(16); cout << left << pCurrent->data.transport;
        cout << left << "|"; cout.width(9); cout << left << pCurrent->data.route;
        std::cout.precision(3); cout << "|"; cout.width(29); cout << right << fixed << pCurrent->data.extent;
        cout << left << "|"; cout.width(22); cout << left << pCurrent->data.time;
        cout << left << "|";
        print_date(pCurrent->data.date.day, pCurrent->data.date.month, pCurrent->data.date.year, 15);
        cout << "|";
        cout << endl;
        pCurrent = pCurrent->next_item;
    }

    cout.width(94); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(132); cout << left << "|Примечание: Тр - трамвай, Тс - троллейбус, А - автобус"; cout << "|" << endl;
    cout.width(94); cout.fill('-'); cout << "-" << endl;
}

int main()
{

    char value[5];
	setlocale(LC_ALL, "Russian");

    struct Record records[10];
    records[0] = { "Tr.", "12", 27.550, 75, {03,04,2022} };
    records[1] = { "T-s", "17", 13.600, 57, {03,04,2020} };
    records[2] = { "Tr.", "12a", 57.300, 117, {04,03,2022} };

    add_item(records[0]);	
    add_item(records[1]);
    add_item(records[2]);

    draw_table();

    struct Record newRecord = { "Tax", "A143", 12.120, 120, {05,05,2022} };         // Введенное значение с клавиатуры

    cout << "\n\nВведите строку, после которой нужно ввести значения: "; cin >> value;
    cout << "Ваша строка: " << value << endl;

    draw_table();

	return 0;
}
