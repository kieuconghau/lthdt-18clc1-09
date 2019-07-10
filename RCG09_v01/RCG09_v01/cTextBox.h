#pragma once

#include "Graphic.h"
#include <vector>
using namespace std;

class cTextBox
{
public:
	enum class ecScreenType : char
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
		MUSIC,
		CONTROL,
		CONTINUE,
		WIN,
		GAME_OVER,
		ENDING
	};

	cTextBox(cTextBox::ecScreenType screenType, int x, int y, int width, string text, ecColor text_color, ecColor line_color);
	~cTextBox();

	void draw(ecColor textColor, ecColor lineColor);
	void draw();
	static cTextBox::ecScreenType scrolling_menu(vector<cTextBox> menu, ecColor color);

private:
	cTextBox::ecScreenType ScreenType;
	int X;
	int Y;
	int Width;
	string Text;
	ecColor TextColor;
	ecColor LineColor;
};
