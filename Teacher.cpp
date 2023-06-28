#include "Teacher.h"

Teacher::Teacher(string fname, string lname, string username,
	string password, string mobile, string DateOfBirth, float salary) 
	:Person(fname,lname,username,password,mobile,DateOfBirth) {
	salary = 0;
	setSalary(salary);
	this->type = 1;
}


//virtual
void Teacher::printPersonalInfo() {
	int passLen = size(password);
	cout << endl << "|*  ID : " << id
		<< endl << "|*  First Name : " << fname
		<< endl << "|*  Last Name : " << lname
		<< endl << "|*  Mobile : " << mobile
		<< endl << "|*  Salary : " << salary
		<< endl << "|*  Date Of Birth : " << date.getFullDate()
		<< endl << "|*  Email : " << username
		<< endl << "|*  Password : ";
	for (int i = 0; i <= passLen; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
}
void Teacher::setType() {
	this->type = 1;
}