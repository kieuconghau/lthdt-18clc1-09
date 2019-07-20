#include "cMinistryB.h"

cMinistryB::cMinistryB(cLecturerCollection* lecturerCollection, cStudentCollection* studentCollection)
{
	this->LecturerCollection = lecturerCollection;
	this->StudentCollection = studentCollection;
}

void cMinistryB::add_one_lecturer(const cLecturer& lecturer)
{
	if (this->LecturerCollection->Count == this->LecturerCollection->MAX)
		throw;	// Full

	*this->LecturerCollection->Lecturers[this->LecturerCollection->Count++] = lecturer;
}

void cMinistryB::add_one_student(const cStudent& student)
{
	cStudent* newStudent = new cStudent(student);
	newStudent->next() = this->StudentCollection->Head;
	this->StudentCollection->Head = newStudent;
}


