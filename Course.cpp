#include "Course.h"

//constructor
int Course::IDCounter = 0;

Course::Course() {
	id = IDCounter++;
}
//Course::Course(string courseName = NULL, int courseUnit = 0, string courseTeacherName = NULL, int courseTeacherID = -1, float score = -1) {
//	this->courseName = courseName;
//	this->courseTeacherName = courseTeacherName;
//	this->courseTeacherID = courseTeacherID;
//	setScore(score);
//	setUnit(courseUnit);
//}

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
void Course::setCourseTeacherName(string name) {
	courseTeacherName = name;
}
void Course::setCourseTeacherID( int id) {
	courseTeacherID = id;
}
void Course::setScore(float score) {
	if (score > 20) {
		score = 16;
	}
	if (score < -1) {
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
void Course::setCourseStuName(string name) {
	this->courseStudentName = name;
}
void Course::setCourseStuID(int id) {
	this->courseStudentID = id;

}

//other
void Course::printCourseInfo() {
	cout << "|*  ID : " << id
		<< endl << "|*  Course Name : " << courseName
		<< endl << "|*  Course Unit : " << courseUnit << endl;
}
void Course::printCourseInfoWithTeacherName() {
	cout << "|*  ID : " << id
		<< endl << "|*  Course Name : " << courseName
		<< endl << "|*  Course Unit : " << courseUnit
		<< endl << "|*  Course Teacher Name : " << courseTeacherName
		<< endl;
}
void Course::printCourseInfoWithTeacherNameAndStudentName() {
	cout << "|*  ID : " << id
		<< endl << "|*  Course Name : " << courseName
		<< endl << "|*  Course Unit : " << courseUnit
		<< endl << "|*  Course Teacher Name : " << courseTeacherName
		<< endl << "|*  Course Student Name : " << courseStudentName
		<< endl;
}
void Course::printCourseInfoWithTeacherNameAndStudentNameAndWithScore() {
	cout << "|*  ID : " << id
		<< endl << "|*  Course Name : " << courseName
		<< endl << "|*  Course Unit : " << courseUnit
		<< endl << "|*  Course Teacher Name : " << courseTeacherName
		<< endl << "|*  Course Student Name : " << courseStudentName
		<< endl << "|*  Course Student Score : " << score
		<< endl;
}