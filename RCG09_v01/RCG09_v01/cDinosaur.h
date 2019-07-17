#pragma once

#include "cSetting.h"
#include "cAnimal.h"

class cDinosaur : public cAnimal
{
public:
	static const char BRICK_SHAPE;
	static const ecColor BRICK_COLOR;

public:
	cDinosaur(ecDirection direction, ecColor color, int x, int y, int step);
	~cDinosaur();

public:
	void move(int leftLimit, int rightLimit, int virtualDistance);
	void draw(int leftLimit, int rightLimit);
	void tell();
	bool impact_xcor(int x);
	char brick_shape();
	ecColor brick_color();
private:
	static const int N;
	static const vector<char> Shapes;
};
