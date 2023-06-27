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
	virtual void setType();
	virtual void printPersonalInfo();
	void setRule(string rule);
	
	//get
	int getType() { return type; }
	string getRule() { return rule; }
private:
	string rule; //rules = owner-admin-moderator-writer

};

#endif // !Admin_H

