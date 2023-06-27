#ifndef Student_H
#define Student_H

#include "Person.h"
#include "Date.h"
#include "Course.h"
#include "Term.h"

class Student :public Person
{
public:
	Student(string fname, string lname, string username, string password, string moible, string DateOfBirth, string yearsOfStart);
	virtual void printPersonalInfo();
	virtual void setType();
	Student& operator = (Student c);
private:
	static int StudentNumbercounter;
	int studentNumber;
	Date dateOfEnter;
	//Term term;
};

#endif // !Student_H
