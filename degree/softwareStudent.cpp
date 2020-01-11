#include "pch.h"
#include "softwareStudent.h"

softwareStudent::softwareStudent(string id, string firstN, string lastN, string email, int thisAge, int days[], Degree degree)
	:student(id, firstN, lastN, email, thisAge, days)
{
	degreeProgram = degree;
}


softwareStudent::~softwareStudent()
{

}

Degree softwareStudent::getDegreeProgram() {
	return degreeProgram;
}

void softwareStudent::print() {
	cout << getStudentID() << "\tFirst Name : " << getFirstName() << "\tLast Name : " << getLastName() << "\tEmail Address: "
		<< getEmail() << "\tAge : " << getAge() << "\tdaysInCourse : ";
	cout << "{" << getCourseDays()[0] << ", " << getCourseDays()[1] <<
		", " << getCourseDays()[2] << "}" << "\tDegree Program : Software." << endl;
}