#include "cTrafficLight.h"

cTrafficLight::cTrafficLight(unsigned int x, unsigned int y, unsigned int timeRed, unsigned int timeYellow, unsigned int timeGreen) : X(x), Y(y)
{
	this->Shapes[0] = char(223);

	this->Times[0] = timeRed;
	this->Times[1] = timeYellow;
	this->Times[2] = timeGreen;
}

void cTrafficLight::draw(cColor color)
{
	goto_xy(this->X, this->Y);
	text_color(color);
	
	cout << this->Shapes[0];

	text_color();
	goto_xy(0, 0);
}