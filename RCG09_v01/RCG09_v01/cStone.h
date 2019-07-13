#pragma once

#include "cInedibleObject.h"

class cStone : public cInedibleObject
{
public:
	static const char BRICK_SHAPE;
	static const ecColor BRICK_COLOR;

public:
	cStone(ecDirection direction, ecColor color, int x, int y);
	virtual ~cStone();

public:
	void draw(int leftLimit, int rightLimit);
	bool impact_xcor(int x);

private:
	static const int N;
	static const vector<char> Shapes;
};