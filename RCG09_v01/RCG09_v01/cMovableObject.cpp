#include "cMovableObject.h"

cMovableObject::cMovableObject(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y, int step, int crazyStep)
	: cObject(objectType, n, direction, x, y, step, crazyStep)
{
	this->Color = color;
	this->Step = step;
	this->CrazyStep = crazyStep;
	this->State = ecState::NORMAL;
}

cMovableObject::~cMovableObject() {}

void cMovableObject::crazy()
{
	this->State = ecState::CRAZY;
}

void cMovableObject::normal()
{
	this->State = ecState::NORMAL;
}
