#include "pch.h"
#include "student.h"

student::student() {

}

student::student(string id, string firstN, string lastN, string email, int thisAge, int days[])
{
	
	studentID = id;
	firstName = firstN;
	lastName = lastN;
	emailAddress = email;
	age = thisAge;

	for (int i = 0; i < 3; i++) {
		courseDays[i] = days[i];
	}
	
}

student::~student()
{


}

string student::getStudentID() {
	return studentID;
}
void student::setStudentID(string id) {
	studentID = id;
}

string student::getFirstName() {
	return firstName;
}
void student::setFirstName(string firstN) {
	firstName = firstN;
}

string student::getLastName() {
	return lastName;
}
void student::setLastName(string lastN) {
	lastName = lastN;
}

string student::getEmail() {
	return emailAddress;
}
void student::setEmail(string email) {
	emailAddress = email;
}

int student::getAge() {
	return age;
}
void student::setAge(int thisAge) {
	age = thisAge;
}

int* student::getCourseDays() {
	return courseDays;
}
void student::setCourseDays(int days[]) {
	//copy day[] parameter to object's courseDays property.
	for (int i = 0; i < 3; i++) {
		courseDays[i] = days[i];
	}
}

void student::print() {
	
}

Degree student::getDegreeProgram() {
	return SOFTWARE;
}


