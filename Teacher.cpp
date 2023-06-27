#include "Teacher.h"

Teacher::Teacher(string fname, string lname, string username,
	string password, string mobile, string DateOfBirth, float salary) 
	:Person(fname,lname,username,password,mobile,DateOfBirth) {
	setSalary(salary);
	this->type = 1;
}
void Teacher::setSalary(float salary) {
	if (salary < 0) {
		salary = 0;
	}
}

//virtual
void Teacher::printPersonalInfo() {
	int passLen = size(password);
	cout << endl << "\tID : " << id
		<< endl << "\tFirst Name : " << fname 
		<< endl << "\tLast Name : " << lname
		<< endl << "\tMobile : " << mobile
		<< endl << "\tSalary : " << salary
		<< endl << "\tDate Of Birth : " << date.getFullDate()
		<< endl << "\tEmail : " << username 
		<< endl << "\tPassword : ";
	for (int i = 0; i <= passLen; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
}
void Teacher::setType() {
	this->type = 1;
}