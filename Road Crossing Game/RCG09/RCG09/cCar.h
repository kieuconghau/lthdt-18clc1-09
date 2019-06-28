#pragma once

#include "Graphic.h"
#include "cVehicle.h"

class cCar : public cVehicle
{
public:
	cCar(ecDirection direction, ecColor color, unsigned int x, unsigned int y);
	void draw(unsigned int leftLimit, unsigned int rightLimit);
	void move(unsigned int leftLimit, unsigned int rightLimit);

private:
	static const unsigned int N = 5;
	static const char Shapes[cCar::N];
};
