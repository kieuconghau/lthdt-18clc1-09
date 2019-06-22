#pragma once

#include "cVehicle.h"
#include "cGraphic.h"

class cCar : public cVehicle
{
public:
	cCar();
	~cCar();
	void move(const unsigned int& x, const unsigned int& y);

private:
	unsigned int Coordinates[4];
};

