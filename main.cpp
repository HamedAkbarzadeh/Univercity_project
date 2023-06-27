﻿#include "Course.h"
#include "Date.h"
#include "Person.h"
#include "Student.h"
#include "Term.h"
#include "Admin.h"
#include <conio.h>

/////prototype/////
//auth
void LoginRegisterForm();
void LoginForm();
void RegisterForm();
void RegisterTeacherForm();
void RegisterStudentForm();
int LoginCheck(string, string);
void logout();
//Admin Panel
void AdminPanel();
void InsertTerm();
void InsertCourse();
void showStudents();
void showTeachers();
void searchInUsers();
void searchByID();
void searchByName();
void InsertAdmin();
void showCourse();
void showTerm();
void returnAdminMenu();
void deleteUser();
//Student Panel
void StudentPanel();
//TeacherPanel
//void TeacherPanel();

/////global/////
static int userCounter = 1;
static int courseCounter = -1;
static int termCounter = -1;
	//Person
	Person** person = new Person * [100];
	Course* course = new Course[100];
	Term* term = new Term[100];
	/* info For User 
	person[0] == currentUserLogin
	person[1] == defualtAdmin
	*/

int main() {
	system("CLS");

	person[1] = new Admin("Hamed" , "Akbarzadeh" , "hmd@gmail.com" , "123456" , "09331434614" , "1382/27/09", "owner");
	LoginRegisterForm();
	return 0;
}
//Auth
void LoginRegisterForm() {
	system("CLS");
	int chooseNum;
	cout << "Welcome To Univercity ..." << endl;
	cout << "1-login" << endl << "2-Register" << endl;
	cin >> chooseNum;
	switch (chooseNum)
	{
	case 1:
		LoginForm();
		break;
	case 2:
		RegisterForm();
		break;

	default:
		cout << "please Enter Number (1 or 2)" << endl;
		break;
	}
}
void LoginForm() {
	system("CLS");
	string username, password;
	int type;

	cout << "*** Login ***" << endl;
	
	while (true) {
		cout << "Email : ";
		cin >> username;
		cout << endl << "password : ";
		cin >> password;
		type = LoginCheck(username, password);
		if (type == -1) {
			cout << endl << endl << "The username or password is incorrect !!" << endl << endl;
			continue;
		}
		break;
		
	}
	
	switch (type)
	{
	case 0:
		StudentPanel();
		break;
	case 1:
		//TeacherPanel();
		break;
	case 2:
		AdminPanel();
		break;

	default:
		break;
	}
}
void RegisterForm() {
	system("CLS");
	int chooseNum;
	cout << "Register Form" << endl << endl;
	cout << "1-I'm Teacher" << endl;
	cout << "2-I'm Student" << endl;
	cin >> chooseNum;
	switch (chooseNum)
	{
	case 1:
		RegisterTeacherForm();
		break;
	case 2:
		RegisterStudentForm();
		break;

	default:
		cout << "please Enter Number (1 or 2)" << endl;
		break;
	}
}
int LoginCheck(string username, string password) {
	for (int i = 1; i <= userCounter; i++)
	{
		if (person[i]->getUsername() == username && person[i]->getPassword() == password) {
			person[0] = person[i];
			return person[i]->getType();
		}
	}
	return -1;
}
void logout() {
	person[0] = NULL;
	LoginRegisterForm();
}
//Teacher
void RegisterTeacherForm() {
	system("CLS");

}
//Student
void RegisterStudentForm() {
	system("CLS");
	int statusPass = true;
	string fname, lname, mobile, username, password, passwordConfirm , yearsOfStart , dateOfBirth;
	//string fname, string lname,string username,string password,string mobile
	cout << "Register Form (Student)" << endl << endl;
	cout << endl << "1-First Name : ";
	cin >> fname;
	cout << endl << "2-Last Name : ";
	cin >> lname;
	cout << endl << "3-Date of Birthday( example : 1382/27/09 ) ";
	cin >> dateOfBirth;
	cout << endl << "3-Date of entering the university ( example : 1400/02/12 ) ";
	cin >> yearsOfStart;
	cout << endl << "4-Mobile : ";
	cin >> mobile;
	cout << endl << "5-email : (Must be used inside email @) : ";
	cin >> username;

	while (statusPass) {
		cout << endl << "6-password : (The minimum length of the password should be 6) : ";
		cin >> password;
		cout << endl << "7-Confirm-Password : ";
		cin >> passwordConfirm;
		if (password == passwordConfirm) {
			break;
		}
		cout << endl << "The password must be equal to the Confirm-Password" << endl;
	}
	person[++userCounter] = new Student(fname , lname , username , password ,mobile , dateOfBirth, yearsOfStart);
	person[0] = NULL;
	person[0] = person[userCounter];
	StudentPanel();
}
void StudentPanel() {
	system("CLS");
	int chooseNum;
	cout << "*** Welcome "<< person[0]->getFname() << " " << person[0]->getLname() <<" To Student Panel ***" << endl << endl;
	cout << "1-Select course" << endl << "2-View the list of class members" << endl << "3-Show score" << endl << "0-logout" << endl;
	cin >> chooseNum;
	switch (chooseNum)
	{
	case 1:
		
		break;
	case 2:

		break;
	case 3:

		break;
	case 0:
		logout();
		break;
	default:
		cout << endl << "please Enter number between (1-3)" << endl;
		break;
	}
}

//Admin
void AdminPanel() {
	system("CLS");
	int chooseNum;
	cout << "*** Welcome " << person[0]->getFname() << " " << person[0]->getLname() << " To Admin Panel ***" << endl << endl;
	cout << "1-Insert New Admin" 
		<< endl << "2-Show Teachers" 
		<< endl << "3-Show Students" 
		<< endl << "4-Insert Course" 
		<< endl << "5-Insert Term" 
		<< endl << "6-Show Courses" 
		<< endl << "7-Show Term" 
		<< endl << "8-Search In Users" 
		<< endl << "9-Delete User" 
		<< endl << "0-logout" << endl;
	cin >> chooseNum;
	switch (chooseNum)
	{
	case 1:
		InsertAdmin();
		break;
	case 2:
		showTeachers();
		break;
	case 3:
		showStudents();
		break;
	case 4:
		InsertCourse();
		break;
	case 5:
		InsertTerm();
		break;
	case 6:
		showCourse();
		break;
	case 7:
		showTerm();
		break;
	case 8:
		searchInUsers();
		break;
	case 9:
		deleteUser();
		break;
	case 0:
		logout();
	
	default:
		returnAdminMenu();
		break;
	}

}
void InsertAdmin() {
	system("CLS");
	cout << "*** Insert Admin ***" << endl << endl;
	int statusPass = true;
	string fname, lname, mobile, username, password, passwordConfirm, dateOfBirth , rule;
	//string fname, string lname,string username,string password,string mobile
	cout << endl << "First Name : ";
	cin >> fname;
	cout << endl << "Last Name : ";
	cin >> lname;
	cout << endl << "Date of Birthday( example : 1382/27/09 ) : ";
	cin >> dateOfBirth;
	cout << endl << "Mobile : ";
	cin >> mobile;
	cout << endl << "Email  (Must be used inside email @) : ";
	cin >> username;
	cout << endl << "Rule ( Choose Between : [ owner , admin , moderator , writer ] ) : ";
	cin >> rule;

	while (statusPass) {
		cout << endl << "Password : (The minimum length of the password should be 6) : ";
		cin >> password;
		cout << endl << "Confirm-Password : ";
		cin >> passwordConfirm;
		if (password == passwordConfirm) {
			break;
		}
		cout << endl << "The password must be equal to the Confirm-Password" << endl;
	}
	person[++userCounter] = new Admin(fname, lname, username, password, mobile, dateOfBirth, rule);
	system("CLS");
	cout << "*** Personl Info New Admin ***" << endl << endl;
	person[userCounter]->printPersonalInfo();
	returnAdminMenu();
}
void showTeachers() {
	system("CLS");
	cout << endl << "*** Show All Teachers ***" << endl << endl;
	for (int i = 1; i <= userCounter; i++)
	{
		if (person[i] != NULL) {
		if (person[i]->getType() == 1) {
			person[i]->printPersonalInfo();
		}
		}
	}
	returnAdminMenu();
}
void showStudents() {
	system("CLS");
	cout << endl << "*** Show All Students ***" << endl << endl;
	for (int i = 1; i <= userCounter; i++)
	{
		if (person[i] != NULL) {
		if (person[i]->getType() == 0) {
			person[i]->printPersonalInfo();
		}
		}
	}
	returnAdminMenu();
}
void InsertCourse() {
	system("CLS");
	string courseName;
	int courseUnit;
	cout << "*** Insert Course ***" << endl << endl;
	cout << "1-Course Name : ";
	cin >> courseName;
	cout << endl << "2-Course Unit ( Between 0-5 ): ";
	cin >> courseUnit;
	course[++courseCounter].setCourseName(courseName);
	course[courseCounter].setUnit(courseUnit);
	returnAdminMenu();
}
void InsertTerm() {
	system("CLS");
	string termName;
	int courseNumber;
	cout << "*** Insert Course ***" << endl << endl;
	cout << "1-Term Name : ";
	cin >> termName;
	cout << endl << "2-Number of lessons per semester ( Between 0-♾️ ): ";
	cin >> courseNumber;
	term[++termCounter].setCourseNumber(courseNumber);
	term[termCounter].setTermName(termName);
	returnAdminMenu();
}
void showTerm() {
	cout << "*** Show Terms ***" << endl << endl;
	for (int i = 0; i <= termCounter; i++)
	{
		term[i].printTermInfo();
		cout << endl << endl;
	}
	returnAdminMenu();
}
void showCourse() {
	cout << "*** Show Courses ***" << endl << endl;
	for (int i = 0; i <= courseCounter; i++)
	{
		course[i].printCourseInfo();
		cout << endl << endl;
	}
	returnAdminMenu();
}
void searchInUsers() {
	system("CLS");
	int chooseNum;
	cout << "*** Search Menu ***" << endl;
	cout << "1-Search By ID : " << endl << "2-Search By Name : " << endl;
	cin >> chooseNum;
	switch (chooseNum)
	{
	case 1:
		searchByID();
		break;
	case 2:
		searchByName();
		break;
	default:
		cout << "Please Enter Number Between (1-2) ...";
		_getch();
		searchInUsers();
		break;
	}
}
void searchByID() {
	system("CLS");
	int id;
	cout << "*** Search By ID Panel ***" << endl;
	cout << "Enter ID : " << endl;
	cin >> id;

	for (int i = 1; i <= userCounter; i++)
	{
		if (person[i] != NULL) {
		if (person[i]->getID() == id) {
			cout << endl;
			person[i]->printPersonalInfo();
		}
		}
	}
	returnAdminMenu();
}
void searchByName() {
	system("CLS");
	string name;
	cout << "*** Search By Name Panel ***" << endl;
	cout << "Enter Name (Just Name, dont enter name + last name !!) : " << endl;
	cin >> name;

	for (int i = 1; i <= userCounter; i++)
	{
		if (person[i] != NULL) {
		if (person[i]->getFname().find(name) == string::npos) {
			cout << endl;
			person[i]->printPersonalInfo();
			cout << endl;
		}
		}
	}
	returnAdminMenu();
	
}
void returnAdminMenu() {
	cout << endl << endl << "Press Any key ...";
	_getch();
	AdminPanel();
}
void deleteUser() {
	system("CLS");
	cout << "*** Delete User Panel ***" << endl << endl;
	int id;
	for (int i = 1; i <= userCounter; i++)
	{
		if (person[i] != NULL) {
			person[i]->printPersonalInfo();
		}
	}
	cout << "Enter User ID For Delete : ";
	cin >> id;
	for (int i = 1; i <= userCounter; i++) {
		if (person[i] != NULL) {
			if (person[i]->getID() == id) {
				person[i] = NULL;
			}
		}
	}
	returnAdminMenu();
}