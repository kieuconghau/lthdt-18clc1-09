#include "cCoin.h"


const char cCoin::BRICK_SHAPE(char(177));

const ecColor cCoin::BRICK_COLOR(ecColor::LIGHT_GREEN);

const int cCoin::N(1);

const vector<char> cCoin::Shapes({ char('$') });


cCoin::cCoin(ecDirection direction, ecColor color, int x, int y)
	: cEdibleObject(cObject::ecType::FE_COIN, cCoin::N, direction, color, x, y) {}

cCoin::~cCoin() {}

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
