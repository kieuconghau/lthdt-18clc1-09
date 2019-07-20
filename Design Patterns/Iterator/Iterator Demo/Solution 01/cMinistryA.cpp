#include "cMinistryA.h"

cMinistryA::cMinistryA(cLecturerCollection lecturerCollection, cStudentCollection studentCollection)
{
	this->LecturerCollection = lecturerCollection;
	this->StudentCollection = studentCollection;
}

void cMinistryA::show_list_lecturers()
{
	cout << "~ List of lecturers ~" << endl;
	for (int i = 0; i < this->LecturerCollection.Count; ++i)
	{
		cout << " #" << i + 1 << endl;
		this->LecturerCollection.Lecturers[i]->show_info();
	}
}

void cMinistryA::show_list_students()
{
	cout << "~ List of students ~" << endl;
	for (cStudent* st = this->StudentCollection.Head, int i = 0; st != nullptr; st = st->next(), ++i)
	{
		cout << " #" << i + 1 << endl;
		st->show_info();
	}
}

