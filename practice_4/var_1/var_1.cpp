#include <iostream>
#include <locale>
#include <fstream>
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

    for (int i = 1; i < count; i++) {
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

void write_to_file_txt(Records* records) {
    ofstream file;
    file.open("Yakovlev.txt");
    for (int i = 1; i < 4; i++) {
        file << records[i].name << " ";
        file << records[i].producer << " ";
        file << records[i].quantity << " ";
        file << records[i].price << " ";
        file << records[i].date.day << " ";
        file << records[i].date.month << " ";
        file << records[i].date.year << " ";
        file << "\n";
    }
    file.close();
}

void read_from_file_txt(Records* records) {
    ifstream file;
    file.open("Yakovlev.txt");
    for (int i = 1; i < 4; i++) {
        file >> records[i].name;
        file >> records[i].producer;
        file >> records[i].quantity;
        file >> records[i].price;
        file >> records[i].date.day;
        file >> records[i].date.month;
        file >> records[i].date.year;
    }
    file.close();
}

void write_to_file_bin(Records* records, int num) {
    ofstream file("Yakovlev.bin", ios_base::out | ios_base::binary);
    for (int i = 1; i < num; i++) {
        file.write((char*)&records[i].name, sizeof(records[i].name));
        file.write((char*)&records[i].producer, sizeof(records[i].producer));
        file.write((char*)&records[i].quantity, sizeof(records[i].quantity));
        file.write((char*)&records[i].price, sizeof(records[i].price));
        file.write((char*)&records[i].date.day, sizeof(records[i].date.day));
        file.write((char*)&records[i].date.month, sizeof(records[i].date.month));
        file.write((char*)&records[i].date.year, sizeof(records[i].date.year));
    }
    file.close();
}

void read_from_file_bin(Records* records, int num) {
    ifstream file("Yakovlev.bin", ios_base::in | ios_base::binary);
    for (int i = 1; i < num; i++) {
        file.read((char*)&records[i].name, sizeof(records[i].name));
        file.read((char*)&records[i].producer, sizeof(records[i].producer));
        file.read((char*)&records[i].quantity, sizeof(records[i].quantity));
        file.read((char*)&records[i].price, sizeof(records[i].price));
        file.read((char*)&records[i].date.day, sizeof(records[i].date.day));
        file.read((char*)&records[i].date.month, sizeof(records[i].date.month));
        file.read((char*)&records[i].date.year, sizeof(records[i].date.year));
    }
    file.close();
}



int main() {

    setlocale(LC_ALL, "Russian");

    struct Records records[5];

    cout << "\n" << "Исходная таблица";
    records[1] = { "Office", "Microsoft", 4, 870.99, {11,01,2011} };
    records[2] = { "SmartSute", "Lotus", 5, 1020.99, {21,12,2012} };
    records[3] = { "StarOffice", "Sun", 4, 9.99, {12,10,2020} };
    records[4] = {"Minecraft", "Mojang", 5, 25.99, {10,11,2023} };         // Значение введенное с клавиатуры
    draw_table(records, 4);

    cout << "\n\n" << "     Этап I\n" << endl;

    cout << "\n" << "Таблица из текстового файла";
    write_to_file_txt(records);
    read_from_file_txt(records);
    draw_table(records, 4);

    cout << "\n" << "Таблица из бинарного файла";
    write_to_file_bin(records, 4);
    read_from_file_bin(records, 4);
    draw_table(records, 4);

    cout << "\n\n" << "     Этап II\n" << endl;

    write_to_file_bin(records, 5);

    swap(records[2].name, records[4].name);
    swap(records[2].producer, records[4].producer);
    
    write_to_file_bin(records, 5);
    draw_table(records, 5);

    return 0;
}
