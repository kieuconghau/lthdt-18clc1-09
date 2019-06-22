#pragma once

#include "cGraphic.h"

/* 
case 1: |...ABC....|
case 2: |..ABCDEF..|
*/

class cTextBox
{
public:
	cTextBox(cScreen screen, unsigned int x, unsigned int y, unsigned int d=10, string text="Group 09", cColor textColor=cColor::WHITE, cColor lineColor=cColor::WHITE);
	void draw();
	void erase();

private:
	cScreen Screen;
	unsigned int X;
	unsigned int Y;
	unsigned int D;
	string Text;
	cColor TextColor;
	cColor LineColor;
};

