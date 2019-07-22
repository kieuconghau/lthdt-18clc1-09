#pragma once

#include "cLecturer.h"

class cLecturerCollection
{
	friend class cMinistry;
public:
	cLecturerCollection();
	~cLecturerCollection();

private:
	static const int MAX = 100;
	cLecturer* Lecturers[MAX];
	int Count;
};

