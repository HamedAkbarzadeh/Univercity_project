#include "Person.h"
#include "DateOfBirth.h"

Person::Person(string fname, string lname, string username, string password , string moible){
	this->fname = fname;
	this->lname = lname;
	setPassword(password);
	setUsername(username);
	setMobile(mobile);
}
void Person::setPassword(string password) {
	int passlen = size(password);
	if (passlen < 7) {
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
	if (mobile.find("09") == string::npos || mobilelen < 12 || mobilelen >= 12) {
		mobile = "09121112233";
	}
	this->mobile = mobile;
}
void Person::setDatePerson(string strDate) {
	date.converStringToInt(strDate);
}