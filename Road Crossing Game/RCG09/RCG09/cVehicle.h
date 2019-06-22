#pragma once

#include "cGraphic.h"

class cVehicle
{
public:
	cVehicle();
	virtual ~cVehicle();
	virtual void move(unsigned int x, unsigned int y) = 0;

protected:
	unsigned int X;
	unsigned int Y;
	cDirection Direction;

private:
};