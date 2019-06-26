#pragma once

#include "Graphic.h"
#include "cVehicle.h"

class cTruck : public cVehicle
{
public:
	static const unsigned int N = 5;
	cTruck(cDirection direction, cColor color, unsigned int x, unsigned int y);
	void draw();
	void move(unsigned int leftLimit = 0, unsigned int rightLimit = get_console_width() - 1);

private:
	char Shapes[cTruck::N];
};