#include "Course.h"
#include "Date.h"
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
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
void ForgotPassword();
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
void AShowMyProfile();
void setSalary();
//Student Panel
void StudentPanel();
void StuSelectCourse();
void StuShowScore();
void returnToStudentMenu();
void StuShowCourse();
void StuShowMyProfile();

//TeacherPanel
void RegisterTeacherForm();
void TeacherPanel();
void returnToTeacherPanel();
void TeacherSelectCourse();
void ShowTeacherSelectedCourse();
void TeacherSetScore();
void TShowMyProfile();

/////global/////
void EditProfile(int type);

static int userCounter = 1;
static int termCounter = -1;
//Person
Person** person = new Person * [100];
Term* term = new Term[100];
/* info For User
person[0] == currentUserLogin
person[1] == defualtAdmin
*/

int main() {
	system("CLS");

	person[1] = new Admin("Hamed", "Akbarzadeh", "hmd@gmail.com", "123456", "09331434614", "1382/27/09", "owner");
	LoginRegisterForm();
	return 0;
}
//Auth
void LoginRegisterForm() {
	system("CLS");
	int chooseNum;
	cout << "Welcome To Univercity ..." << endl;
	cout << "1-login" << endl << "2-Register" << endl << "3-Forgot Password" << endl;
	cin >> chooseNum;
	switch (chooseNum)
	{
	case 1:
		LoginForm();
		break;
	case 2:
		RegisterForm();
		break;
	case 3:
		ForgotPassword();
		break;
	default:
		cout << "please Enter Number (1 or 3)" << endl;
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
		TeacherPanel();
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
void ForgotPassword() {
	system("CLS");
	cout << "*** Recovery Password Panel ***" << endl << endl;
	string mobile, username, pass, confPass;
	int k = 0 , passSize;
	cout << "Enter Email : ";
	cin >> username;
	cout << endl << "Enter Mobile : ";
	cin >> mobile;
	for (int i = 1; i <= userCounter; i++)
	{
		if (person[i]->getUsername() == username && person[i]->getMobile() == mobile) {
			k++;
			while(true)
			{
				while (true) {
					cout << endl << endl << "Enter New Password (The minimum length of the password should be 6): ";
					cin >> pass;
					passSize = size(pass);
					if (passSize >= 6) {
						break;
					}
					cout << endl << "!!! The minimum length of the password should be 6 !!!" << endl;
				}
			cout << endl << "Enter Confirm Password : ";
			cin >> confPass;
			if (pass == confPass) {
				person[i]->setPassword(pass);
				break;
			}
			cout << endl << "The password must be equal to the Confirm-Password" << endl;
			}
		}
	}
	if (k > 0) {
	cout << endl << "password Successfully Changed :)" << endl;

	}
	else {
		cout << endl << "!!! Ther is no such user with this information !!!" << endl;
	}
	cout << "Press any key ...";
	_getch();
	LoginRegisterForm();
}
//Teacher
void TShowMyProfile() {
	system("CLS");
	cout << "*** Show Profile Panel ***" << endl << endl;
	person[0]->printPersonalInfo();
	cout << endl;
	returnToTeacherPanel();
}
void RegisterTeacherForm() {
	system("CLS");
	int statusPass = true;
	string fname, lname, mobile, username, password, passwordConfirm, yearsOfStart, dateOfBirth;
	//string fname, string lname,string username,string password,string mobile
	cout << "*** Register Form (Teacher) ***" << endl << endl;
	cout << endl << "First Name : ";
	cin >> fname;
	cout << endl << "Last Name : ";
	cin >> lname;
	cout << endl << "Date of Birthday( example : 1382/27/09 ) : ";
	cin >> dateOfBirth;
	cout << endl << "Mobile : ";
	cin >> mobile;

	cout << endl << "email : (Must be used inside email @) : ";
	cin >> username;

	while (statusPass) {
		while (true) {
			cout << endl << endl << "Enter Password (The minimum length of the password should be 6): ";
			cin >> password;
			int passSize = size(password);
			if (passSize >= 6) {
				break;
			}
			cout << endl << "!!! The minimum length of the password should be 6 !!!" << endl;
		}
		cout << endl << "Confirm-Password : ";
		cin >> passwordConfirm;
		if (password == passwordConfirm) {
			break;
		}
		cout << endl << "!!! The password must be equal to the Confirm-Password !!!" << endl;
	}
	person[++userCounter] = new Teacher(fname, lname, username, password, mobile, dateOfBirth, 0);
	person[0] = NULL;
	person[0] = person[userCounter];
	TeacherPanel();
}
void TeacherPanel() {
	system("CLS");
	cout << "*** Welcome " << person[0]->getFname() << " " << person[0]->getLname() << " To Teacher Panel ***" << endl << endl;
	int chooseNum;
	cout << "P-Show My Profile" << endl << "E-Edit My Profile" << endl << "1-Select Course" << endl << "2-Show My Course" << endl << "3-Set Score" << endl << "0-logout" << endl;
	chooseNum = _getch();
	switch (chooseNum)
	{
	case 'p':
		TShowMyProfile();
		break;
	case 'e':
		EditProfile(1);
		break;
	case 49:
		TeacherSelectCourse();
		break;
	case 50:
		ShowTeacherSelectedCourse();
		break;
	case 51:
		TeacherSetScore();
		break;
	case 48:
		logout();
		break;
	default:
		cout << endl << "Please Enter Number Between (1-3) ..." << endl;
		returnToTeacherPanel();
		break;
	}
}
void TeacherSelectCourse() {
	//select Term
	system("CLS");
	int termID;
	cout << "*** Select Course Panel ***" << endl << endl;

	cout << "For Wich One Term Do You Want Select Course ( Enter Term ID ) : " << endl << endl;
	for (int i = 0; i <= termCounter; i++)
	{
		term[i].printTermInfo();
		cout << endl << endl;
	}
	cin >> termID;

	//select Course
	system("CLS");
	int courseID;
	cout << "Select Course ( Course ID ) :" << endl << endl;
	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				if (term[i].course[j].getCourseTeacherID() == -1) {
					term[i].course[j].printCourseInfo();
					cout << endl << endl;
				}
			}
		}
	}
	cin >> courseID;

	//set Course For Teacher
	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				if (term[i].course[j].getID() == courseID) {
					term[i].course[j].setCourseTeacherName(person[0]->getFname());
					term[i].course[j].setCourseTeacherID(person[0]->getID());
				}
			}
		}
	}

	returnToTeacherPanel();
}
void ShowTeacherSelectedCourse() {

	//select Course
	system("CLS");
	cout << "*** Teacher Selected Course Panel ***" << endl << endl;
	int termID;

	cout << "For Wich One Term ( Enter Term ID ) : " << endl << endl << endl;
	for (int i = 0; i <= termCounter; i++)
	{
		term[i].printTermInfo();
		cout << endl << endl;
	}
	cin >> termID;

	//Show Selected Course From Teacher
	system("CLS");
	cout << "Selected Course From :" << person[0]->getFname() << " " << person[0]->getLname() << endl << endl;
	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				if (term[i].course[j].getCourseTeacherID() == person[0]->getID()) {
					term[i].course[j].printCourseInfoWithTeacherName();
					cout << endl << endl;
				}
			}
		}
	}
	returnToTeacherPanel();
}
void TeacherSetScore() {
	system("CLS");
	cout << "*** Set Score Panel ***" << endl << endl;
	int termID;
	for (int i = 0; i <= termCounter; i++)
	{
		term[i].printTermInfo();
		cout << endl << endl;
	}
	cin >> termID;
	//select
	system("CLS");
	cout << "Select Course For Set Score ( Enter Course ID ) : " << endl;
	int courseID;
	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				if (term[i].course[j].getCourseTeacherID() == person[0]->getID() && term[i].course[j].getCourseStuID() != -1) {
					term[i].course[j].printCourseInfoWithTeacherNameAndStudentName();
				}
			}
		}
	}
	cin >> courseID;
	//set Score
	system("CLS");
	int score;
	cout << "Enter Score : ";
	cin >> score;
	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				if (term[i].course[j].getID() == courseID) {
					term[i].course[j].setScore(score);
				}
			}
		}
	}
	returnToTeacherPanel();
}
void returnToTeacherPanel() {
	cout << endl << endl << "Press Any key ...";
	_getch();
	TeacherPanel();
}

//Student
void StuShowMyProfile() {
	system("CLS");
	cout << "*** Show Profile Panel ***" << endl << endl;
	person[0]->printPersonalInfo();
	cout << endl;
	returnToStudentMenu();
}
void RegisterStudentForm() {
	system("CLS");
	int statusPass = true;
	string fname, lname, mobile, username, password, passwordConfirm, yearsOfStart, dateOfBirth;
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
		while (true) {
			cout << endl << endl << "Enter Password (The minimum length of the password should be 6): ";
			cin >> password;
			int passSize = size(password);
			if (passSize >= 6) {
				break;
			}
			cout << endl << "!!! The minimum length of the password should be 6 !!!" << endl;
		}
		cout << endl << "7-Confirm-Password : ";
		cin >> passwordConfirm;
		if (password == passwordConfirm) {
			break;
		}
		cout << endl << "!!! The password must be equal to the Confirm-Password !!!" << endl;
	}
	person[++userCounter] = new Student(fname, lname, username, password, mobile, dateOfBirth, yearsOfStart);
	person[0] = NULL;
	person[0] = person[userCounter];
	StudentPanel();
}
void StudentPanel() {
	system("CLS");
	int chooseNum;
	cout << "*** Welcome " << person[0]->getFname() << " " << person[0]->getLname() << " To Student Panel ***" << endl << endl;
	cout << "P-Show My Profile" << endl << "E-Edit My Profile" << endl << "1-Select course" << endl << "2-Show score" << endl << "3-Show My Course" << endl << "0-logout" << endl;
	chooseNum = _getch();
	switch (chooseNum)
	{
	case 'p':
		StuShowMyProfile();
		break;
	case 'e':
		EditProfile(0);
		break;
	case 49:
		StuSelectCourse();
		break;
	case 50:
		StuShowScore();
		break;
	case 51:
		StuShowCourse();
		break;
	case 48:
		logout();
		break;
	default:
		cout << endl << "please Enter number between (1-3)" << endl;
		break;
	}
}
void StuSelectCourse() {
	system("CLS");

	//select Term
	cout << "*** Select Course Panel (Student)***" << endl << endl;
	cout << "For Which One Term Do You Want Select Course (Enter ID) : " << endl << endl;
	int termID;
	for (int i = 0; i <= termCounter; i++)
	{
		term[i].printTermInfo();
		cout << endl << endl;
	}
	cin >> termID;
	//select Course
	system("CLS");
	int courseID;
	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				if (term[i].course[j].getCourseTeacherID() != -1 && term[i].course[j].getCourseStuID() != person[0]->getID()) {
					term[i].course[j].printCourseInfoWithTeacherName();
					cout << endl << endl;
				}
			}
		}
	}
	cin >> courseID;
	//set Course For Student
	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				if (term[i].course[j].getID() == courseID) {
					term[i].course[j].setCourseStuName(person[0]->getFname());
					term[i].course[j].setCourseStuID(person[0]->getID());
				}
			}
		}
	}
	returnToStudentMenu();
}
void StuShowScore() {
	system("CLS");

	//select Term
	cout << "*** Show Score Panel ***" << endl << endl;
	int termID;
	cout << "For Which One Term Do You Want Show Course Score (Enter Term ID) : " << endl << endl;
	for (int i = 0; i <= termCounter; i++)
	{
		term[i].printTermInfo();
		cout << endl << endl;
	}
	cin >> termID;
	//select Course
	float sumScoreXsumUnit = 0;
	float sumUnit = 0;
	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				if (term[i].course[j].getCourseStuID() == person[0]->getID() && term[i].course[j].getCourseTeacherID() != -1) {
					term[i].course[j].printCourseInfoWithTeacherNameAndStudentNameAndWithScore();
					cout << endl << endl;
					sumScoreXsumUnit += term[i].course[j].getScore() * term[i].course[j].getCourseUnit();
					sumUnit += term[i].course[j].getCourseUnit();
				}
			}
		}
	}
	cout << endl << endl << "AVG Score In Term : " << sumScoreXsumUnit / sumUnit << endl;
	returnToStudentMenu();
}
void StuShowCourse() {
	system("CLS");
	cout << "*** Show Selected Courses ***" << endl << endl;
	//select term
	cout << "For Which One Term Do You Want Show Courses (Enter ID) : " << endl << endl;
	int termID;
	for (int i = 0; i <= termCounter; i++)
	{
		term[i].printTermInfo();
		cout << endl << endl;
	}
	cin >> termID;
	//show Courses
	system("CLS");
	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				if (term[i].course[j].getCourseStuID() == person[0]->getID()) {
					term[i].course[j].printCourseInfoWithTeacherNameAndStudentName();
					cout << endl << endl;
				}
			}
		}
	}
	returnToStudentMenu();
}
void returnToStudentMenu() {
	cout << endl << endl << "Press Any key ...";
	_getch();
	StudentPanel();
}

//Admin
void AShowMyProfile() {
	system("CLS");
	cout << "*** Show Profile Panel ***" << endl << endl;
	person[0]->printPersonalInfo();
	cout << endl;
	returnAdminMenu();
}
void AdminPanel() {
	system("CLS");
	int chooseNum;
	cout << "*** Welcome " << person[0]->getFname() << " " << person[0]->getLname() << " To Admin Panel ***" << endl << endl;
	cout << "*__________________________________ **** Information About Rule **** ___________________________________*" << endl;
	cout << "|\t** owner ** = Full Access \t\t\t\t\t\t\t\t\t|"
		<< endl << "|\t** admin ** = Full Access except (Insert Admin , Delete User) \t\t\t\t\t|"
		<< endl << "|\t** moderator ** = Full Access except (Insert Admin , Delete User , Search In Users) \t\t|"
		<< endl << "|\t** writer ** = Just Can Use (Show teacher , Show student , Show Course) \t\t\t|" << endl;
	cout << "*-------------------------------------------------------------------------------------------------------*" << endl << endl;

	if (person[0]->getRule() == "owner") {
		cout << "P-Show My Profile"
			<< endl << "E-Edit Profile"
			<< endl << "S-Set Salary For Teacher"
			<< endl << "1-Insert New Admin"
			<< endl << "2-Show Teachers"
			<< endl << "3-Show Students"
			<< endl << "4-Insert Course"
			<< endl << "5-Insert Term"
			<< endl << "6-Show Courses"
			<< endl << "7-Show Term"
			<< endl << "8-Search In Users"
			<< endl << "9-Delete User"
			<< endl << "0-logout" << endl;
	}
	else if (person[0]->getRule() == "admin") {
		cout << "P-Show My Profile"
			<< endl << "S-Set Salary For Teacher"
			<< endl << "E-Edit Profile"
			<< endl << "1-Insert New Admin ( You Cant Use This :) )"
			<< endl << "2-Show Teachers"
			<< endl << "3-Show Students"
			<< endl << "4-Insert Course"
			<< endl << "5-Insert Term"
			<< endl << "6-Show Courses"
			<< endl << "7-Show Term"
			<< endl << "8-Search In Users"
			<< endl << "9-Delete User ( You Cant Use This :) )"
			<< endl << "0-logout" << endl;
	}
	else if (person[0]->getRule() == "moderator") {
		cout << "P-Show My Profile"
			<< endl << "S-Set Salary For Teacher"
			<< endl << "E-Edit Profile"
			<< endl << "1-Insert New Admin ( You Cant Use This :) )"
			<< endl << "2-Show Teachers"
			<< endl << "3-Show Students"
			<< endl << "4-Insert Course ( You Cant Use This :) )"
			<< endl << "5-Insert Term ( You Cant Use This :) )"
			<< endl << "6-Show Courses"
			<< endl << "7-Show Term ( You Cant Use This :) )"
			<< endl << "8-Search In Users ( You Cant Use This :) )"
			<< endl << "9-Delete User ( You Cant Use This :) )"
			<< endl << "0-logout" << endl;
	}
	else if (person[0]->getRule() == "writer") {
		cout << "P-Show My Profile"
			<< endl << "S-Set Salary For Teacher"
			<< endl << "E-Edit Profile"
			<< endl << "1-Insert New Admin"
			<< endl << "2-Show Teachers"
			<< endl << "3-Show Students"
			<< endl << "4-Insert Course"
			<< endl << "5-Insert Term"
			<< endl << "6-Show Courses"
			<< endl << "7-Show Term"
			<< endl << "8-Search In Users ( You Cant Use This :) )"
			<< endl << "9-Delete User ( You Cant Use This :) )"
			<< endl << "0-logout" << endl;
	}
	chooseNum = _getch();
	//cin >> chooseNum;

	if (person[0]->getRule() == "owner") {
		switch (chooseNum)
		{
		case 'p':
			AShowMyProfile();
			break;
		case 49: //1
			InsertAdmin();
			break;
		case 50: //2
			showTeachers();
			break;
		case 51: //3
			showStudents();
			break;
		case 52: //4
			InsertCourse();
			break;
		case 53: //5
			InsertTerm();
			break;
		case 54: //6
			showTerm();
			break;
		case 55: //7
			showCourse();
			break;
		case 56: //8
			searchInUsers();
			break;
		case 57: //9
			deleteUser();
			break;
		case 's': 
			setSalary();
			break;
		case 'e': 
			EditProfile(2);
			break;
		case 48: //0
			logout();

		default:
			returnAdminMenu();
			break;

		}
	}
	if (person[0]->getRule() == "admin") {
		switch (chooseNum)
		{
		case 'p':
			AShowMyProfile();
			break;
		case 50: //2
			showTeachers();
			break;
		case 51: //3
			showStudents();
			break;
		case 52: //4
			InsertCourse();
			break;
		case 53: //5
			InsertTerm();
			break;
		case 54: //6
			showTerm();
			break;
		case 55: //7
			showCourse();
			break;
		case 56: //8
			searchInUsers();
			break;
		case 's':
			setSalary();
			break;
		case 'e':
			EditProfile(2);
			break;
		case 48: //0
			logout();

		default:
			returnAdminMenu();
			break;

		}
	}
	if (person[0]->getRule() == "moderator") {
		switch (chooseNum)
		{
		case 'p':
			AShowMyProfile();
			break;
		case 50: //2
			showTeachers();
			break;
		case 51: //3
			showStudents();
			break;
		case 52: //4
			InsertCourse();
			break;
		case 53: //5
			InsertTerm();
			break;
		case 54: //6
			showTerm();
			break;
		case 55: //7
			showCourse();
			break;
		case 's':
			setSalary();
			break;
		case 'e':
			EditProfile(2);
			break;
		case 48: //0
			logout();

		default:
			returnAdminMenu();
			break;

		}
	}
	if (person[0]->getRule() == "writer") {
		switch (chooseNum)
		{
		case 'p':
			AShowMyProfile();
			break;
		case 50: //2
			showTeachers();
			break;
		case 51: //3
			showStudents();
			break;
		case 55: //7
			showCourse();
			break;
		case 's':
			setSalary();
			break;
		case 'e':
			EditProfile(2);
			break;
		case 48: //0
			logout();

		default:
			returnAdminMenu();
			break;

		}
	}

}
void InsertAdmin() {
	system("CLS");
	cout << "*** Insert Admin ***" << endl << endl;
	int statusPass = true;
	string fname, lname, mobile, username, password, passwordConfirm, dateOfBirth, rule;
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
		while (true) {
			cout << endl << endl << "Enter Password (The minimum length of the password should be 6): ";
			cin >> password;
			int passSize = size(password);
			if (passSize >= 6) {
				break;
			}
			cout << endl << "!!! The minimum length of the password should be 6 !!!" << endl;
		}
		cout << endl << "Confirm-Password : ";
		cin >> passwordConfirm;
		if (password == passwordConfirm) {
			break;
		}
		cout << endl << "!!! The password must be equal to the Confirm-Password !!!" << endl;
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
	cout << "*** Insert Course ***" << endl << endl;
	cout << "For Wich One Term Do You Want Add Course (Enter Term ID) : " << endl;
	int termID;
	for (int i = 0; i <= termCounter; i++)
	{
		term[i].printTermInfo();
		cout << endl;
		cout << endl;
	}
	cin >> termID;

	//insert course for termID
	string courseName;
	int courseUnit;
	system("CLS");

	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				cout << "1-Course Name[ " << j + 1 << " ] : ";
				cin >> courseName;
				cout << "2-Course Unit ( Between 0-5 ) [ " << j + 1 << " ] : ";
				cin >> courseUnit;
				cout << endl << endl;
				term[i].course[j].setCourseName(courseName);
				term[i].course[j].setUnit(courseUnit);
				term[i].course[j].setScore(-1);
				term[i].course[j].setCourseTeacherID(-1);
				term[i].course[j].setCourseStuID(-1);
			}
		}
	}

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
	system("CLS");
	cout << "*** Show Courses ***" << endl << endl;
	cout << "For Wich One Term Do You Want Show Courses (Enter Term ID) : " << endl;
	int termID;
	for (int i = 0; i <= termCounter; i++)
	{
		term[i].printTermInfo();
		cout << endl << endl;
	}
	cin >> termID;
	system("CLS");
	for (int i = 0; i <= termCounter; i++)
	{
		if (term[i].getID() == termID) {
			for (int j = 0; j < term[i].getCourseCount(); j++)
			{
				term[i].course[j].printCourseInfo();
				cout << endl << endl;
			}
		}
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
void setSalary() {
	//select teacher
	system("CLS");
	cout << "*** Set Salary For Teacher Panel ***" << endl << endl;
	int id;
	cout << "For Which One Teacher Do You Want Set Salary ( Enter ID ) ? " << endl << endl;
	for (int i = 1; i <= userCounter; i++)
	{
		if (person[i]->getType() == 1) {
			person[i]->printPersonalInfo();
			cout << endl << endl;
		}
	}
	cin >> id;
	//set salary
	system("CLS");
	float salary;
	cout << "Enter Salary Price : ";
	cin >> salary;
	for (int i = 1; i <= userCounter; i++)
	{
		if (person[i]->getID() == id) {
			person[i]->setSalary(salary);
		}
	}
	returnAdminMenu();
}
void EditProfile(int type) {
	system("CLS");
	cout << "*** Edit Profile ***" << endl << endl;
	cout << "Current Profile : " << endl;
	person[0]->printPersonalInfo();
	//string fname, string lname, string username, string password, string mobile, string DateOfBirth
	string fname, lname, username, mobile, date;
	cout << endl << endl;
	cout << "First Name : ";
	cin >> fname;
	cout << endl << "Last Name : ";
	cin >> lname;
	cout << endl << "Email : ";
	cin >> username;
	cout << endl << "Mobile : ";
	cin >> mobile;
	cout << endl << "Date Of Birth : ";
	cin >> date;
	person[0]->EditProfile(fname, lname, mobile, username, date);

	switch (type)
	{
	case 0:
		returnToStudentMenu();
		break;
	case 1:
		returnToTeacherPanel();
		break;
	case 2:
		returnAdminMenu();
		break;
	default:
		LoginRegisterForm();
		break;
	}
}