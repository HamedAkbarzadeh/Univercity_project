#include "Teacher.h"

Teacher::Teacher(string fname, string lname, string username,
	string password, string mobile, string DateOfBirth, float salary)
	:Person(fname, lname, username, password, mobile, DateOfBirth) {
	salary = 0;
	setSalary(salary);
	this->type = 1;
}


//virtual
void Teacher::printPersonalInfo() {
	if (getSoftDeleted() == 0) {

		int passLen = size(password);
		cout << endl << "|*  ID : " << id
			<< endl << "|*  First Name : " << fname
			<< endl << "|*  Last Name : " << lname
			<< endl << "|*  Mobile : " << mobile
			<< endl << "|*  Salary : " << salary
			<< endl << "|*  Date Of Birth : " << date.getFullDate()
			<< endl << "|*  Email : " << username
			<< endl << "|*  Password : ";
		for (int i = 0; i < passLen; i++)
		{
			cout << "*";
		}
		cout << endl << endl;
	}

}
void Teacher::setType() {
	this->type = 1;
}
void Teacher::getSoftDeletedUsers() {
	if (getSoftDeleted() == 1) {
		int passLen = size(password);
		cout << endl << "|*  ID : " << id
			<< endl << "|*  First Name : " << fname
			<< endl << "|*  Last Name : " << lname
			<< endl << "|*  mobile : " << mobile
			<< endl << "|*  Date Of Birth : " << date.getFullDate()
			<< endl << "|*  rule : " << rule
			<< endl << "|*  Email : " << username
			<< endl << "|*  password : ";
		for (int i = 0; i < passLen; i++)
		{
			cout << "*";
		}
		cout << endl << endl;
	}
};