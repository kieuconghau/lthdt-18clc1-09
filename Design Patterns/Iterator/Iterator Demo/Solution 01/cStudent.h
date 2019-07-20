#pragma once

#include <iostream>
#include <string>
using namespace std;

class cStudent
{
public:
	cStudent(string name = "N/A", string id = "N/A");
	void input_info();
	void show_info();
	cStudent*& next();

private:
	string Name;
	string ID;
	cStudent* Next;
};

