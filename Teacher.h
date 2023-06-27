#pragma once
#ifndef Teacher_H
#include "Person.h"
#include "Date.h"
#define Teacher_H

class Teacher : public Person
{
public:
	Teacher(string fname, string lname, string username,
		string password, string mobile, string DateOfBirth , float salary);
	//virtual
	virtual void printPersonalInfo();
	virtual void setType();
	//set
	void setSalary(float salary);
	//get
	float getSalary() { return salary; }
private:
	float salary;
};


#endif // !Teacher_H
