#include "degree.h"
#include "student.h"

/*=== D2d. Student Constructor ===*/
Student::Student(string aStudentId, string aFirstName, string aLastName, string aEmail, int aAge, int aDaystoComplete[], DegreeProgram aProgram) {
	studentId = aStudentId;
	firstName = aFirstName;
	lastName = aLastName;
	email = aEmail;
	age = aAge;

	for (int i = 0; i < SIZE; i++) {
		daysToComplete[i] = aDaystoComplete[i];
	}
	program = aProgram;
}

// Destructor
Student::~Student() {
}

/*=== D2a. Getter functions ===*/
// Gets student ID number
string Student::getStudentId() {
	return (studentId);
}

// Gets first name
string Student::getFirstName() {
	return (firstName);
}

// Gets last name
string Student::getLastName() {
	return (lastName);
}

// Gets email
string Student::getEmail() {
	return (email);
}

// Gets age
int Student::getAge() {
	return (age);
}

// Gets days to complete courses
int* Student::getDaysToComplete() {
	return (daysToComplete);
}

// Gets degree program
DegreeProgram Student::getProgram() {
	return (program);
}

/*=== D2b. Setter functions ===*/
// Sets student ID number
void Student::setStudentId(string aStudentId) {
	studentId = aStudentId;
}

// Sets first name
void Student::setFirstName(string aFirstName) {
	firstName = aFirstName;
}

// Sets last name
void Student::setLastName(string aLastName) {
	lastName = aLastName;
}

// Sets email
void Student::setEmail(string aEmail) {
	email = aEmail;
}

// Sets age
void Student::setAge(int aAge) {
	age = aAge;
}

// Sets days to complete courses
void Student::setDaystoComplete(int aDaysToComplete[]) {
	for (int i = 0; i < SIZE; i++) {
		daysToComplete[i] = aDaysToComplete[i];
	}
}

// Sets degree program
void Student::setProgram(DegreeProgram aProgram) {
	program = aProgram;
}

/*=== D2e. Print function ===*/
void Student::print() {
	cout << studentId << '\t'
		<< "First Name: " << firstName << '\t'
		<< "Last Name: " << lastName << '\t'
		<< "Age: " << age << '\t'
		<< "daysInCourse: {" << daysToComplete[0] << ", "
		<< daysToComplete[1] << ", "
		<< daysToComplete[2] << "} " << '\t'
		<< "Degree Program: ";

	switch (program) {
	case SECURITY:
		cout << "SECURITY";
		break;
	case NETWORK:
		cout << "NETWORK";
		break;
	case SOFTWARE:
		cout << "SOFTWARE";
		break;
	case NONE:
		cout << "NONE";
		break;
	}
	cout << endl;

}