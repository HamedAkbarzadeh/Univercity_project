#include "Student.h"
#ifndef Course_H
#define Course_H

class Course
{
	friend class Student;
public:
	Course();
	//Course(string courseName = NULL ,int courseUnit = 0, string courseTeacherName = NULL , int courseTeacherID = -1, float score = -1);
	//set
	//void setAll(string courseName, int courseUnit, string courseTeacher = NULL, float score = 0);
	void setScore(float score);
	void setUnit(int unit);
	void setCourseTeacherName(string name);
	void setCourseTeacherID(int id);
	void setCourseName(string name);

	//get
	string getCourseTeacherName() { return courseTeacherName; }
	string getCourseName() { return courseName; }
	int getCourseTeacherID() { return courseTeacherID; }
	int getCourseUnit() { return courseUnit; }
	float getScore() { return score; }
	int getID() { return id; }

	//other
	void printCourseInfo();
	void printCourseInfoWithTeacherName();
private:
	static int IDCounter;
	int id;
	float score;
	string courseName , courseTeacherName;
	int courseUnit , courseTeacherID;
};
#endif // !Course_H
