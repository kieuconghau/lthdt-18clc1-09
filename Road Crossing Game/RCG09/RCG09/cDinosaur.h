#pragma once

#include "cAnimal.h"
#include "Graphic.h"

class cDinosaur : public cAnimal
{
public:
	cDinosaur(ecDirection direction, ecColor color, unsigned int x, unsigned int y);
	void draw(unsigned int leftLimit, unsigned int rightLimit);
	void move(unsigned int leftLimit, unsigned int rightLimit);

private:
	static const unsigned int N = 5;
	static const char Shapes[cDinosaur::N];
};
