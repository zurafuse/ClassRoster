#pragma once
#include "student.h"
//#include "degree.h"

class securityStudent : public student
{
public:
	securityStudent(string id, string firstN, string LastN, string email, int age, int days[], Degree degree);
	~securityStudent();
	Degree getDegreeProgram();
	void print();
private:
	Degree degreeProgram;
};


