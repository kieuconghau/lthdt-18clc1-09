#include "cWood.h"

//const char cWood::BRICK_SHAPE(cSetting::Object::Wood::BRICK_SHAPE);
//
//const ecColor cWood::BRICK_COLOR(cSetting::Object::Wood::BRICK_COLOR);
//
//const int cWood::N(cSetting::Object::Wood::N);
//
//const vector<char> cWood::Shapes(cSetting::Object::Wood::SHAPES);


const char cWood::BRICK_SHAPE(char(219));

const ecColor cWood::BRICK_COLOR(ecColor::LIGHT_YELLOW);

const int cWood::N(9);

const vector<char> cWood::Shapes({ char(177), char(177), char(177), char(177), char(177), char(177), char(177), char(177), char(177)
, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE
, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE
, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE, cWood::BRICK_SHAPE });


cWood::cWood(ecDirection direction, ecColor color, int x, int y, int step, int crazyStep)
	: cFloat(cObject::ecType::MV_CAR, cWood::N, direction, color, x, y, step, crazyStep)
{
	if (step + crazyStep > cWood::Shapes.size() - cWood::N)
		throw;
}

cWood::~cWood() {}


void cWood::move(int leftLimit, int rightLimit, int virtualDistance)
{
	int crazyFlag = 0;

	if (this->State == ecState::CRAZY)
		crazyFlag = 1;
	else
		crazyFlag = 0;

	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < cWood::N + this->Step + this->CrazyStep; ++i)
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
		for (int i = 0; i < cWood::N + this->Step + this->CrazyStep; i++)
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

void cWood::draw(int leftLimit, int rightLimit)
{
	text_color(this->Color);
	int crazyFlag = 0;

	if (this->State == ecState::CRAZY)
	{
		crazyFlag = 1;
		text_color(ecColor::RED);
	}
	else if (this->State == ecState::NORMAL)
	{
		crazyFlag = 0;
		text_color(this->Color);
	}

	for (int i = 0; i < cWood::N + this->Step + this->CrazyStep * crazyFlag; i++)
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


