#include <iostream>
#include <locale>
#include <cstring>

using namespace std;

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

struct Node *pHead;
int count = 0;

struct Node
{
    Records data;
    Node *next_item;
};

void add_item(Records data) {
    struct Node* newNode = new Node();
    newNode->data = data;
    if (count == 0) {
        newNode->next_item = NULL;

    }
    else {
        newNode->next_item = pHead;
    }
    pHead = newNode;
    count++;
}

void find_and_delete(char value[10]) 
{
    struct Node* pCurrent = pHead;
    while (pCurrent) {
        if (strcmp(pCurrent->data.name, value) == 0) {
            strcpy(pCurrent->data.name, "");
        }
        if (strcmp(pCurrent->data.producer, value) == 0) {
            strcpy(pCurrent->data.producer, "");
        }
        pCurrent = pCurrent->next_item;
    }
}

void draw_table() 
{
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

    struct Node* pCurrent = pHead;

    while (pCurrent) {
        cout << "|"; cout.width(12); cout << left << pCurrent->data.name;
        cout << "|"; cout.width(14); cout << left << pCurrent->data.producer;
        cout << "|"; cout.width(24); cout << left << pCurrent->data.quantity;
        std::cout.precision(2); cout << "|"; cout.width(11); cout << left << fixed << pCurrent->data.price;
        cout << "|"; print_date(pCurrent->data.date.day, pCurrent->data.date.month, pCurrent->data.date.year, 15);
        cout << "|" << endl;
        pCurrent = pCurrent->next_item;
    }

    cout.width(79); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(78); cout << left << "|Note: it is possible to get a StarOffice product for free via the Internet"; cout << "|" << endl;
    cout.width(79); cout.fill('-'); cout << "-" << endl;
}

int main()
{

    setlocale(LC_ALL, "Russian");

    char value[10];

    struct Records records[10];
    records[1] = { "StarOffice", "Sun", 4, 9.99, {12,10,2020} };
    records[2] = { "SmartSute", "Lotus", 5, 1020.99, {21,12,2012} };
    records[3] = { "Office", "Microsoft", 4, 870.99, {11,01,2011} };

    add_item(records[1]);	
    add_item(records[2]);
    add_item(records[3]);

    draw_table();

    cout << "\n\nEnter the line you want to delete: "; cin >> value;

    find_and_delete(value);

    draw_table();

	return 0;
}
