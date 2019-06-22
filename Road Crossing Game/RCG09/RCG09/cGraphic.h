#pragma once
#pragma warning(disable:4996)

#include <iostream>
#include <Windows.h>
#include <vector>
using namespace std;

enum class cColor
{
	GREY = 8,
	BLUE,
	GREEN,
	CYAN,
	RED,
	PURPLE,
	YELLOW,
	WHITE
};

enum class cScreen
{
	EXIT,
	ACCOUNT,
	SIGN_UP,
	SIGN_IN,
	MENU,
	PLAY,
	SETTING
};

enum class cDirection
{
	LEFT,
	RIGHT,
	DOWN,
	UP
};

void goto_xy(const unsigned int column, const unsigned int line);
unsigned int where_x();
unsigned int where_y();

void text_color(const cColor color=cColor::WHITE);
void text_size(const unsigned int size);

void zoom_full_console_window();
unsigned int get_console_width();
unsigned int get_console_height();

cScreen scrolling_menu(vector<string> selections);