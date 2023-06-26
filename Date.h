#ifndef Date_H
#define Date_H
#include <iostream>
#include <string>
using namespace std;

class Date
{
	friend class Person;
	friend class Student;
public:
	Date();
	Date(string);
	Date(int, int, int);

	void converStringToInt(string);
	void setYear(int);
	void setMounth(int);
	void setDay(int);

	string getFullDate();
	int getYear();
	int getMounth();
	int getDay();

private:
	string fullDate;
	int year, mounth, day;
};


#endif // !Date_H
