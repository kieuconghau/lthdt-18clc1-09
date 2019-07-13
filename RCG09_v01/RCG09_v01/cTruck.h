#pragma once

#include "cSetting.h"
#include "cVehicle.h"
#include "cPeople.h"

class cTruck : public cVehicle
{
public:
	static const char BRICK_SHAPE;
	static const ecColor BRICK_COLOR;

public:
	cTruck(ecDirection direction, ecColor color, int x, int y, int step);
	~cTruck();

public:
	void move(int leftLimit, int rightLimit, int virtualDistance);
	void draw(int leftLimit, int rightLimit);
	void tell();
	char brick_shape();
	ecColor brick_color();

private:
	static const int N;
	static const vector<char> Shapes;

private:
	bool impact_xcor(int x);
};

