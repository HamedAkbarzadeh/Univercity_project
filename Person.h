#ifndef Person_H
#define Person_H
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;
class Person
{
public:
	Person(string fname , string lname , string username, string password, string mobile);
	virtual void printPersonalInfo() = 0;
	void setPassword(string password);
	void setUsername(string username);
	void setMobile(string mobile);
	void setDatePerson(string strDate);

	//get 
	int getID() { return id; }
	string getFname() { return fname; }
	string getLname() { return lname; }
protected:
	static int idCounter;
	int id;
	string fname, lname, mobile , username, password;
	Date date;

};


#endif // !Person_H


