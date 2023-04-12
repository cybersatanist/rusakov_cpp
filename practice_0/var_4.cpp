#include <iostream>
#include <locale>
#include <cstring>
#include <iomanip>

using namespace std;

struct Records {
    char name[11];
    char producer[10];
    unsigned int quantity;
    float price;
    char date[11];
} RECORDS[3];

void center(const char* s, int wLine) {
    int w = strlen(s);
    int delta = (wLine - w) / 2 - 1;
    cout << left;
    cout.width(delta); cout << " ";
    cout << s;
    cout.width(delta); cout << " ";
}

void draw_line() {
    for (int i = 0; i <= 78; i++) {
        cout << "-";
    }
    cout << "\n";
}

void draw_table_head() {
      draw_line();
      cout.width(78); cout << left << "|Office packages"; cout << "|" << endl;
      draw_line();
      cout << "|"; center("Name", 14); cout << "|";
      center("Producer", 16); cout << "|";
      center("Number of components", 26); cout << "|";
      center("Price ($)", 13); cout << "|";
      center("Date", 14); cout << "|" << endl;
      draw_line();
}

void draw_table_note() {
      cout.width(78); cout << left << "|Note: it is possible to get a StarOffice product for free via the Internet"; cout << "|" << endl;
      draw_line();
}

void entering_values(int i) {
    cout << "The input process " << i << " record" << endl;
    cout << "Name: "; cin >> RECORDS[i].name;
    cout << "Producer: "; cin >> RECORDS[i].producer;
    cout << "Number of components: "; cin >> RECORDS[i].quantity;
    cout << "Price ($): "; cin >> RECORDS[i].price;
    cout << "Date: "; cin >> RECORDS[i].date;
}

void print_strings(int i) {
    cout << "|" << left << setw(12) << RECORDS[i].name;
    cout << "|" << left << setw(14) << RECORDS[i].producer;
    cout.precision(2); cout << "|" << fixed << setw(24) << RECORDS[i].quantity;
    cout << "|" << left << setw(11) << RECORDS[i].price;
    cout << "| " << left << setw(11) << RECORDS[i].date;
    cout << "|" << endl;
    draw_line();
}

int main() {

    setlocale(LC_ALL, "Russian");

    entering_values(1); cout << endl;
    entering_values(2); cout << endl;
    entering_values(3); cout << endl;

    draw_table_head();

    print_strings(1);
    print_strings(2);
    print_strings(3);

    draw_table_note();

    cout << endl;

    return 0;
}
