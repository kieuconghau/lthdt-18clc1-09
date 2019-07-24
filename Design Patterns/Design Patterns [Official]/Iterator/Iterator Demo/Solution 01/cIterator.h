#pragma once
#include "cLecturerCollection.h"
#include "cStudentCollection.h"
class cIterator
{
public:
	virtual void next() = 0;
	virtual void first() = 0;
	virtual bool is_end() = 0;
	virtual cUniversityPersonel* current_item()=0;
};

