#pragma once
#include "student.h"
//#include "degree.h"

class networkStudent: public student
{
public:
	networkStudent(string id, string firstN, string LastN, string email, int age, int days[], Degree degree);
	~networkStudent();
	Degree getDegreeProgram();
	void print();
private:
	Degree degreeProgram;
};

