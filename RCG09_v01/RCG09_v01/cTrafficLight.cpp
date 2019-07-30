#include "cTrafficLight.h"


const char cTrafficLight::Shapes[cTrafficLight::N] = { char(223), char(223), char(223) };


cTrafficLight::cTrafficLight(ecDirection direction, int x, int y, int timeRed, int timeYellow, int timeGreen)
	: cObject(cObject::ecType::TRAFFIC_LIGHT, cTrafficLight::N, direction, x, y)
{
	this->Times[0] = timeRed;
	this->Times[1] = timeYellow;
	this->Times[2] = timeGreen;

	this->TimeCount = 0;
}

cTrafficLight::~cTrafficLight() {}


bool cTrafficLight::impact_xcor(int x)
{
	if (this->Direction == ecDirection::RIGHT)
		return x >= this->X[cTrafficLight::N - 1] && x <= this->X[0];
	else if (this->Direction == ecDirection::LEFT)
		return x >= this->X[0] && x <= this->X[cTrafficLight::N - 1];
	else
		throw;

	return false;
}

void cTrafficLight::draw()
{
	if (this->isGreenLight())
	{
		goto_xy(this->X[0], this->Y);
		text_color(ecColor::LIGHT_RED);
		cout << this->Shapes[0];
		goto_xy(this->X[1], this->Y);
		text_color(ecColor::LIGHT_YELLOW);
		cout << this->Shapes[1];
		goto_xy(this->X[2], this->Y);
		text_color(ecColor::GREEN);
		cout << this->Shapes[2];
	}
	else if (this->isYellowLight())
	{
		goto_xy(this->X[0], this->Y);
		text_color(ecColor::LIGHT_RED);
		cout << this->Shapes[0];
		goto_xy(this->X[1], this->Y);
		text_color(ecColor::YELLOW);
		cout << this->Shapes[1];
		goto_xy(this->X[2], this->Y);
		text_color(ecColor::LIGHT_GREEN);
		cout << this->Shapes[2];
	}
	else if (this->isRedLight())
	{
		goto_xy(this->X[0], this->Y);
		text_color(ecColor::RED);
		cout << this->Shapes[0];
		goto_xy(this->X[1], this->Y);
		text_color(ecColor::LIGHT_YELLOW);
		cout << this->Shapes[1];
		goto_xy(this->X[2], this->Y);
		text_color(ecColor::LIGHT_GREEN);
		cout << this->Shapes[2];
	}

	goto_xy(0, 0);
	text_color();
}

void cTrafficLight::work()
{
	if (++this->TimeCount == this->Times[0] + this->Times[1] + this->Times[2] + 1)
		this->TimeCount = 1;
}

bool cTrafficLight::isGreenLight()
{
	return this->TimeCount >= 1 && this->TimeCount <= this->Times[2];
}

bool cTrafficLight::isYellowLight()
{
	return this->TimeCount >= this->Times[2] + 1 && this->TimeCount <= this->Times[2] + this->Times[1];
}

bool cTrafficLight::isRedLight()
{
	return this->TimeCount >= this->Times[2] + this->Times[1] + 1 && this->TimeCount <= this->Times[2] + this->Times[1] + this->Times[0];
}
