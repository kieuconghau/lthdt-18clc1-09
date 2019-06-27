#pragma once

#include "cAnimal.h"
#include "Graphic.h"

class cDinosaur : public cAnimal
{
public:
	static const unsigned int N = 5;
	cDinosaur(ecDirection direction, ecColor color, unsigned int x, unsigned int y);
	void draw(unsigned int leftLimit, unsigned int rightLimit);
	void move(unsigned int leftLimit, unsigned int rightLimit);

private:
	char Shapes[cDinosaur::N];
};
