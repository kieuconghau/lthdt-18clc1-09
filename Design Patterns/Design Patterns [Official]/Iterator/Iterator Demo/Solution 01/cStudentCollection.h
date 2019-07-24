#pragma once

#include "cStudent.h"
class cIterator;
class cStudentCollection
{
	friend class cMinistry;
	friend class cStudentCollectionIterator;
public:
	cStudentCollection();
	~cStudentCollection();
	cIterator* create_iterator();
private:
	cStudent* Head;
};
