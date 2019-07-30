#include "cLecturer.h"

cLecturer::cLecturer(string name, string id)
{
	this->Name = name;
	this->ID = id;
}

void cLecturer::input_info()
{
	cout << "Input info for this Lecturer" << endl;
	cout << "  - Name: ";
	getline(cin, this->Name);
	cout << "  - ID: ";
	getline(cin, this->ID);
}

void cLecturer::show_info()
{
	cout << "  - Type: Lecturer" << endl;
	cout << "  - Name: " << this->Name << endl;
	cout << "  - ID: " << this->ID << endl;
}

