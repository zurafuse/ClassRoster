#include "pch.h"
#include "securityStudent.h"

securityStudent::securityStudent(string id, string firstN, string lastN, string email, int thisAge, int days[], Degree degree)
	:student(id, firstN, lastN, email, thisAge, days)
{
	degreeProgram = degree;
}


securityStudent::~securityStudent()
{
}

Degree securityStudent::getDegreeProgram() {
	return degreeProgram;
}

void securityStudent::print() {
	cout << getStudentID() << "\tFirst Name : " << getFirstName() << "\tLast Name : " << getLastName() << "\tEmail Address: "
		<< getEmail() << "\tAge : " << getAge() << "\tdaysInCourse : ";
	cout << "{" << getCourseDays()[0] << ", " << getCourseDays()[1] <<
		", " << getCourseDays()[2] << "}" << "\tDegree Program : Security." << endl;
}