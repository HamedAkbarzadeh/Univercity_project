#include "Admin.h"


Admin::Admin(string fname, string lname, string username, string password, string mobile, string DateOfBirth, string rule)
	:Person(fname, lname, username, password, mobile, DateOfBirth) {
	setRule(rule);
	setType();
}
void Admin::setRule(string rule) {
	//rules = owner-admin-moderator-writer
	if (rule.find("owner") != string::npos 
		|| rule.find("admin") != string::npos
		|| rule.find("moderator") != string::npos
		|| rule.find("writer") != string::npos)
	{
		this->rule = rule;
	}
	else {
		this->rule = "admin";
	}
}
void Admin::setType() {
	this->type = 2;
}
void Admin::printPersonalInfo() {
	int passLen = size(password);
	cout << endl << "|*  ID : " << id
		<< endl << "|*  First Name : " << fname 
		<< endl << "|*  Last Name : " << lname 
		<< endl << "|*  mobile : " << mobile 
		<< endl << "|*  Date Of Birth : " << date.getFullDate() 
		<< endl << "|*  rule : " << rule 
		<< endl << "|*  Email : " << username 
		<< endl << "|*  password : ";
	for (int i = 0; i <= passLen; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
}

