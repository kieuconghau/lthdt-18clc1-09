#pragma once

#include "Graphic.h"
#include "cVehicle.h"
#include "cCar.h"
#include "cTruck.h"

class cVehicleFactory
{
public:
	static cVehicle* create(cVehicleType type, ecDirection direction, ecColor color, unsigned int x, unsigned int y);
};

