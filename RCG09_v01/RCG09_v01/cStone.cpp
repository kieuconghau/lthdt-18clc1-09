#include "cStone.h"


const char cStone::BRICK_SHAPE(char(177));

const ecColor cStone::BRICK_COLOR(ecColor::LIGHT_GREEN);

const int cStone::N(2);

const vector<char> cStone::Shapes({ char(219), char(219) });


cStone::cStone(ecDirection direction, ecColor color, int x, int y)
	: cInedibleObject(cObject::ecType::FI_STONE, cStone::N, direction, color, x, y) {}

cStone::~cStone() {}


void cStone::draw(int leftLimit, int rightLimit)
{
	text_color(this->Color);

	for (int i = 0; i < cStone::N; i++)
	{
		if (this->X[i] >= leftLimit && this->X[i] <= rightLimit)
		{
			goto_xy(this->X[i], this->Y);
			cout << cStone::Shapes[i];
		}
	}

	text_color();
	goto_xy(0, 0);
}

bool cStone::impact_xcor(int x)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		return x >= this->X[cStone::N - 1] && x <= this->X[0];
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		return x >= this->X[0] && x <= this->X[cStone::N - 1];
	}
	else
		throw;

	return false;
}
