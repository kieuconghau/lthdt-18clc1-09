#include "cObject.h"

cObject::cObject(cObject::ecType objectType, int n, ecDirection direction, int x, int y, int step, int crazyStep)
{
	this->ObjectType = objectType;

	this->Direction = direction;

	this->X = new int[n + step + crazyStep];
	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < n + step + crazyStep; i++)
			this->X[i] = x - i;
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		for (int i = 0; i < n + step + crazyStep; i++)
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

