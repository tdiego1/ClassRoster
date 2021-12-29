#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

/*=== D1. Class "Student" contains the definition of student information ===*/
class Student {
public:
	static const int SIZE = 3;

	// D2d. Constructor
	Student(string aStudentId, string aFirstName, string aLastName, string aEmail, int aAge, int aDaystoComplete[], DegreeProgram aProgram);
	~Student();

	// D2a. Getters
	string getStudentId();		// Gets student ID 
	string getFirstName();		// Gets first name
	string getLastName();		// Gets last name
	string getEmail();			// Gets email
	int getAge();			// Gets age
	int* getDaysToComplete();	// Gets days to complete courses
	DegreeProgram getProgram();	// Gets degree program

	// D2b. Setters
	void setStudentId(string aStudentId);
	void setFirstName(string aFirstName);
	void setLastName(string aLastName);
	void setEmail(string aEmail);
	void setAge(int aAge);
	void setDaystoComplete(int aDaysToComplete[]);
	void setProgram(DegreeProgram aProgram);

	// D2e.  print() function
	void print();

private:
	// D1. and D2c. Variable declarations 
	string studentId;		// Student ID
	string firstName;		// first name
	string lastName;		// last name
	string email;			// email address
	int age;				// age
	int daysToComplete[SIZE];	// Days to complete courses
	DegreeProgram program;	// Degree program
};


#endif