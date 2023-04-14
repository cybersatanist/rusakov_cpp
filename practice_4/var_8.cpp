#include <iostream>
#include <locale>
#include <fstream>
#include <string>

using namespace std;

FILE* file;
FILE* binaryFile;

struct Date {
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

struct Record {
    char transport[16];
    char route[9];
    float extent;
    unsigned int time;
    struct Date date;
};

void my_centr(string s, int wLine) {
    int w = s.length();
    int delta = (wLine - w) / 2;  
    cout << left;
    cout.width(delta); cout << " "; 
    cout << s; 
    cout.width(delta + 1); cout << " ";
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

void draw(Record* records, int n) {
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

    for (int i = 1; i < n; i++) {
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

void write_to_file_txt(Record* records) {
    file = fopen("Makarov.txt", "w+");
    for (int i = 1; i < 4; i++) {
        fprintf(file, "%s %s %f %d %d %d %d \n",
            records[i].transport,
            records[i].route,
            records[i].extent,
            records[i].time,
            records[i].date.day, records[i].date.month, records[i].date.year );
    }
    fclose(file);
}

void scan_from_file_txt(Record* records) {
    file = fopen("Makarov.txt", "r");
    for (int i = 1; i < 4; i++) {
        fscanf(file, "%s", records[i].transport);
        fscanf(file, "%s", records[i].route);
        fscanf(file, "%f", &records[i].extent);
        fscanf(file, "%d", &records[i].time);
        fscanf(file, "%hd", &records[i].date.day);
        fscanf(file, "%hd", &records[i].date.month);
        fscanf(file, "%hd", &records[i].date.year);
    }
    fclose(file);
}

void write_to_file_bin(Record* records) {
    binaryFile = fopen("Makarov.bin", "wb");
    fwrite(records, sizeof(records), 1, binaryFile);
    fclose(binaryFile);
}

void scan_from_file_bin(Record* records) {
    binaryFile = fopen("Makarov.bin", "rb");
    fread(records, sizeof(records), 1, binaryFile);
    fclose(binaryFile);
}

void write_newRecord_to_file_txt(Record* add_record) {
    file = fopen("Makarov.txt", "a");
    fprintf(file, "%s %s %f %d %d %d %d \n",
            add_record->transport,
            add_record->route,
            add_record->extent,
            add_record->time,
            add_record->date.day, add_record->date.month, add_record->date.year );
    fclose(file);
}

void swap_values(Record* records) {
    int index;
    for (int i = 0; i < 5; i++) {
        if (records[i].date.day % 2 == 0) {
            index = i;
            break;
        }
    }
    for (int i = 0; i < 5; i++) {
        if ((records[i].date.day % 2 == 0) and i != index) {
            swap(records[i].date.day, records[index].date.day);
            swap(records[i].date.month, records[index].date.month);
            break;
        }
   }
}

void swap_file_values_txt(Record* add_record) {
    file = fopen("Makarov.txt", "r");
    for (int i = 1; i < 5; i++) {
        fscanf(file, "%s", add_record[i].transport);
        fscanf(file, "%s", add_record[i].route);
        fscanf(file, "%f", &add_record[i].extent);
        fscanf(file, "%d", &add_record[i].time);
        fscanf(file, "%hd", &add_record[i].date.day);
        fscanf(file, "%hd", &add_record[i].date.month);
        fscanf(file, "%hd", &add_record[i].date.year);
    }
    fclose(file);

    swap_values(add_record);
    
    file = fopen("Makarov.txt", "w+");
    for (int i = 1; i < 5; i++) {
        fprintf(file, "%s %s %f %d %d %d %d \n",
            add_record[i].transport,
            add_record[i].route,
            add_record[i].extent,
            add_record[i].time,
            add_record[i].date.day, add_record[i].date.month, add_record[i].date.year );
    }
    fclose(file);
}

int main() 
{

    setlocale(LC_ALL, "Russian");

    struct Record records[5];

    cout << "\n" << "Исходная таблица";
    records[1] = { "Tr.", "12", 27.550, 75, {06,66,2021} };
    records[2] = { "T-s", "17", 13.600, 57, {03,04,2020} };
    records[3] = { "A", "12a", 57.300, 117, {04,77,2022} };
    draw(records, 4);

    cout << "\n\n" << "     Этап I\n" << endl;

    struct Record add_record[4] = { "Tax", "135f", 34.590, 94, {01,01,2021} };        // Значение введенное с клавиатуры

    cout << "\n" << "Таблица из текстового файла";
    write_to_file_txt(records);
    scan_from_file_txt(records);
    draw(records, 4);

    cout << "\n" << "Таблица из бинарного файла";
    write_to_file_bin(records);
    scan_from_file_bin(records);
    draw(records, 4);

    cout << "\n\n" << "     Этап II\n" << endl;


    write_newRecord_to_file_txt(add_record);
    swap_file_values_txt(add_record);
    draw(add_record, 5);

}
