#include "cTrafficLight.h"

cTrafficLight::cTrafficLight(unsigned int x, unsigned int y, unsigned int timeRed, unsigned int timeYellow, unsigned int timeGreen) : cObject(cTrafficLight::N, x, y)
{
	this->Shapes[0] = char(223);
	this->Shapes[1] = char(223);
	this->Shapes[2] = char(223);

	this->Times[0] = timeRed;
	this->Times[1] = timeYellow;
	this->Times[2] = timeGreen;
}

void cTrafficLight::draw()
{
}