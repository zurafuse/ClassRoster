#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <array>
#include "roster.h"
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"

using namespace std;

roster::roster()
{

}


roster::~roster()
{
	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (classRosterArray[i] != NULL) {
			delete classRosterArray[i];
		}
	}
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram)
{
	int DaysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	switch (degreeProgram) {
	case 0:
		//Security Student
		classRosterArray[index] = new securityStudent(studentID, firstName, lastName, emailAddress, age, DaysArray, degreeProgram);
		break;
	case 1:
		//Network Student
		classRosterArray[index] = new networkStudent(studentID, firstName, lastName, emailAddress, age, DaysArray, degreeProgram);
		break;
	case 2: 
		//Software Student
		classRosterArray[index] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, DaysArray, degreeProgram);
		break;
	}
	
}

void roster::remove(string studentID)
{
	bool studentIsFound = false;
	//if the requested student id is found, make the current array element NULL.
	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (classRosterArray[i] != NULL){
			if (studentID == classRosterArray[i]->getStudentID()) {
				studentIsFound = true;
				classRosterArray[i] = NULL;
			}
			
		}
	}
	if (!studentIsFound) {
		cout << "The student with the ID of " << studentID << " was not found." << endl;
	}
}

void roster::printAll()
{
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		if (classRosterArray[i] != NULL) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

void roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < NUM_STUDENTS; i++)
	{
		if (classRosterArray[i] != NULL) {
			if (classRosterArray[i]->getStudentID() == studentID)
			{
				int sum = 0;
				int avg = 0;
				for (int j = 0; j < classRosterArray[i]->NUM_COURSE_DAYS; j++) {
					sum += classRosterArray[i]->getCourseDays()[j];
				}
				avg = sum / classRosterArray[i]->NUM_COURSE_DAYS;
				cout << "The average number of days that " << classRosterArray[i]->getFirstName() <<
					" spends on a course is " << avg << endl;
			}
		}
	}
}

void roster::printInvalidEmails()
{
	cout << "List of invalid email addresses: " << endl;
	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (classRosterArray[i] != NULL) {
			size_t hasAT = classRosterArray[i]->getEmail().find("@");
			size_t hasDot = classRosterArray[i]->getEmail().find(".");
			size_t hasSpace = classRosterArray[i]->getEmail().find(" ");
			if (hasAT == std::string::npos || hasDot == std::string::npos || hasSpace != std::string::npos) {
				cout << classRosterArray[i]->getEmail() << endl;
			}
		}
	}
	cout << endl;
}

void roster::printByDegreeProgram(int degreeProgram)
{
	string thisDegree = "";
	switch (degreeProgram) {
	case 0:
		//Security Student
		thisDegree = "Security";
		break;
	case 1:
		//Network Student
		thisDegree = "Network";
		break;
	case 2:
		//Software Student
		thisDegree = "Software";
		break;
	default:
		thisDegree = "Not Declared";
		break;
	}

	cout << "Students found in the " << thisDegree << " Program:" << endl;

	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (classRosterArray[i] != NULL) {
			if (degreeProgram == classRosterArray[i]->getDegreeProgram()) {
				classRosterArray[i]->print();
			}
		}
	}
	cout << endl;
}

int main()
{
	cout << "Scripting and Programming - Applications - C867" << endl << "C++" << endl << "000891319" << endl << "Timothy Horton" << endl;
	cout << endl;

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Timothy,Horton,thort15@wgu.edu,36,57,61,37,SOFTWARE" };

	roster classRoster;

	//Add student objects to the classRosterArray
	for (classRoster.index = 0; classRoster.index < classRoster.NUM_STUDENTS; classRoster.index++) {
		int i = classRoster.index;
		stringstream row(studentData[i]);
		string studentString;
		vector<string> items;
		string studentID, firstName, lastName, email;
		int age;
		int days1;
		int days2;
		int days3;
		Degree degree;

		while (getline(row, studentString, ','))
		{
			items.push_back(studentString);
		}
		studentID = items[0];
		firstName = items[1];
		lastName = items[2];
		email = items[3];
		age = stoi(items[4]);
		days1 = stoi(items[5]);
		days2 = stoi(items[6]);
		days3 = stoi(items[7]);

		//determine degree type
		if (items[8] == "SECURITY") {
			degree = SECURITY;
		}
		else if (items[8] == "SOFTWARE") {
			degree = SOFTWARE;
		}
		else if (items[8] == "NETWORK") {
			degree = NETWORK;
		}

		classRoster.add(studentID, firstName, lastName, email, age, days1, days2, days3, degree);

	}

	classRoster.index = 0; //Resetting the index back to 0 again.

	classRoster.printAll();
	classRoster.printInvalidEmails();

	for (int i = 0; i < classRoster.NUM_STUDENTS; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");
	classRoster.remove("A3");

	return 0;
}