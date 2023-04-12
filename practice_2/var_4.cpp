#include <iostream>
#include <cstring>
#include <locale>

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

int main() 
{

    setlocale(LC_ALL, "Russian");

    struct Records records[3];

    records[0] = { "Office", "Microsoft", 4, 870.99, {11,01,2011} };
    records[1] = { "SmartSute", "Lotus", 5, 1020.99, {21,12,2012} };
    records[2] = { "StarOffice", "Sun", 4, 9.99, {12,10,2020} };

    Records* A;
    A = (Records*)malloc(3 * sizeof(Records));

    for (int i = 0; i < 3; i++) {
        A[i] = records[i];
    }

    Records** B;
    B = (Records**) new Records * [10];

    for (int i = 0; i <= 10; i++) {
        B[i] = (Records*) new Records;
        *(B[i]) = A[i];
    }

    A = (Records*)realloc(A, 10 * sizeof(Records));

    for (int i = 0; i < 3; i++) {
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> Name: " << A[i].name;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> Producer: " << A[i].producer;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> Quantity: " << A[i].quantity;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> Price: " << A[i].price;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> Day: " << A[i].date.day;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> Month: " << A[i].date.month;
        cout << endl << "Aдрес A[i] = " << &A[i] << "; A[i] -> Year: " << A[i].date.year;
        cout << "\n";
    }

        cout << "\n" << "\n" << endl;

    for (int i = 0; i < 3; i++) {
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> Name: " << B[i] -> name;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> Producer: " << B[i] -> producer;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> Quantity: " << B[i] -> quantity;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> Price: " << B[i] -> price;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> Day: " << B[i] -> date.day;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> Month: " << B[i] -> date.month;
        cout << endl << "Aдрес B[i] = " << &B[i] << "; B[i] -> Year: " << B[i] -> date.year << endl;
    }

    for (int i = 0; i <= 10; i++) {
        delete B[i];
    }

    delete[] B;
    free(A);
}
