#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"

using namespace std;

int main() {
	const int maxStudents = 5;

	// A. Includes my personal information as last item
	const string studentData[] = {
									"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
									"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
									"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
									"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
									"A5,Diego,Torres,dtor172@wgu.edu,23,30,25,40,SOFTWARE"
	};

	// F1. Prints out course title, programming language used, WGU student ID, Name
	cout << "C867 - Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 006274354" << endl;
	cout << "Name: Diego Torres" << endl << endl;

	// F2. Creates instance of Roster class
	Roster* classRoster = new Roster(maxStudents);

	// F3. Adds Each student to classRoster
	for (int i = 0; i < maxStudents; i++) {
		classRoster->parseDataAndAdd(studentData[i]);
	}

	/*=== F4. Demonstrations of Roster functions ===*/
	// Prints all student data
	classRoster->printAll();

	// Prints invalid emails
	classRoster->printInvalidEmails();
	cout << endl;

	// Loops through classRosterArray for each element to print out average days in course
	for (int i = 0; i < maxStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentId());
	}
	cout << endl;

	// Prints students by degree program
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << endl;

	// Removes student by ID
	classRoster->remove("A3");
	classRoster->printAll();
	classRoster->remove("A3");



}