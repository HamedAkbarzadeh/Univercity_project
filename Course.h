#include "Student.h"
#ifndef Course_H
#define Course_H

class Course
{
	friend class Student;
public:
	Course();
	Course(float score , string courseName , string courseTeacher ,int courseUnit);
	void setScore(float score);
	void setUnit(int unit);
	void setCourseTeacher(string name);
	void setCourseName(string name);

	float getScore();
	string getCourseTeacher();
	string getCourseName();
	int getCourseUnit();
private:
	float score;
	string courseName , courseTeacher;
	int courseUnit;
};
#endif // !Course_H
