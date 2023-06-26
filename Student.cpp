#include "Student.h"
#include "Date.h"

//operator
Student& Student::operator=(Student c) {
	//string yearsOfStart
	this->id = c.id;
	this->fname = c.fname;
	this->lname = c.lname;
	this->mobile = c.mobile;
	this->username = c.username;
	this->password = c.password;
	this->dateOfEnter = c.dateOfEnter;
	this->date = c.date;
	return c;
}

int Student::StudentNumbercounter = 401133100;
Student::Student(string fname, string lname, string username, string password, string moible,string yearsOfStart)
	: Person(fname, lname, username, password, moible) {
	studentNumber = StudentNumbercounter++;

	dateOfEnter.converStringToInt(yearsOfStart);
}
void Student::printPersonalInfo() {
	cout << endl << "\tFirst Name : " << fname << endl << "\tLast Name : " << lname << endl << "\tmobile : " << mobile << endl << "\tStudent Number : " << studentNumber << endl << endl;
}