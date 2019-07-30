#include "cBird.h"

//const char cBird::BRICK_SHAPE(cSetting::Object::Bird::BRICK_SHAPE);
//
//const ecColor cBird::BRICK_COLOR(cSetting::Object::Bird::BRICK_COLOR);
//
//const int cBird::N(cSetting::Object::Bird::N);
//
//const vector<char> cBird::Shapes(cSetting::Object::Bird::SHAPES);


const char cBird::BRICK_SHAPE(char(219));

const ecColor cBird::BRICK_COLOR(ecColor::BLACK);

const int cBird::N(4);

const vector<char> cBird::Shapes({ char(223), char(220), char(220), char(223)
, cBird::BRICK_SHAPE, cBird::BRICK_SHAPE, cBird::BRICK_SHAPE
, cBird::BRICK_SHAPE, cBird::BRICK_SHAPE, cBird::BRICK_SHAPE
, cBird::BRICK_SHAPE, cBird::BRICK_SHAPE, cBird::BRICK_SHAPE });


cBird::cBird(ecDirection direction, ecColor color, int x, int y, int step, int crazyStep)
	: cAnimal(cObject::ecType::MA_BIRD, cBird::N, direction, color, x, y, step, crazyStep)
{
	if (step + crazyStep > cBird::Shapes.size() - cBird::N)
		throw;
}

cBird::~cBird() {}


void cBird::move(int leftLimit, int rightLimit, int virtualDistance)
{
	int crazyFlag = 0;

	if (this->State == ecState::CRAZY)
		crazyFlag = 1;
	else
		crazyFlag = 0;

	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < cBird::N + this->Step + this->CrazyStep; ++i)
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
		for (int i = 0; i < cBird::N + this->Step + this->CrazyStep; i++)
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

void cBird::draw(int leftLimit, int rightLimit)
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

	for (int i = 0; i < cBird::N + this->Step + this->CrazyStep * crazyFlag; i++)
	{
		if (i >= cBird::N)
		{
			text_color(cBird::BRICK_COLOR);
		}

		if (this->X[i] >= leftLimit && this->X[i] <= rightLimit)
		{
			goto_xy(this->X[i], this->Y);
			cout << cBird::Shapes[i];
		}
	}

	text_color();
	goto_xy(0, 0);
}


void cBird::tell()
{
	PlaySound(TEXT("bird.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

bool cBird::impact_xcor(int x)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		return x >= this->X[cBird::N - 1] && x <= this->X[0];
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		return x >= this->X[0] && x <= this->X[cBird::N - 1];
	}
	else
		throw;

	return false;
}

char cBird::brick_shape() {
	return this->BRICK_SHAPE;
}
ecColor cBird::brick_color()
{
	return this->BRICK_COLOR;
}
