#pragma once

#include "cIterator.h"
class cStudentCollectionIterator:public cIterator
{
public:
	cStudentCollectionIterator(const cStudentCollection* lecturerCollection);
	void first();
	void next();
	bool is_end();
	cStudent* current_item();
private:
	const cStudentCollection* collection;
	cStudent* index;
};

