#include "cLecturerCollectionIterator.h"



cLecturerCollectionIterator::cLecturerCollectionIterator(const cLecturerCollection* lecturerCollection)
{
	this->collection = lecturerCollection;
	this->index = 0;
}
void cLecturerCollectionIterator::first()
{
	index=0;
}
void cLecturerCollectionIterator::next()
{
	index++;
}
bool cLecturerCollectionIterator::is_end()
{
	return index == collection->Count;
}
cLecturer* cLecturerCollectionIterator::current_item()
{
	return collection->Lecturers[index];
}

cIterator* cLecturerCollection::create_iterator()
{
	return new cLecturerCollectionIterator(this);
}