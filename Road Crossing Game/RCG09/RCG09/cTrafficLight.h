#pragma once

#include "Graphic.h"
#include "cObject.h"

class cTrafficLight : public cObject
{
public:
	static const unsigned int N = 3;
	cTrafficLight(unsigned int x, unsigned int y, unsigned int timeRed, unsigned int timeYellow, unsigned int timeGreen);	// (x, y): Red light character
	void draw();

private:
	char Shapes[cTrafficLight::N];
	unsigned int Times[cTrafficLight::N];
};
