#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Graphic.h"

enum class cScreen
{
	ACCOUNT = 1,
	SIGN_UP,
	SIGN_IN,
	ABOUT,
	MENU,
	GAME,
	LOAD_GAME,
	SAVE_GAME,
	SETTING,
	CONTINUE,
	WIN,
	GAME_OVER
};

class cTextBox
{
public:
	cTextBox(cScreen screen, unsigned int x, unsigned int y, unsigned int width, string text, ecColor text_color, ecColor line_color);
	void draw();
	void draw(ecColor textColor, ecColor lineColor);
	
	friend cScreen scrolling_menu(vector<cTextBox> menu, ecColor color);

private:
	cScreen Screen;
	unsigned int X;
	unsigned int Y;
	unsigned int Width;
	string Text;
	ecColor TextColor;
	ecColor LineColor;
};