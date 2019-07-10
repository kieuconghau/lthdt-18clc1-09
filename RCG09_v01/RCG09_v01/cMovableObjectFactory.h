#pragma once

#include "cCar.h"
#include "cTrain.h"
#include "cTruck.h"
#include "cBird.h"
#include "cDinosaur.h"

class cMovableObjectFactory
{
public:
	static cMovableObject* create(cObject::ecType movableObjectType, ecDirection direction, ecColor color, int x, int y, int step);
};