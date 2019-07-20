/* Only for updating info */
#pragma once

#include "cLecturerCollection.h"
#include "cStudentCollection.h"

class cMinistryB
{
public:
	cMinistryB(cLecturerCollection* lecturerCollection, cStudentCollection* studentCollection);
	void add_one_lecturer(const cLecturer& lecturer);
	void add_one_student(const cStudent& student);

private:
	cLecturerCollection* LecturerCollection;
	cStudentCollection* StudentCollection;
};
