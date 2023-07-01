#include "Person.h"
#include "Date.h"
//operator


int Person::idCounter = 0;
Person::Person(string fname, string lname, string username, string password , string mobile, string DateOfBirth){
	this->id = idCounter++;
	this->fname = fname;
	this->lname = lname;
	setPassword(password);
	setUsername(username);
	setMobile(mobile);
	date.converStringToInt(DateOfBirth);
}
void Person::setPassword(string password) {
	int passlen = size(password);
	if (passlen < 6) {
		password = "123456";
	}
	this->password = password;
}
void Person::setUsername(string username) {
	if (username.find("@") == string::npos) {
		username = "123456@";
	}
	this->username = username;
}
void Person::setMobile(string mobile) {
	int mobilelen = size(mobile);
	if (mobile.find("09") == string::npos || mobilelen != 11) {
		mobile = "09121112233";
	}
	this->mobile = mobile;
}
void Person::setDatePerson(string strDate) {
	date.converStringToInt(strDate);
}
void Person::setSalary(float salary) {
	if (salary < 0) {
		salary = 0;
	}
	this->salary = salary;
}
//virtual
void Person::EditProfile(string fname, string lname, string mobile, string username, string date) {
	this->fname = fname;
	this->lname = lname;
	setMobile(mobile);
	setUsername(username);
	setDatePerson(date);
}
