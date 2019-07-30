#pragma once
#include "cIterator.h"

class cLecturerCollectionIterator : public cIterator
{
public:
	cLecturerCollectionIterator(const cLecturerCollection* lecturerCollection);
	void first() override;
	void next() override;
	bool is_done() override;
	cLecturer* current_item();

private:
	const cLecturerCollection* collection;
	int index;
};

