#include "Admin.h"

//operator
Admin& Admin::operator=(Admin c) {
	//string yearsOfStart
	this->id = c.id;
	this->fname = c.fname;
	this->lname = c.lname;
	this->mobile = c.mobile;
	this->username = c.username;
	this->password = c.password;
	this->type = c.type;
	this->rule = c.rule;
	this->date = c.date;
	return c;
}


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
	cout << endl << "\tFirst Name : " << fname << endl << "\tLast Name : " << lname 
		<< endl << "\tmobile : " << mobile 
		<< endl << "\tDate Of Birth : " << date.getFullDate() << endl << "\trule : " << rule 
		<< endl << "\tEmail : " << username << endl << "\tpassword : ";
	for (int i = 0; i <= passLen; i++)
	{
		cout << "*";
	}
	cout << endl << endl;
}
