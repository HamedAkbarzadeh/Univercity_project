#include "Course.h"
#include "Date.h"
#include "Person.h"
#include "Student.h"
#include "Term.h"

//prototype
void LoginRegisterForm();
void LoginForm();
void RegisterForm();
void RegisterTeacherForm();
void RegisterStudentForm();
//void AdminPanel();
void StudentPanel();
//void TeacherPanel();

//global
static int userCounter = 0;
Person** person = new Person * [100];
//person[0] == currentUserLogin

int main() {
	system("CLS");
	LoginRegisterForm();
	return 0;
}
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
void RegisterTeacherForm() {
	system("CLS");

}
void RegisterStudentForm() {
	system("CLS");
	int chooseNum, statusPass = true;
	string fname, lname, mobile, username, password, passwordConfirm , yearsOfStart;
	//string fname, string lname,string username,string password,string mobile
	cout << "Register Form (Teacher)" << endl << endl;
	cout << endl << "1-First Name : ";
	cin >> fname;
	cout << endl << "2-Last Name : ";
	cin >> lname;
	cout << endl << "3-Date of entering the university : ";
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
	person[++userCounter] = new Student(fname , lname , username , password ,mobile , yearsOfStart);
	person[0] = person[userCounter];
	StudentPanel();
}
void StudentPanel() {
	system("CLS");
	cout << "*** Welcome "<< person[0]->getFname() << " " << person[0]->getLname() <<" To Student Panel ***" << endl << endl;
}