#include "cStudent.h"

cStudent::cStudent(string name, string id)
{
	this->Name = name;
	this->ID = id;
	this->Next = nullptr;
}

void cStudent::input_info()
{
	cout << "Input info for this Student" << endl;
	cout << "  - Name: ";
	getline(cin, this->Name);
	cout << "  - ID: ";
	getline(cin, this->ID);
}

void cStudent::show_info()
{
	cout << "  - Type: Student" << endl;
	cout << "  - Name: " << this->Name << endl;
	cout << "  - ID: " << this->ID << endl;
}

cStudent*& cStudent::next()
{
	return this->Next;
}

