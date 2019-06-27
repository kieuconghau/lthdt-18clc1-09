#pragma once

#include "Graphic.h"

class cTrafficLight
{
public:
	static const unsigned int N = 1;
	cTrafficLight(unsigned int x, unsigned int y, unsigned int timeRed=3, unsigned int timeYellow=2, unsigned int timeGreen=5);
	void draw(ecColor color);

private:
	const unsigned int X;
	const unsigned int Y;
	char Shapes[cTrafficLight::N];
	unsigned int Times[3];
};