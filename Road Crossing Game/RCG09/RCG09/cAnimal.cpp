#include "cAnimal.h"

cAnimal::cAnimal(unsigned int n, ecDirection direction, ecColor color, unsigned int x, unsigned int y) : cObject(n, direction, x, y)
{
	this->Direction = direction;
	this->Color = color;
}

cAnimal::~cAnimal() { }