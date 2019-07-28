#pragma once

#include "cEdibleObject.h"


class cCoin : public cEdibleObject
{
public:
	static const char BRICK_SHAPE;
	static const ecColor BRICK_COLOR;

public:
	cCoin(ecDirection direction, ecColor color, int x, int y);
	virtual ~cCoin();

public:
	void draw(int leftLimit, int rightLimit);
	bool impact_xcor(int x);
	bool is_edible();
	void is_eaten();
	bool was_eaten();
	char brick_shape();
	ecColor brick_color();
	void reset();
private:
	static const int N;
	static const vector<char> Shapes;
	eatState State;
};