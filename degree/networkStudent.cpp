#include "pch.h"
#include "networkStudent.h"

networkStudent::networkStudent(string id, string firstN, string lastN, string email, int thisAge, int days[], Degree degree)
	:student(id, firstN, lastN, email, thisAge, days)
{
	degreeProgram = degree;
}


networkStudent::~networkStudent()
{
}

Degree networkStudent::getDegreeProgram() {
	return degreeProgram;
}

void networkStudent::print() {
	cout << getStudentID() << "\tFirst Name : " << getFirstName() << "\tLast Name : " << getLastName() << "\tEmail Address: "
		<< getEmail() << "\tAge : " << getAge() << "\tdaysInCourse : ";
	cout << "{" << getCourseDays()[0] << ", " << getCourseDays()[1] <<
		", " << getCourseDays()[2] << "}" << "\tDegree Program : Network." << endl;
}