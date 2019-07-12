#pragma once

#include "cSetting.h"
#include "cVehicle.h"

class cTrain : public cVehicle
{
public:
	static const char BRICK_SHAPE;
	static const ecColor BRICK_COLOR;

public:
	cTrain(ecDirection direction, ecColor color, int x, int y, int step);
	~cTrain();

public:
	void move(int leftLimit, int rightLimit, int virtualDistance);
	void draw(int leftLimit, int rightLimit);
	void tell();

private:
	static const int N;
	static const vector<char> Shapes;

private:
	bool impact_xcor(int x);
};

