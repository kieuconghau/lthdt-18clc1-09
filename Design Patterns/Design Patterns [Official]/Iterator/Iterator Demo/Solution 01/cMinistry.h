#pragma once
#include "cLecturerCollection.h"
#include "cStudentCollection.h"
#include "cIterator.h"

class cMinistry
{
public:
	cMinistry(cLecturerCollection* lecturerCollection, cStudentCollection* studentCollection);
	void show_list_lecturers();
	void show_list_students();
	void add_one_lecturer(const cLecturer& lecturer);
	void add_one_student(const cStudent& student);

private:
	cLecturerCollection* LecturerCollection;
	cStudentCollection* StudentCollection;

private:
	void show_list(cIterator* iterator);
};