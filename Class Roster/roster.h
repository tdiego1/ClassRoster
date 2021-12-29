#ifndef ROSTER_H
#define ROSTER_H
#include "student.h"
#include <string>
#include <iostream>

class Roster {
public:
	Student** classRosterArray;

	/*=== Constructor ===*/
	Roster(int aTotalStudents);
	~Roster();

	/*=== Functions ===*/
	void parseDataAndAdd(string studentDataRow);
	void add(string aStudentId, string aFirstName, string aLastName, string aEmail, int aAge, int aDaysInCourse1, int aDaysInCourse2, int aDaysInCourse3, DegreeProgram aProgram);
	void printAll();
	void remove(string aStudentId);
	void printAverageDaysInCourse(string aStudentId);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram aProgram);
private:
	int lastStudent;
	int totalStudents;


};
#endif
