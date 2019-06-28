#pragma once

#include "Graphic.h"
#include "cObject.h"

class cTrafficLight : public cObject
{
public:
	cTrafficLight(unsigned int x, unsigned int y, unsigned int timeRed, unsigned int timeYellow, unsigned int timeGreen);	// (x, y): Red light character
	void draw(unsigned int time);
	void change_light_color(unsigned int& time);

	bool isGreenLight(unsigned int time);
	bool isYellowLight(unsigned int time);
	bool isRedLight(unsigned int time);

private:
	static const unsigned int N = 3;
	static const char Shapes[cTrafficLight::N];
	const unsigned int Times[cTrafficLight::N];
};