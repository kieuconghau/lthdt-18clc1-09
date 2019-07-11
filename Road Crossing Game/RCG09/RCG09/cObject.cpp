#include "cObject.h"

cObject::cObject(cObject::ecType objectType, int n, ecDirection direction, int x, int y, int step)
{
	this->ObjectType = objectType;

	this->Direction = direction;

	this->X = new int[n + step];
	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < n + step; i++)
			this->X[i] = x - i;
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		for (int i = 0; i < n + step; i++)
			this->X[i] = x + i;
	}
	else
		throw;

	this->Y = y;
}

cObject::~cObject()
{
	delete[] this->X;
}