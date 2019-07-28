#include "cMinistry.h"

cMinistry::cMinistry(cLecturerCollection* lecturerCollection, cStudentCollection* studentCollection)
{
	this->LecturerCollection = lecturerCollection;
	this->StudentCollection = studentCollection;
}

void cMinistry::show_list_lecturers()
{
	cIterator* iterator = this->LecturerCollection->create_iterator();
	cout << "~ List of lecturers ~" << endl;
	this->show_list(iterator);
	delete iterator;
}

void cMinistry::show_list_students()
{
	cIterator* iterator = this->StudentCollection->create_iterator();
	cout << "~ List of students ~" << endl;
	this->show_list(iterator);
	delete iterator;
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

void cMinistry::show_list(cIterator* iterator)
{
	int i = 0;
	for (iterator->first(); !iterator->is_done(); iterator->next())
	{
		cout << " #" << i + 1 << endl;
		iterator->current_item()->show_info();
		++i;
	}
}
