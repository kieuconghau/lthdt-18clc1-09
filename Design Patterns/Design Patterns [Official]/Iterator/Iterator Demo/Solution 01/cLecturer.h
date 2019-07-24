#pragma once

#include <iostream>
#include <string>
#include "cUniversityPersonel.h"
using namespace std;

class cLecturer:public cUniversityPersonel
{
public:
	cLecturer(string name = "N/A", string id = "N/A");
	void input_info();
	void show_info();

private:
	string Name;
	string ID;
};
