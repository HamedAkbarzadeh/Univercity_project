#include "Term.h"

Term::Term() {
	cout << endl << "**Term**" << endl;
}

Term::Term(string termName , int courseNumber) {
	setTermName(termName);
	setCourseNumber(courseNumber);
}
void Term::setCourseNumber(int courseNumber) {
	if (courseNumber <= 0) {
		courseNumber = 2;
	}
	this->courseNumber = courseNumber;
}
void Term::setTermName(string termName) {
	this->termName = termName;
}