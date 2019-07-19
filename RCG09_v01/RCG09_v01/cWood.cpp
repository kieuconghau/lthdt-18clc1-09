#include "cWood.h"

//const char cWood::BRICK_SHAPE(cSetting::Object::Wood::BRICK_SHAPE);
//
//const ecColor cWood::BRICK_COLOR(cSetting::Object::Wood::BRICK_COLOR);
//
//const int cWood::N(cSetting::Object::Wood::N);
//
//const vector<char> cWood::Shapes(cSetting::Object::Wood::SHAPES);


const char cWood::BRICK_SHAPE(char(177));

const ecColor cWood::BRICK_COLOR(ecColor::BLUE);

const int cWood::N(6);

const vector<char> cWood::Shapes({ char(219), char(219), char(219), char(219), char(219), char(219)
, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE
, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE
, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE });


cWood::cWood(ecDirection direction, ecColor color, int x, int y, int step)
	: cFloat(cObject::ecType::MV_CAR, cWood::N, direction, color, x, y, step)
{
	if (step > cWood::Shapes.size() - cWood::N)
		throw;
}

cWood::~cWood() {}


void cWood::move(int leftLimit, int rightLimit, int virtualDistance)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < cWood::N + this->Step; ++i)
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
		for (int i = 0; i < cWood::N + this->Step; i++)
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

void cWood::draw(int leftLimit, int rightLimit)
{
	text_color(this->Color);

	for (int i = 0; i < cWood::N + this->Step; i++)
	{
		if (i >= cWood::N)
		{
			text_color(cWood::BRICK_COLOR);
		}

		if (this->X[i] >= leftLimit && this->X[i] <= rightLimit)
		{
			goto_xy(this->X[i], this->Y);
			cout << cWood::Shapes[i];
		}
	}

	text_color();
	goto_xy(0, 0);
}

void cWood::tell()
{
	// do_sth
}

bool cWood::impact_xcor(int x)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		return x >= this->X[cWood::N - 1] && x <= this->X[0];
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		return x >= this->X[0] && x <= this->X[cWood::N - 1];
	}
	else
		throw;

	return false;
}

char cWood::brick_shape() {
	return this->BRICK_SHAPE;
}
ecColor cWood::brick_color()
{
	return this->BRICK_COLOR;
}


