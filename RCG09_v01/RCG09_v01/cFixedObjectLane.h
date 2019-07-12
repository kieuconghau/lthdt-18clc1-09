#pragma once

#include "cLane.h"
#include "cObjectFactory.h"
#include <stdlib.h>
#include <time.h>

class cFixedObjectLane : public cLane
{
public:
	cFixedObjectLane(cObject::ecType objectType, ecDirection direction, ecColor objectColor, int y, int objectCount, int leftLimit, int rightLimit, int virtualDistance=0);
	virtual ~cFixedObjectLane();

	void work() {};
	void impact_xcor(cPeople* people) {};

private:
	cObject::ecType FixedObjectType;
	cFixedObject** FixedObjects;
};
