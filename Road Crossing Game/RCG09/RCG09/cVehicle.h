#pragma once

#include "Graphic.h"
#include "cObstacle.h"

enum class cVehicleType
{
	CAR,
	TRUCK
};

class cVehicle : public cObstacle
{
public:
	cVehicle(unsigned int n, cDirection direction, cColor color, unsigned int x, unsigned int y);
	virtual ~cVehicle();

	virtual void draw() = 0;
	virtual void move(unsigned int leftLimit = 0, unsigned int rightLimit = get_console_width()) = 0;

protected:
	cDirection Direction;
	cColor Color;
	//cVehicleType Type;
};