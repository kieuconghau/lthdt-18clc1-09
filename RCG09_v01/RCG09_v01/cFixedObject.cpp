#include "cFixedObject.h"

cFixedObject::cFixedObject(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y)
	: cObject(objectType, n, direction, x, y)
{
	this->Color = color;
}

cFixedObject::~cFixedObject() {}
