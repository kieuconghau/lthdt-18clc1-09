#include "cStudentCollection.h"

cStudentCollection::cStudentCollection()
{
	this->Head = nullptr;
}

cStudentCollection::~cStudentCollection()
{
	cStudent* temp;
	while (this->Head)
	{
		temp = this->Head;
		this->Head = temp->next();
		delete temp;
	}
}
