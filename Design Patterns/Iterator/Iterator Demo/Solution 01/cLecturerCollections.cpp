#include "cLecturerCollections.h"

cLecturerCollections::cLecturerCollections()
{
	this->Lecturers = nullptr;
	this->N = 0;
}

cLecturerCollections::~cLecturerCollections()
{
	delete[] this->Lecturers;
}

void cLecturerCollections::input_all_infos()
{
	cout << "Input the quantity of Students: ";
	cin >> this->N;

	this->Lecturers = new cLecturer[this->N];
	for (int i = 0; i < this->N; i++)
	{
		cout << "#" << i + 1 << endl;
		this->Lecturers[i].input_info();
	}
}

void cLecturerCollections::show_all_infos()
{
	cout << "~ Lecturer Collection ~" << endl;
	for (int i = 0; i < this->N; i++)
	{
		cout << "#" << i + 1 << endl;
		this->Lecturers[i].show_info();
	}
}
