#ifndef Term_H
#define Term_H
#include "Course.h"
#include "Student.h"

class Term
{
public:
	Term();
	Term(string , int);

	//set
	//void setAll(string termName, int courseNumber);
	void setTermName(string termName);
	void setCourseNumber(int courseNumber);

	//other
	void printTermInfo();

	Course course;
private:
	string termName;
	int courseNumber;
};

#endif // !Term_H
