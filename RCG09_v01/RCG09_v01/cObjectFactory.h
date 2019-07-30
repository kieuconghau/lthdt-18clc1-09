#pragma once

#include "cCar.h"
#include "cTrain.h"
#include "cTruck.h"
#include "cBird.h"
#include "cDinosaur.h"

#include "cWood.h"

#include "cStone.h"
#include "cCoin.h"

class cObjectFactory
{
public:
	static cMovableObject* create(cObject::ecType movableObjectType, ecDirection direction, ecColor color, int x, int y, int step, int crazyStep);
	static cFixedObject* create(cObject::ecType fixedObjectType, ecDirection direction, ecColor color, int x, int y);
};
