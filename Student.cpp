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
	this->type = c.type;
	return c;
}

int Student::StudentNumbercounter = 401133100;
Student::Student(string fname, string lname, string username, string password, string moible, string DateOfBirth,string yearsOfStart)
	: Person(fname, lname, username, password, moible, DateOfBirth) {
	studentNumber = StudentNumbercounter++;

	dateOfEnter.converStringToInt(yearsOfStart);
}
void Student::printPersonalInfo() {
	int passLen = size(password);
	cout << endl << "\tID : " << id
		<< endl << "\tFirst Name : " << fname 
		<< endl << "\tLast Name : " << lname
		<< endl << "\tmobile : " << mobile
		<< endl << "\tStudent Number : " << getStudentNumber()
		<< endl << "\tDate Of Birth : " << date.getFullDate() 
		<< endl << "\tDate Of Enter To Univercity : " << dateOfEnter.getFullDate()
		<< endl << "\tEmail : " << username << endl << "\tpassword : ";
	for (int i = 0; i <= passLen; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
}
void Student::setType() {
	this->type = 0;
}