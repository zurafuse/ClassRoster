#pragma once
#include <string>
#include "student.h"
using namespace std;

class roster
{
public:
	roster();
	~roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);
	int index;
	const int NUM_STUDENTS = 5;
	student* classRosterArray[5];
};

