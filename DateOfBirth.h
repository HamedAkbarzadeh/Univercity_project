#ifndef DateOfBirth_H
#define DateOfBirth_H
#include <iostream>
#include <string>
using namespace std;

class DateOfBirth
{
	friend class Person;
public:
	DateOfBirth(string);
	DateOfBirth(int ,int ,int);
	
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


#endif // !DateOfBirth_H
