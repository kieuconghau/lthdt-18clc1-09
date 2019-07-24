#include "cLecturerCollection.h"

cLecturerCollection::cLecturerCollection()
{
	this->Count = 0;
	for (int i = 0; i < this->MAX; ++i)
		this->Lecturers[i] = nullptr;
}

cLecturerCollection::~cLecturerCollection()
{
	for (int i = 0; i < this->Count; ++i)
		delete this->Lecturers[i];
}

