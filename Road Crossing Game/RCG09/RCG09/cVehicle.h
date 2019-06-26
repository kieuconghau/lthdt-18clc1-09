#pragma once

#include "Graphic.h"

enum class cVehicleType
{
	CAR,
	TRUCK
};

enum class cVehilceState
{
	RUNNING,
	CRASHING
};

class cVehicle
{
public:
	cVehicle();
	cVehicle(unsigned int n, cDirection direction, cColor color, unsigned int x, unsigned int y);
	virtual ~cVehicle();

	virtual void draw() = 0;
	virtual void move(unsigned int leftLimit = 0, unsigned int rightLimit = get_console_width()) = 0;

protected:
	unsigned int* X;
	unsigned int* Y;
	cDirection Direction;
	cColor Color;
	//cVehicleType Type;
	//cVehilceState State;
};