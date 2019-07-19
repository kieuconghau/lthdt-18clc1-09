#include "cStudent.h"

void cStudent::input_info()
{
	cout << "Input info for this Student" << endl;
	cPerson::input_info();
}

void cStudent::show_info()
{
	cout << "  - Type: Student" << endl;
	cPerson::show_info();
}
