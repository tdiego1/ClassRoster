#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

/*=== E1. Roster Constructors ===*/
Roster::Roster(int aTotalStudents) {
	totalStudents = aTotalStudents;
	lastStudent = -1;
	classRosterArray = new Student * [aTotalStudents];
}

/*=== F5. Roster Destructor ===*/
Roster::~Roster() {
	for (int i = 0; i < totalStudents; i++) {
		delete classRosterArray[i];
	}
	delete this;
}

/*=== E2. and E3. Roster Functions ===*/
// E2a. and E2b. Parses and adds data to classRoster
void Roster::parseDataAndAdd(string studentDataRow) {
	vector <string> parsedData;
	stringstream streamInput(studentDataRow);
	DegreeProgram parsedProgram;

	// E2a. Parses the string with the comma delimiters and adds each piece to the vector
	while (streamInput.good()) {
		string newData;
		getline(streamInput, newData, ',');
		parsedData.push_back(newData);
	}

	//Converts value to enum
	if (parsedData.at(8) == "SECURITY") {
		parsedProgram = SECURITY;
	}
	else if (parsedData.at(8) == "NETWORK") {
		parsedProgram = NETWORK;
	}
	else if (parsedData.at(8) == "SOFTWARE") {
		parsedProgram = SOFTWARE;
	}
	else {
		parsedProgram = NONE;
	}

	add(parsedData.at(0), parsedData.at(1), parsedData.at(2), parsedData.at(3), stoi(parsedData.at(4)), stoi(parsedData.at(5)), stoi(parsedData.at(6)), stoi(parsedData.at(7)), parsedProgram);
}

// E3a. Adds data to new student object
void Roster::add(string aStudentId, string aFirstName, string aLastName, string aEmail, int aAge, int aDaysInCourse1, int aDaysInCourse2, int aDaysInCourse3, DegreeProgram aProgram) {
	if (lastStudent < totalStudents) {
		lastStudent++;
		int daystoComplete[3] = { aDaysInCourse1, aDaysInCourse2, aDaysInCourse3 };
		classRosterArray[lastStudent] = new Student(aStudentId, aFirstName, aLastName, aEmail, aAge, daystoComplete, aProgram);
	}
	else {
		cerr << endl << "ERROR! REACHED MAX SIZE!" << endl << endl;
	}
}

// E3b. Removes student object by student ID
void Roster::remove(string aStudentId) {
	bool foundId = false;

	cout << "Removing " << aStudentId << endl;
	for (int i = 0; i <= lastStudent; i++) {
		if (classRosterArray[i]->getStudentId() == aStudentId) {
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[lastStudent];
			foundId = true;
			lastStudent--;
		}
	}
	if (foundId) {
		cout << "Student ID " << aStudentId << " removed." << endl;
	}
	else {
		cout << "ERORR! Student ID " << aStudentId << " not found." << endl;
	}
}

// E3c. Prints all the student objects
void Roster::printAll() {
	cout << "Displaying all students:" << endl << endl;

	for (int i = 0; i < totalStudents; i++) {
		classRosterArray[i]->print();

	}
	cout << endl;
}



// E3d. Prints average days in course
void Roster::printAverageDaysInCourse(string aStudentId) {
	bool foundId = false;

	for (int i = 0; i <= lastStudent; i++) {
		if (classRosterArray[i]->getStudentId() == aStudentId) {
			foundId = true;
			int* daysCourse = classRosterArray[i]->getDaysToComplete();
			cout << "Student ID: " << aStudentId << ", average days in course is: " << (daysCourse[0] + daysCourse[1] + daysCourse[2]) / 3 << endl;
		}
	}
}

// E3e. Prints invalid emails
void Roster::printInvalidEmails() {
	cout << "Displaying invalid emails: " << endl << endl;
	bool foundId = false;

	for (int i = 0; i <= lastStudent; i++) {
		string emailStudent = classRosterArray[i]->getEmail();
		if ((emailStudent.find('.') == string::npos) || (emailStudent.find('@') == string::npos) || !(emailStudent.find(' ') == string::npos)) {
			foundId = true;
			cout << classRosterArray[i]->getEmail() << " - is invalid.";
			cout << endl;

		}
	}
	if (!foundId) {
		cout << "No invalid emails found!" << endl;
	}
}

// E3f. Prints students by degree program
void Roster::printByDegreeProgram(DegreeProgram aProgram) {
	bool foundId = false;
	for (int i = 0; i <= lastStudent; i++) {
		if (classRosterArray[i]->getProgram() == aProgram) {
			foundId = true;
			classRosterArray[i]->print();
		}
	}
	if (!foundId) {
		cout << "Invalid degree program!" << endl;
	}
}