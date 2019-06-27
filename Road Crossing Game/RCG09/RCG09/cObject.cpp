#include "cObject.h"

cObject::cObject(unsigned int n, ecDirection direction, unsigned int x, unsigned int y)
{
	this->X = new unsigned int[n];
	for (unsigned int i = 0; i < n; i++)
	{
		if (direction == ecDirection::LEFT)
			this->X[i] = x + i;
		else if (direction == ecDirection::RIGHT)
			this->X[i] = x + i - n + 1;
		else
			throw;
	}

	this->Y = new unsigned int[n];
	for (unsigned int i = 0; i < n; i++)
		this->Y[i] = y;
}

void cObject::move(unsigned int leftLimit, unsigned int rightLimit) {}

cObject::cObject(unsigned int n, unsigned int x, unsigned int y)
{
	this->X = new unsigned int[n];
	for (unsigned int i = 0; i < n; i++)
		this->X[i] = x + i;

	this->Y = new unsigned int[n];
	for (unsigned int i = 0; i < n; i++)
		this->Y[i] = y;
}

cObject::~cObject()
{
	if (this->X != nullptr)
		delete[] this->X;

	if (this->Y != nullptr)
		delete[] this->Y;
}