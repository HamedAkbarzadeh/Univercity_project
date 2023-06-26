#include "DateOfBirth.h"

DateOfBirth::DateOfBirth(string strDate) {
	converStringToInt(strDate);
}
DateOfBirth::DateOfBirth(int year , int mounth , int day) {
	setYear(year);
	setMounth(mounth);
	setDay(day);
}
void DateOfBirth::converStringToInt(string strDate) {
	int year = 0, mounth = 0, day = 0;

	this->fullDate = strDate;
	for (int i = 0; i <= 10; i++)
	{
		//year
		if (i >= 0 && i <= 4) {
			year += strDate[i] + (year * 10);
			setYear(year);
		}
		//mounth
		if (i >= 6 && i <= 7) {
			mounth += strDate[i] + (mounth * 10);
			setMounth(mounth);
		}
		//day
		if (i >= 9 && i <= 10) {
			day += strDate[i] + (day * 10);
			setDay(day);
		}
	}
}
void DateOfBirth::setYear(int year) {
	if (year > 2023 || year < 1910) {
		year = 2000;
	}
	this->year = year;
}
void DateOfBirth::setMounth(int mounth) {
	if (mounth > 12 || mounth < 0) {
		mounth = 01;
	}
	this->mounth = mounth;
}
void DateOfBirth::setDay(int day) {
	if (day > 31 || day < 0) {
		day = 01;
	}
	this->day = day;
}

string DateOfBirth::getFullDate() {
	return fullDate;
}
int DateOfBirth::getYear() {
	return year;
}
int DateOfBirth::getMounth() {
	return mounth;
}
int DateOfBirth::getDay() {
	return day;
}
