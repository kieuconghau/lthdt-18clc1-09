#pragma once

#include "cSetting.h"
#include "cVehicle.h"

class cTrain : public cVehicle
{
public:
	static const char BRICK_SHAPE;
	static const ecColor BRICK_COLOR;

	cTrain(ecDirection direction, ecColor color, int x, int y, int step);
	~cTrain();

	void work(int leftLimit, int rightLimit, int virtualDistance);
	void tell();

private:
	static const int N;
	static const vector<char> Shapes;

	void draw(int leftLimit, int rightLimit);
	bool impact_xcor(int x);
};
