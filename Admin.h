#pragma once

#ifndef Admin_H
#define Admin_H

#include "Person.h"

class Admin :public Person
{
public:
	Admin(string fname, string lname, string username, string password, string mobile, string DateOfBirth, string rule);
	
	Admin& operator = (Admin c);
	//set
	void setRule(string rule);
	virtual void setType();
	virtual void printPersonalInfo();
	//virtual void EditProfile(string fname, string lname, string mobile, string username, string date);

	
	//get
	int getType() { return type; }
private:

};

#endif // !Admin_H

