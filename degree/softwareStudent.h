#pragma once
#include "student.h"
//#include "degree.h"

class softwareStudent : public student
{
public:
	softwareStudent(string id, string firstN, string lastN, string email, int thisAge, int days[], Degree degree);
	~softwareStudent();
	Degree getDegreeProgram();
	void print();
private:
	Degree degreeProgram;
};

