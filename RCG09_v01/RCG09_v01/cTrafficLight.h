#pragma once

#include "cSetting.h"
#include "cObject.h"

class cTrafficLight : public cObject
{
public:
	cTrafficLight(ecDirection direction, int x, int y, int timeRed, int timeYellow, int timeGreen);
	~cTrafficLight();

	bool impact(int x);

private:
	static const int N = 3;
	static const char Shapes[cTrafficLight::N];

	int Times[cTrafficLight::N];
	int TimeCount;

	void work();
	void draw();
	bool isGreenLight();
	bool isYellowLight();
	bool isRedLight();

	friend class cMovableObjectLane;
};
