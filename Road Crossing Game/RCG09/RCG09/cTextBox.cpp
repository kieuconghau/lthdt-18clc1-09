#include "cTextBox.h"

cTextBox::cTextBox(cScreen screen, unsigned int x, unsigned int y, unsigned int d, string text, cColor textColor, cColor lineColor)
{
	this->Screen = screen;
	this->X = x;
	this->Y = y;
	this->D = d;
	this->Text = text;
	this->TextColor = textColor;
	this->LineColor = lineColor;
}

void cTextBox::draw()
{
	int text_length = this->Text.length();
	goto_xy(this->X, this->Y);
}

void cTextBox::erase()
{
}
