#include "cPerson.h"

void cPerson::show_info()
{
	cout << "  - ID: " << this->ID << endl;
	cout << "  - Name: " << this->Name << endl;
}

void cPerson::input_info()
{
	cout << "  - ID: ";
	getline(cin, this->ID);
	cout << "  - Name: ";
	getline(cin, this->Name);
}
