#include <iostream>
#include <locale>
#include <string>

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

class clDate
{

private:
	unsigned short day;
    unsigned short month;
    unsigned short year;
public:

	char delimiter = '.';

    clDate()
    {
    	setDate(1, 1, 1666);
    }

    clDate(unsigned short day, unsigned short month, unsigned short year)
    {
    	setDate(day, month, year);
    }

    clDate(struct Date* pDate)
	{
		day = pDate->day; month = pDate->month; year = pDate->year;
	}

    // Деструктор
    ~clDate() {;}

    void setDate(unsigned short day, unsigned short month, unsigned short year) {
        this->day = day;
    	this->month = month;
    	this->year = year;
    }

    Date getDate()
    {
        Date date = {day, month, year};
        return date;
    }

    void printDate() {
		if (this->day > 0 and this->day < 10)
			cout << "0";
		cout << day << this->delimiter;
		if (this->month > 0 and this->month < 10)
			cout << "0";
		cout << month << this->delimiter << year << endl;
	}
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class clRecord
{
	string transport;

public:
	string route;

	clRecord() 
	{
		transport = "";
        route = "";
        extent = 0.0;
        time = 0;
        date.setDate(1, 1, 2000);
	}

	clRecord(string file) {;}

	clRecord(Record* records) 
	{
		transport = records->transport;
        route = records->route;
        extent = records->extent;
        time = records->time;
        date.setDate(records->date.day, records->date.month, records->date.year);
	}

	void setTransport(string transport)
    {
        this->transport = transport;
    }

    void setExtent(float extent)
    {
        this->extent = extent;
    }

    void setTime(unsigned int time)
    {
        this->time = time;
    }

    void setDate(clDate date)
    {
        this->date = date;
    }

    void printRecord()
    {
        cout << transport << ", " << route << ", " << extent << ", " << time << ", ";
        date.printDate();
        cout << endl;
    }

private:
	float extent;

protected:
	unsigned int time;
	clDate date;
};

int main() {

	struct Date dates[4];

	dates[1] = {03,04,2022};
    dates[2] = {03,05,2020};
    dates[3] = {04,03,2022};

	clDate date1;						// Конструктор по умолчанию
	cout << "date1: "; date1.printDate(); cout;

	clDate date2(12, 12, 2021);			// Конструктор с параметрами
	cout << "date2: "; date2.printDate(); cout;

	clDate date3(&dates[1]); 			// Конструктор с параметрами на основе структуры
	cout << "date3: "; date3.printDate(); cout << endl;

	// Создание динамического объекта с использованием конструктора по умолчанию и освобождение памяти
	clDate* pDate0 = new clDate();
	delete pDate0;

	// Создание объекта на основе конструктора копирования и увеличение даты на 5 дней
	clDate date4 = date2;
	date4.setDate(date4.getDate().day + 5, date4.getDate().month + 5, date4.getDate(). year + 5);
	cout << "date2 + 5: "; date4.printDate();

	// Проверка допустимости новой даты
	if (date4.getDate().day > 31 or date4.getDate().month > 12) {
    	cout << "Недопустимая дата!\n";
    	date4.setDate(date2.getDate().day, date2.getDate().month, date2.getDate().year);
    	cout << "date2 - 5: "; date2.printDate();
	}

	cout << "_______________________________________________" << endl;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	struct Record records[] = {
		{ "Tr.", "12", 27.550, 75, {03,04,2022} },
  		{ "T-s", "17", 13.600, 57, {03,04,2020} },
  		{ "A", "12a", 57.300, 117, {04,03,2022} },
  	};

    clRecord staticRecord(records);		// Статический объект класса clRecord
    staticRecord.printRecord();

    clRecord* dynamicRecord = new clRecord(&records[1]);	// Динамический объект класса clRecord

    dynamicRecord->setTransport("Taxi");
    dynamicRecord->setExtent(55.400);
    dynamicRecord->setTime(81);

    clDate newDate(11, 10, 2021);
    dynamicRecord->setDate(newDate);

    dynamicRecord->printRecord();
    delete dynamicRecord;

    clRecord recordsArray[3];					// Массив объектов класса clRecord
    for (int i = 0; i < 3; i++)
    {
        recordsArray[i] = clRecord(&records[i]);
        recordsArray[i].printRecord();
    }
    
	return 0;
}
