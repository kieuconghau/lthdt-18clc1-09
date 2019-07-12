#include "cCar.h"

//const char cCar::BRICK_SHAPE(cSetting::Object::Car::BRICK_SHAPE);
//
//const ecColor cCar::BRICK_COLOR(cSetting::Object::Car::BRICK_COLOR);
//
//const int cCar::N(cSetting::Object::Car::N);
//
//const vector<char> cCar::Shapes(cSetting::Object::Car::SHAPES);


const char cCar::BRICK_SHAPE(char(219));

const ecColor cCar::BRICK_COLOR(ecColor::BLACK);

const int cCar::N(4);

const vector<char> cCar::Shapes({ char(220), char(219), char(219), char(220)
, cCar::BRICK_SHAPE, cCar::BRICK_SHAPE, cCar::BRICK_SHAPE
, cCar::BRICK_SHAPE, cCar::BRICK_SHAPE, cCar::BRICK_SHAPE
, cCar::BRICK_SHAPE, cCar::BRICK_SHAPE, cCar::BRICK_SHAPE });


cCar::cCar(ecDirection direction, ecColor color, int x, int y, int step)
	: cVehicle(cObject::ecType::MV_CAR, cCar::N, direction, color, x, y, step)
{
	if (step > cCar::Shapes.size() - cCar::N)
		throw;
}

cCar::~cCar() {}


void cCar::move(int leftLimit, int rightLimit, int virtualDistance)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < cCar::N + this->Step; ++i)
		{
			this->X[i] += this->Step;

			if (this->X[i] >= rightLimit + virtualDistance + 1)
			{
				this->X[i] = leftLimit + (this->X[i] - (rightLimit + virtualDistance + 1));
			}
		}
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		for (int i = 0; i < cCar::N + this->Step; i++)
		{
			this->X[i] -= this->Step;

			if (this->X[i] <= leftLimit - 1)
			{
				this->X[i] = rightLimit + virtualDistance - ((leftLimit - 1) - this->X[i]);
			}
		}
	}
	else
		throw;
}

void cCar::draw(int leftLimit, int rightLimit)
{
	text_color(this->Color);

	for (int i = 0; i < cCar::N + this->Step; i++)
	{
		if (i >= cCar::N)
		{
			text_color(cCar::BRICK_COLOR);
		}

		if (this->X[i] >= leftLimit && this->X[i] <= rightLimit)
		{
			goto_xy(this->X[i], this->Y);
			cout << cCar::Shapes[i];
		}
	}

	text_color();
	goto_xy(0, 0);
}

void cCar::tell()
{
	// do_sth
}

bool cCar::impact_xcor(int x)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		return x >= this->X[cCar::N - 1] && x <= this->X[0];
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		return x >= this->X[0] && x <= this->X[cCar::N - 1];
	}
	else
		throw;

	return false;
}
