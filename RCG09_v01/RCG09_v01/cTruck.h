#pragma once

#include "cSetting.h"
#include "cVehicle.h"

class cTruck : public cVehicle
{
public:
	static const char BRICK_SHAPE;
	static const ecColor BRICK_COLOR;

	cTruck(ecDirection direction, ecColor color, int x, int y, int step);
	~cTruck();

	void work(int leftLimit, int rightLimit, int virtualDistance);
	void tell();

private:
	static const int N;
	static const vector<char> Shapes;

	void draw(int leftLimit, int rightLimit);
	bool impact_xcor(int x);
};
