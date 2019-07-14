#pragma once

#include "cInedibleObject.h"

class cStone : public cInedibleObject
{
	friend class cFixedObjectLane;

public:
	static const char BRICK_SHAPE;
	static const ecColor BRICK_COLOR;

public:
	cStone(ecDirection direction, ecColor color, int x, int y);
	virtual ~cStone();

public:
	void draw(int leftLimit, int rightLimit);
	bool impact_xcor(int x);
	bool is_edible();
	void is_eaten() {}; // can't be eaten
	bool was_eaten() { return false; }
	char brick_shape();
	ecColor brick_color();

private:
	static const int N;
	static const vector<char> Shapes;
};