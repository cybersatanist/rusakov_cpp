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

int main() 
{

    setlocale(LC_ALL, "Russian");

    struct Record records[3];

    records[0] = { "Tr.", "12", 27.550, 75, {03,04,2022} };
    records[1] = { "T-s", "17", 13.600, 57, {03,04,2020} };
    records[2] = { "A", "12a", 57.300, 117, {04,03,2022} };

    Record* A;
    A = (Record*)malloc(3 * sizeof(Record));

    for (int i = 0; i < 3; i++) {
        A[i] = records[i];
    }

    Record** B;
    B = (Record**) new Record * [10];

    for (int i = 0; i <= 10; i++) {
        B[i] = (Record*) new Record;
        *(B[i]) = A[i];
    }

    A = (Record*)realloc(A, 10 * sizeof(Record));

    for (int i = 0; i < 3; i++) {
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> transport: " << A[i].transport;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> route: " << A[i].route;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> extent: " << A[i].extent;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> time: " << A[i].time;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> day: " << A[i].date.day;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> month: " << A[i].date.month;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> year: " << A[i].date.year;
        cout << "\n";
    }

        cout << "\n" << "\n" << endl;

    for (int i = 0; i < 3; i++) {
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> transport: " << B[i] -> transport;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> transport: " << B[i] -> route;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> transport: " << B[i] -> extent;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> transport: " << B[i] -> time;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> transport: " << B[i] -> date.day;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> transport: " << B[i] -> date.month;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> transport: " << B[i] -> date.year << endl;
    }

    for (int i = 0; i < 10; i++) {
        delete B[i];
    }

    delete[] B;
    free(A);
}
