#include "Date.h"


//Constructor
Date::Date() {
	cout << endl << "**Date**" << endl;
}
Date::Date(string strDate) {
	converStringToInt(strDate);
}
Date::Date(int year, int mounth, int day) {
	setYear(year);
	setMounth(mounth);
	setDay(day);
}
//set

void Date::converStringToInt(string strDate) {
	int year = 0, mounth = 0, day = 0;

	this->fullDate = strDate;
	//for (int i = 0; i <= 10; i++)
	//{
	//	//year
	//	if (i >= 0 && i <= 4) {
	//		year += strDate[i] + (year * 10);
	//		setYear(year);
	//	}
	//	//mounth
	//	if (i >= 6 && i <= 7) {
	//		mounth += strDate[i] + (mounth * 10);
	//		setMounth(mounth);
	//	}
	//	//day
	//	if (i >= 9 && i <= 10) {
	//		day += strDate[i] + (day * 10);
	//		setDay(day);
	//	}
	//}
}
void Date::setYear(int year) {
	if (year > 2023 || year < 1910) {
		year = 2000;
	}
	this->year = year;
}
void Date::setMounth(int mounth) {
	if (mounth > 12 || mounth < 0) {
		mounth = 01;
	}
	this->mounth = mounth;
}
void Date::setDay(int day) {
	if (day > 31 || day < 0) {
		day = 01;
	}
	this->day = day;
}
//get
string Date::getFullDate() {
	return fullDate;
}
int Date::getYear() {
	return year;
}
int Date::getMounth() {
	return mounth;
}
int Date::getDay() {
	return day;
}
