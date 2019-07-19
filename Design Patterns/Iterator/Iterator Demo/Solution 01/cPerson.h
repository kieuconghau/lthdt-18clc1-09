#pragma once

#include <iostream>
#include <string>
using namespace std;

class cPerson
{
public:
	virtual void show_info();
	virtual void input_info();

protected:
	string ID;
	string Name;
};

