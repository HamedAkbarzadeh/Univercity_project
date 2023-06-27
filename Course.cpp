#include "Course.h"

//constructor
Course::Course() {
	cout << endl << "**Course**" << endl;
}
Course::Course(string courseName, int courseUnit,string courseTeacher, float score) {
	this->courseName = courseName;
	this->courseTeacher = courseTeacher;
	setScore(score);
	setUnit(courseUnit);
}

//set
//void Course::setAll(string courseName, int courseUnit,string courseTeacher = NULL,float score = 0) {
//	this->courseName = courseName;
//	this->courseTeacher = courseTeacher;
//	setScore(score);
//	setUnit(courseUnit);
//}
void Course::setCourseName(string name) {
	courseName = name;
}
void Course::setCourseTeacher(string name) {
	courseTeacher = name;
}
void Course::setScore(float score) {
	if (score > 20) {
		score = 16;
	}
	if (score < 0) {
		score = 9.99;
	}
	this->score = score;
}
void Course::setUnit(int unit) {
	if (unit > 5) {
		unit = 5;
	}
	if (unit < 0) {
		unit = 1;
	}
	this->courseUnit = unit;
}
//get
float Course::getScore() {
	return score;
}
string Course::getCourseTeacher() {
	return courseTeacher;
}
string Course::getCourseName() {
	return courseName;
}
int Course::getCourseUnit() {
	return courseUnit;
}
//other
void Course::printCourseInfo() {
	cout << "\tCourse Name : " << courseName << endl << "\tCourse Unit : " << courseUnit << endl;
}