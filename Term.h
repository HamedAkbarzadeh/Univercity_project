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


	//
	int getID() { return id; }
	int getCourseCount() { return courseNumber; }

	//other
	void printTermInfo();

	Course* course = new Course[30];
private:
	static int IDCounter;
	int id;
	string termName;
	int courseNumber;
};

#endif // !Term_H
