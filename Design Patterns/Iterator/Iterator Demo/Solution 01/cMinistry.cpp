#include "cMinistry.h"

cMinistry::cMinistry(cLecturerCollection* lecturerCollection, cStudentCollection* studentCollection)
{
	this->LecturerCollection = lecturerCollection;
	this->StudentCollection = studentCollection;
}

void cMinistry::show_list_lecturers()
{
	cout << "~ List of lecturers ~" << endl;
	for (int i = 0; i < this->LecturerCollection->Count; ++i)
	{
		cout << " #" << i + 1 << endl;
		this->LecturerCollection->Lecturers[i]->show_info();
	}
}

void cMinistry::show_list_students()
{
	cout << "~ List of students ~" << endl;
	int i = 0;
	for (cStudent* st = this->StudentCollection->Head; st != nullptr; st = st->next())
	{
		cout << " #" << i++ + 1 << endl;
		st->show_info();
	}
}

void cMinistry::add_one_lecturer(const cLecturer& lecturer)
{
	if (this->LecturerCollection->Count == this->LecturerCollection->MAX)
		throw;	// Full

	*this->LecturerCollection->Lecturers[this->LecturerCollection->Count++] = lecturer;
}

void cMinistry::add_one_student(const cStudent& student)
{
	cStudent* newStudent = new cStudent(student);
	newStudent->next() = this->StudentCollection->Head;
	this->StudentCollection->Head = newStudent;
}
