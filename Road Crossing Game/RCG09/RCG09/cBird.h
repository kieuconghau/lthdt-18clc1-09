#pragma once

#include "Graphic.h"
#include "cAnimal.h"

class cBird : public cAnimal
{
public:
	static const unsigned int N = 5;
	cBird(cDirection direction, cColor color, unsigned int x, unsigned int y);
	void draw();
	void move(unsigned int leftLimit = 0, unsigned int rightLimit = get_console_width()-1);
private:
	char Shape[cBird::N];
};