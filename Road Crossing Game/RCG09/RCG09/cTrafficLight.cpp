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

void cTrafficLight::draw(unsigned int time)
{
	goto_xy(this->X[0], this->Y[0]);

	if (this->isGreenLight(time))
	{
		text_color(ecColor::LIGHT_RED);
		cout << this->Shapes[0];
		text_color(ecColor::LIGHT_YELLOW);
		cout << this->Shapes[1];
		text_color(ecColor::GREEN);
		cout << this->Shapes[2];
	}
	else if (this->isYellowLight(time))
	{
		text_color(ecColor::LIGHT_RED);
		cout << this->Shapes[0];
		text_color(ecColor::YELLOW);
		cout << this->Shapes[1];
		text_color(ecColor::LIGHT_GREEN);
		cout << this->Shapes[2];
	}
	else if (this->isRedLight(time))
	{
		text_color(ecColor::RED);
		cout << this->Shapes[0];
		text_color(ecColor::LIGHT_YELLOW);
		cout << this->Shapes[1];
		text_color(ecColor::LIGHT_GREEN);
		cout << this->Shapes[2];
	}

	goto_xy(0, 0);
	text_color();
}

void cTrafficLight::change_light_color(unsigned int& time)
{
	this->draw(time);
	
	if (time == this->Times[0] + this->Times[1] + this->Times[2])
		time = 0;
}

bool cTrafficLight::isGreenLight(unsigned int time)
{
	return time >= 1 && time <= this->Times[2];
}

bool cTrafficLight::isYellowLight(unsigned int time)
{
	return time >= this->Times[2] + 1 && time <= this->Times[2] + this->Times[1];
}

bool cTrafficLight::isRedLight(unsigned int time)
{
	return time >= this->Times[2] + this->Times[1] + 1 && time <= this->Times[2] + this->Times[1] + this->Times[0];
}