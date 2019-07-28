#include "cDinosaur.h"

//const char cDinosaur::BRICK_SHAPE(cSetting::Object::Dinosaur::BRICK_SHAPE);
//
//const ecColor cDinosaur::BRICK_COLOR(cSetting::Object::Dinosaur::BRICK_COLOR);
//
//const int cDinosaur::N(cSetting::Object::Dinosaur::N);
//
//const vector<char> cDinosaur::Shapes(cSetting::Object::Dinosaur::SHAPES);


const char cDinosaur::BRICK_SHAPE(char(219));

const ecColor cDinosaur::BRICK_COLOR(ecColor::BLACK);

const int cDinosaur::N(4);

const vector<char> cDinosaur::Shapes({ char(223), char(219), char(220), char(254)
, cDinosaur::BRICK_SHAPE, cDinosaur::BRICK_SHAPE, cDinosaur::BRICK_SHAPE
, cDinosaur::BRICK_SHAPE, cDinosaur::BRICK_SHAPE, cDinosaur::BRICK_SHAPE
, cDinosaur::BRICK_SHAPE, cDinosaur::BRICK_SHAPE, cDinosaur::BRICK_SHAPE });


cDinosaur::cDinosaur(ecDirection direction, ecColor color, int x, int y, int step)
	: cAnimal(cObject::ecType::MA_DINOSAUR, cDinosaur::N, direction, color, x, y, step)
{
	if (step > cDinosaur::Shapes.size() - cDinosaur::N)
		throw;
}

cDinosaur::~cDinosaur() {}


void cDinosaur::move(int leftLimit, int rightLimit, int virtualDistance)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < cDinosaur::N + this->Step; ++i)
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
		for (int i = 0; i < cDinosaur::N + this->Step; i++)
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

void cDinosaur::draw(int leftLimit, int rightLimit)
{
	text_color(this->Color);

	for (int i = 0; i < cDinosaur::N + this->Step; i++)
	{
		if (i >= cDinosaur::N)
		{
			text_color(cDinosaur::BRICK_COLOR);
		}

		if (this->X[i] >= leftLimit && this->X[i] <= rightLimit)
		{
			goto_xy(this->X[i], this->Y);
			cout << cDinosaur::Shapes[i];
		}
	}

	text_color();
	goto_xy(0, 0);
}

void cDinosaur::tell()
{
	PlaySound(TEXT("dino.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

bool cDinosaur::impact_xcor(int x)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		return x >= this->X[cDinosaur::N - 1] && x <= this->X[0];
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		return x >= this->X[0] && x <= this->X[cDinosaur::N - 1];
	}
	else
		throw;

	return false;
}

char cDinosaur::brick_shape() {
	return this->BRICK_SHAPE;
}
ecColor cDinosaur::brick_color()
{
	return this->BRICK_COLOR;
}
