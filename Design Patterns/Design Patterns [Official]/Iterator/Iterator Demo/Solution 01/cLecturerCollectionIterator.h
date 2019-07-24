#pragma once

#include "cIterator.h"
class cLecturerCollectionIterator:public cIterator
{
public:
	cLecturerCollectionIterator(const cLecturerCollection* lecturerCollection);
	void first();
	void next();
	bool is_end();
	cLecturer* current_item();
private:
	const cLecturerCollection* collection;
	int index;
};

