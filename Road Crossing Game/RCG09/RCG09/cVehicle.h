#pragma once

#include "Graphic.h"
#include "cObject.h"

enum class cVehicleType
{
	CAR,
	TRUCK
};

class cVehicle : public cObject
{
public:
	cVehicle(unsigned int n, ecDirection direction, ecColor color, unsigned int x, unsigned int y);
	virtual ~cVehicle();

	virtual void draw(unsigned int leftLimit, unsigned int rightLimit) = 0;
	virtual void move(unsigned int leftLimit, unsigned int rightLimit) = 0;

protected:
	ecDirection Direction;
	ecColor Color;
};
