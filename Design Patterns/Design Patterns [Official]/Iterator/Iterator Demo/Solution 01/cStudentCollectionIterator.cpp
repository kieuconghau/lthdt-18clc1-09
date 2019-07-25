#include "cStudentCollectionIterator.h"



cStudentCollectionIterator::cStudentCollectionIterator(const cStudentCollection* studentCollection)
{
	this->collection = studentCollection;
	this->index = collection->Head;
}

void cStudentCollectionIterator::first()
{
	index = collection->Head;
}
void cStudentCollectionIterator::next()
{
	index = index->next();
}
bool cStudentCollectionIterator::is_end()
{
	return index == nullptr;
}
cStudent* cStudentCollectionIterator::current_item()
{
	return index;
}

cIterator* cStudentCollection::create_iterator()
{
	return new cStudentCollectionIterator(this);
}

