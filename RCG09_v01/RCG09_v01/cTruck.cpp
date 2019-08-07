#include "cTruck.h"

//const char cTruck::BRICK_SHAPE(cSetting::Object::Truck::BRICK_SHAPE);
//
//const ecColor cTruck::BRICK_COLOR(cSetting::Object::Truck::BRICK_COLOR);
//
//const int cTruck::N(cSetting::Object::Truck::N);
//
//const vector<char> cTruck::Shapes(cSetting::Object::Truck::SHAPES);


const char cTruck::BRICK_SHAPE(char(219));

const ecColor cTruck::BRICK_COLOR(ecColor::BLACK);

const int cTruck::N(4);

const vector<char> cTruck::Shapes({ char(219), char(219), char(220), char(220)
, cTruck::BRICK_SHAPE, cTruck::BRICK_SHAPE, cTruck::BRICK_SHAPE
, cTruck::BRICK_SHAPE, cTruck::BRICK_SHAPE, cTruck::BRICK_SHAPE
, cTruck::BRICK_SHAPE, cTruck::BRICK_SHAPE, cTruck::BRICK_SHAPE });


cTruck::cTruck(ecDirection direction, ecColor color, int x, int y, int step, int crazyStep)
	: cVehicle(cObject::ecType::MV_TRUCK, cTruck::N, direction, color, x, y, step, crazyStep)
{
	if (step + crazyStep > cTruck::Shapes.size() - cTruck::N)
		throw;
}

cTruck::~cTruck() {}


void cTruck::move(int leftLimit, int rightLimit, int virtualDistance)
{
	int crazyFlag = 0;

	if (this->State == ecState::CRAZY)
		crazyFlag = 1;
	else
		crazyFlag = 0;

	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < cTruck::N + this->Step + this->CrazyStep; ++i)
		{
			this->X[i] += this->Step + this->CrazyStep * crazyFlag;

			if (this->X[i] >= rightLimit + virtualDistance + 1)
			{
				this->X[i] = leftLimit + (this->X[i] - (rightLimit + virtualDistance + 1));
			}
		}
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		for (int i = 0; i < cTruck::N + this->Step + this->CrazyStep; i++)
		{
			this->X[i] -= this->Step + this->CrazyStep * crazyFlag;

			if (this->X[i] <= leftLimit - 1)
			{
				this->X[i] = rightLimit + virtualDistance - ((leftLimit - 1) - this->X[i]);
			}
		}
	}
	else
		throw;
}

void cTruck::draw(int leftLimit, int rightLimit)
{
	text_color(this->Color);
	int crazyFlag = 0;

	if (this->State == ecState::CRAZY)
	{
		crazyFlag = 1;
		//text_color(ecColor::RED);
	}
	else if (this->State == ecState::NORMAL)
	{
		crazyFlag = 0;
		text_color(this->Color);
	}

	for (int i = 0; i < cTruck::N + this->Step + this->CrazyStep * crazyFlag; i++)
	{
		if (i >= cTruck::N)
		{
			text_color(cTruck::BRICK_COLOR);
		}

		if (this->X[i] >= leftLimit && this->X[i] <= rightLimit)
		{
			goto_xy(this->X[i], this->Y);
			cout << cTruck::Shapes[i];
		}
	}

	text_color();
	goto_xy(0, 0);
}

void cTruck::tell()
{
	PlaySound(TEXT("truck.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

bool cTruck::impact_xcor(int x)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		return x >= this->X[cTruck::N - 1] && x <= this->X[0];
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		return x >= this->X[0] && x <= this->X[cTruck::N - 1];
	}
	else
		throw;

	return false;
}

char cTruck::brick_shape() {
	return this->BRICK_SHAPE;
}
ecColor cTruck::brick_color()
{
	return this->BRICK_COLOR;
}