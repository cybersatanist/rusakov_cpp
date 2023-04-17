#include <iostream>
#include <locale>
#include <string>

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

class clDate {

private:

	unsigned short day;
    unsigned short month;
    unsigned short year;

public:

	char delimiter = '.';

    clDate() {
    	set_date(3, 3, 1333);
    }

    clDate(struct Date* pDate) {
        day = pDate->day; month = pDate->month; year = pDate->year;
    }

    clDate(unsigned short day, unsigned short month, unsigned short year) {
    	set_date(day, month, year);
    }

    ~clDate() {;}

    void set_date(unsigned short day, unsigned short month, unsigned short year) {
        this->day = day;
    	this->month = month;
    	this->year = year;
    }

    Date get_date()
    {
        Date date = {day, month, year};
        return date;
    }

    void print_date() {
		if (this->day > 0 and this->day < 10)
			cout << "0";
		cout << day << this->delimiter;
		if (this->month > 0 and this->month < 10)
			cout << "0";
		cout << month << this->delimiter << year << endl;
	}
};

class clRecord {

	string name;

public:

	string producer;

	clRecord() {
		name = "";
        producer = "";
        quantity = 0;
        price = 0.0;
        date.set_date(1, 1, 1000);
	}

	clRecord(string file) {;}

	clRecord(Records* records) {
		name = records->name;
        producer = records->producer;
        quantity = records->quantity;
        price = records->price;
        date.set_date(records->date.day, records->date.month, records->date.year);
	}

	void set_name(string name) {
        this->name = name;
    }

    void set_producer(string producer) {
        this->producer = producer;
    }

    void set_quantity(unsigned int quantity) {
        this->quantity = quantity;
    }

    void set_price(float price) {
        this->price = price;
    }

    void set_date(clDate date) {
        this->date = date;
    }

    void print_record() {
        cout << name << ", " << producer << ", " << quantity << ", " << price << ", ";
        date.print_date();
        cout << endl;
    }

private:

	unsigned int quantity;

protected:

	float price;
	clDate date;
};

int main() {

	struct Date dates[4];

	dates[1] = {11,01,2011};
    dates[2] = {21,12,2012};
    dates[3] = {12,10,2020};

	clDate date1;
	cout << "date1: "; date1.print_date(); cout;

	clDate date2(30, 4, 2024);
	cout << "date2: "; date2.print_date(); cout;

	clDate date3(&dates[1]);
	cout << "date3: "; date3.print_date(); cout << endl;

	
	clDate* pDate0 = new clDate();
	delete pDate0;

	
	clDate date4 = date2;
	date4.set_date(date4.get_date().day + 5, date4.get_date().month + 5, date4.get_date(). year + 5);
	cout << "date2 + 5: "; date4.print_date();

	
	if (date4.get_date().day > 31 or date4.get_date().month > 12) {
    	cout << "Недопустимая дата!\n";
    	date4.set_date(date2.get_date().day, date2.get_date().month, date2.get_date().year);
    	cout << "date2 - 5: "; date2.print_date();
	}

	cout << "_______________________________________________" << endl;


	struct Records records[] = {
	    { "Office", "Microsoft", 4, 870.99, {11,01,2011} },
        { "SmartSute", "Lotus", 5, 1020.99, {21,12,2012} },
        { "StarOffice", "Sun", 4, 9.99, {12,10,2020} },
  	};

    clRecord staticRecord(records);
    staticRecord.print_record();

    clRecord* dynamicRecord = new clRecord(&records[1]);

    dynamicRecord->set_name("Antivirus");
    dynamicRecord->set_producer("Kaspersky");
    dynamicRecord->set_quantity(100);
    dynamicRecord->set_price(99.65);

    clDate newDate(10, 10, 2010);
    dynamicRecord->set_date(newDate);

    dynamicRecord->print_record();
    delete dynamicRecord;

    clRecord recordsArray[3];
    for (int i = 0; i < 3; i++)
    {
        recordsArray[i] = clRecord(&records[i]);
        recordsArray[i].print_record();
    }
    
	return 0;
}
