#ifndef Term_H
#define Term_H
#include "Course.h"
#include "Student.h"

class Term
{
public:
	Term();
	Term(string , int);
	void setTermName(string termName);
	void setCourseNumber(int courseNumber);

	Course course;
private:
	string termName;
	int courseNumber;
};

#endif // !Term_H
