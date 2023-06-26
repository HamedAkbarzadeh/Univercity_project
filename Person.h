#ifndef Person_H
#define Person_H
#include <iostream>
#include <string>
#include "DateOfBirth.h"

using namespace std;
class Person
{
public:
	Person(string fname , string lname , string username, string password, string moible);
	virtual void printPersonalInfo() = 0;
	void setPassword(string password);
	void setUsername(string username);
	void setMobile(string mobile);
	void setDatePerson(string strDate);
private:
	string username, password;
protected:
	string fname, lname, mobile;
	DateOfBirth date;

};


#endif // !Person_H


