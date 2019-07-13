#pragma once

#include "cSetting.h"
#include "cObject.h"

class cTrafficLight : public cObject
{
	friend class cMovableObjectLane;

public:
	cTrafficLight(ecDirection direction, int x, int y, int timeRed, int timeYellow, int timeGreen);
	~cTrafficLight();

public:
	bool impact_xcor(int x);

private:
	static const int N = 3;
	static const char Shapes[cTrafficLight::N];

private:
	int Times[cTrafficLight::N];
	int TimeCount;

private:
	void work();
	void draw();
	bool isGreenLight();
	bool isYellowLight();
	bool isRedLight();
};
