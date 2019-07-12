#pragma once

#include "cEdibleObject.h"

class cCoin : public cEdibleObject
{
public:
	static const char BRICK_SHAPE;
	static const ecColor BRICK_COLOR;

	cCoin(ecDirection direction, ecColor color, int x, int y);
	virtual ~cCoin();

private:
	static const int N;
	static const vector<char> Shapes;

	bool impact_xcor(int x);
};

