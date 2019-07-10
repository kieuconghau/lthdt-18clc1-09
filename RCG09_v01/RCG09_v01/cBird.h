#pragma once

#include "cSetting.h"
#include "cAnimal.h"

class cBird : public cAnimal
{
public:
	static const char BRICK_SHAPE;
	static const ecColor BRICK_COLOR;

	cBird(ecDirection direction, ecColor color, int x, int y, int step);
	~cBird();

	void work(int leftLimit, int rightLimit, int virtualDistance);
	void tell();

private:
	static const int N;
	static const vector<char> Shapes;

	void draw(int leftLimit, int rightLimit);
	bool impact(int x);
};
