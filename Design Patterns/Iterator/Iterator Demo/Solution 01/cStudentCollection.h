#pragma once

#include "cStudent.h"

class cStudentCollection
{
	friend class cMinistryA;
	friend class cMinistryB;
public:
	cStudentCollection();
	~cStudentCollection();

private:
	cStudent* Head;
};


