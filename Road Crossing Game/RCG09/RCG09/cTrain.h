#pragma once

#include "Graphic.h"
#include "cVehicle.h"

class cTrain : public cVehicle
{
public:
	cTrain(ecDirection direction, ecColor color, unsigned int x, unsigned int y);
	void draw(unsigned int leftLimit, unsigned int rightLimit);
	void move(unsigned int leftLimit, unsigned int rightLimit);

private:
	static const unsigned int N = 10*5 + 9 + 1;
	static const char Shapes[cTrain::N];
};
