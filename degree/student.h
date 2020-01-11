#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class student
{
public:
	student();
	student(string id, string firstN, string LastN, string email, int age, int days[]);
	~student();
	string getStudentID();
	void setStudentID(string id);
	string getFirstName();
	void setFirstName(string firstName);
	string getLastName();
	void setLastName(string lastName);
	string getEmail();
	void setEmail(string email);
	int getAge();
	void setAge(int age);
	int* getCourseDays();
	const int NUM_COURSE_DAYS = 3;
	void setCourseDays(int days[]);
	virtual void print();
	virtual Degree getDegreeProgram();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDays[3];
};
