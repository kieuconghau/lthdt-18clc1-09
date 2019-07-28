#pragma once
#include "cLecturer.h"

class cIterator;

class cLecturerCollection
{
	friend class cMinistry;
	friend class cLecturerCollectionIterator;
public:
	cLecturerCollection();
	~cLecturerCollection();                                                                                                                                                      
	cIterator* create_iterator();

private:
	static const int MAX = 100;
	cLecturer* Lecturers[MAX];
	int Count;
};

