#pragma once

#include "cStudent.h"

class cStudentCollection
{
public:
	cStudentCollection();
	~cStudentCollection();

	void input_all_infos();
	void show_all_infos();

private:
	cStudent* Students;
	int N;
};

