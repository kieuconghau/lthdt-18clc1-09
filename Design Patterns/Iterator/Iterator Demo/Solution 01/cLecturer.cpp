#include "cLecturer.h"

void cLecturer::input_info()
{
	cout << "Input info for this Lecturer" << endl;
	cPerson::input_info();
}

void cLecturer::show_info()
{
	cout << "  - Type: Lecturer" << endl;
	cPerson::show_info();
}
