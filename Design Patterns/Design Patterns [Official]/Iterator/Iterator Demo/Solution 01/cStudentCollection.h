#pragma once

#include "cStudent.h"

class cStudentCollection
{
	friend class cMinistry;
public:
	cStudentCollection();
	~cStudentCollection();

private:
	cStudent* Head;
};
