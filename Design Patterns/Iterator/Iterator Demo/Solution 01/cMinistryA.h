/* Only for showing info */
#pragma once

#include "cLecturerCollection.h"
#include "cStudentCollection.h"

class cMinistryA
{
public:
	cMinistryA(cLecturerCollection lecturerCollection, cStudentCollection studentCollection);
	void show_list_lecturers();
	void show_list_students();

private:
	cLecturerCollection LecturerCollection;
	cStudentCollection StudentCollection;
};
