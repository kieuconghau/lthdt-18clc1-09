#pragma once

#include "cLecturer.h"

class cLecturerCollections
{
public:
	cLecturerCollections();
	~cLecturerCollections();

	void input_all_infos();
	void show_all_infos();

private:
	cLecturer* Lecturers;
	int N;
};

