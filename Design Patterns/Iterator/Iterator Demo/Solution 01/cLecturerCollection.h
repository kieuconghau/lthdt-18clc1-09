#pragma once

#include "cLecturer.h"

class cLecturerCollection
{
	friend class cMinistryA;
	friend class cMinistryB;
public:
	cLecturerCollection();
	~cLecturerCollection();

private:
	static const int MAX = 100;
	cLecturer* Lecturers[MAX];
	int Count;
};
