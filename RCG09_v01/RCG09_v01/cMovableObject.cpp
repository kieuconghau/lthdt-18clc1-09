#include "cMovableObject.h"

cMovableObject::cMovableObject(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y, int step)
	: cObject(objectType, n, direction, x, y, step)
{
	this->Color = color;
	this->Step = step;
}

cMovableObject::~cMovableObject() {}
