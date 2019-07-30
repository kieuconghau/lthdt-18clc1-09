#pragma once
#include "cUniversityPersonnel.h"
#include <iostream>
#include <string>
using namespace std;

class cLecturer : public cUniversityPersonnel
{
public:
	cLecturer(string name = "N/A", string id = "N/A");
	void input_info() override;
	void show_info() override;

private:
	string Name;
	string ID;
};
