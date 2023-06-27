#include "Student.h"
#ifndef Course_H
#define Course_H

class Course
{
	friend class Student;
public:
	Course();
	Course(string courseName ,int courseUnit, string courseTeacher = NULL, float score = 0);
	//set
	//void setAll(string courseName, int courseUnit, string courseTeacher = NULL, float score = 0);
	void setScore(float score);
	void setUnit(int unit);
	void setCourseTeacher(string name);
	void setCourseName(string name);

	//get
	float getScore();
	string getCourseTeacher();
	string getCourseName();
	int getCourseUnit();

	//other
	void printCourseInfo();
private:
	float score;
	string courseName , courseTeacher;
	int courseUnit;
};
#endif // !Course_H
