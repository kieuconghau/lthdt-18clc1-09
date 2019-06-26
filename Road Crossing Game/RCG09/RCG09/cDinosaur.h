#pragma once

#include "cAnimal.h"
#include "Graphic.h"


class cDinosaur : public cAnimal
{
public:
	static const unsigned int N = 5;
	cDinosaur(cDirection direction, cColor color, unsigned int x, unsigned int y);
	void draw();
	void move(unsigned int leftLimit = 0, unsigned int rightLimit = get_console_width()-1);
private:
	char Shape[cDinosaur::N];
};