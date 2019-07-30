#pragma once
#include "cUniversityPersonnel.h"
#include <iostream>
#include <string>
using namespace std;

class cStudent : public cUniversityPersonnel
{
public:
	cStudent(string name = "N/A", string id = "N/A");
	void input_info() override;
	void show_info() override;
	cStudent*& next();

private:
	string Name;
	string ID;
	cStudent* Next;
};

