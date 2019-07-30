#pragma once

#include "cMovableObjectLane.h"
#include "cTrain.h"
#include "cCar.h"
#include "cTruck.h"
#include "cBird.h"
#include "cDinosaur.h"

#include "cFixedObjectLane.h"
#include "cCoin.h"
#include "cStone.h"

class cLaneFactory
{
public:
	static cLane* create(cObject::ecType objectType, ecDirection direction, ecColor color
		, int objectCount, int y, vector<int> time, int step, int crazyStep, int leftLimit, int rightLimit);
};

