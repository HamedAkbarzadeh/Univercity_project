#include "Date.h"


//Constructor
Date::Date() {
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
	string y, m, d;
	y = strDate.substr(0, 4);
	m = strDate.substr(5, 6);
	d = strDate.substr(8, 9);
	setYear(stoi(y));
	setMounth(stoi(m));
	setDay(stoi(d));
	this->fullDate = to_string(getYear()) + " / " + to_string(getMounth()) + " / " + to_string(getDay());
}
void Date::setYear(int year) {
	if (year > 1402 || year < 1300) {
		year = 1380;
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
