#include "cVehicle.h"

cVehicle::cVehicle(unsigned int n, ecDirection direction, ecColor color, unsigned int x, unsigned int y) : cObject(n, direction, x, y)
{
	this->Direction = direction;
	this->Color = color;
}

cVehicle::~cVehicle() { }