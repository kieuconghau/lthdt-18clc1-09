#include "cCoin.h"


const char cCoin::BRICK_SHAPE(char(177));

const ecColor cCoin::BRICK_COLOR(ecColor::LIGHT_GREEN);

const int cCoin::N(1);

const vector<char> cCoin::Shapes({ char('$') });


cCoin::cCoin(ecDirection direction, ecColor color, int x, int y)
	: cEdibleObject(cObject::ecType::FE_COIN, cCoin::N, direction, color, x, y)
{
	this->State = coinState::AVAILABLE;
}

cCoin::~cCoin() {}

void cCoin::draw(int leftLimit, int rightLimit)
{
	if (this->State == coinState::AVAILABLE) {
		text_color(this->Color);

		for (int i = 0; i < cCoin::N; i++)
		{
			if (this->X[i] >= leftLimit && this->X[i] <= rightLimit)
			{
				goto_xy(this->X[i], this->Y);
				cout << cCoin::Shapes[i];
			}
		}
	}

	text_color();
	goto_xy(0, 0);
}

bool cCoin::impact_xcor(int x)
{
	if (this->Direction == ecDirection::RIGHT)
		return x >= this->X[cCoin::N - 1] && x <= this->X[0];
	else if (this->Direction == ecDirection::LEFT)
		return x >= this->X[0] && x <= this->X[cCoin::N - 1];
	else
		throw;

	return false;
}

bool cCoin::is_edible()
{
	return true;
}

void cCoin::is_eaten()
{ 
	this->State = coinState::UNAVAILABLE;
}

bool cCoin::was_eaten()
{
	return (this->State == coinState::UNAVAILABLE);
}

char cCoin::brick_shape() {
	return this->BRICK_SHAPE;
}
ecColor cCoin::brick_color()
{
	return this->BRICK_COLOR;
}