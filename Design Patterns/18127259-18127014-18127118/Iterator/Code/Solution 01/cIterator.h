#pragma once

#include "cLecturerCollection.h"
#include "cStudentCollection.h"

class cIterator
{
public:
	virtual void next() = 0;
	virtual void first() = 0;
	virtual bool is_done() = 0;
	virtual cUniversityPersonnel* current_item() = 0;
};

