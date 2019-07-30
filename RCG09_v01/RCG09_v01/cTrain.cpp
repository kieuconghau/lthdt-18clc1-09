#include "cTrain.h"

//const char cTrain::BRICK_SHAPE(cSetting::Object::Train::BRICK_SHAPE);
//
//const ecColor cTrain::BRICK_COLOR(cSetting::Object::Train::BRICK_COLOR);
//
//const int cTrain::N(cSetting::Object::Train::N);
//
//const vector<char> cTrain::Shapes(cSetting::Object::Train::SHAPES);


const char cTrain::BRICK_SHAPE(char(']'));

const ecColor cTrain::BRICK_COLOR(ecColor::GREY);

const int cTrain::N(35);

const vector<char> cTrain::Shapes({ char(220), char(219), char(219), char(219), char(219), char(205)
, char(219), char(219), char(219), char(219), char(219), char(205)
, char(219), char(219), char(219), char(219), char(219), char(205)
, char(219), char(219), char(219), char(219), char(219), char(205)
, char(219), char(219), char(219), char(219), char(219), char(205)
, char(219), char(219), char(219), char(219), char(219)
, cTrain::BRICK_SHAPE, cTrain::BRICK_SHAPE, cTrain::BRICK_SHAPE
, cTrain::BRICK_SHAPE, cTrain::BRICK_SHAPE, cTrain::BRICK_SHAPE
, cTrain::BRICK_SHAPE, cTrain::BRICK_SHAPE, cTrain::BRICK_SHAPE });

const int cTrain::DisappearTime = 450;


cTrain::cTrain(ecDirection direction, ecColor color, int x, int y, int step, int crazyStep)
	: cVehicle(cObject::ecType::MV_TRAIN, cTrain::N, direction, color, x, y, step, crazyStep)
{
	if (step + crazyStep > cTrain::Shapes.size() - cTrain::N)
		throw;
}

cTrain::~cTrain() {}

void cTrain::move(int leftLimit, int rightLimit, int virtualDistance)
{
	int crazyFlag = 0;

	if (this->State == ecState::CRAZY)
		crazyFlag = 1;
	else
		crazyFlag = 0;

	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < cTrain::N + this->Step + this->CrazyStep; ++i)
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
		for (int i = 0; i < cTrain::N + this->Step + this->CrazyStep; i++)
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

void cTrain::draw(int leftLimit, int rightLimit)
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

	for (int i = 0; i < cTrain::N + this->Step + this->CrazyStep * crazyFlag; i++)
	{
		if (i >= cTrain::N)
		{
			text_color(cTrain::BRICK_COLOR);
		}

		if (this->X[i] >= leftLimit && this->X[i] <= rightLimit)
		{
			goto_xy(this->X[i], this->Y);
			cout << cTrain::Shapes[i];
		}
	}

	text_color();
	goto_xy(0, 0);
}

void cTrain::tell()
{
	PlaySound(TEXT("train.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

bool cTrain::impact_xcor(int x)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		return x >= this->X[cTrain::N - 1] && x <= this->X[0];
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		return x >= this->X[0] && x <= this->X[cTrain::N - 1];
	}
	else
		throw;

	return false;
}

char cTrain::brick_shape()
{
	return this->BRICK_SHAPE;
}
ecColor cTrain::brick_color()
{
	return this->BRICK_COLOR;
}