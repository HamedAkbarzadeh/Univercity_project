#include "Term.h"

//constructor
int Term::IDCounter = 0;
Term::Term() {
	id = IDCounter++;
}

Term::Term(string termName , int courseNumber) {
	setTermName(termName);
	setCourseNumber(courseNumber);
}
//set
//void Term::setAll(string termName, int courseNumber) {
//	setTermName(termName);
//	setCourseNumber(courseNumber);
//}
void Term::setCourseNumber(int courseNumber) {
	if (courseNumber <= 0) {
		courseNumber = 2;
	}
	this->courseNumber = courseNumber;
}
void Term::setTermName(string termName) {
	this->termName = termName;
}
//other
void Term::printTermInfo() {
	cout << "|*  ID : " << id 
		<< endl<< "|*  Term Name : " << termName 
		<< endl << "|*  Number of lessons per semester : " << courseNumber << endl;
}