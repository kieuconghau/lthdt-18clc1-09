#pragma once
#pragma warning(disable:4996)

#include <Windows.h>

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

enum class cDirection
{
	LEFT,
	RIGHT,
	DOWN,
	UP
};

void goto_xy(const unsigned int& column, const unsigned int& line);
unsigned int where_x();
unsigned int where_y();

void text_color(const cColor& color=cColor::WHITE);
void text_size(const unsigned int& size);

void zoom_full_console_window();
unsigned int get_console_width();
unsigned int get_console_height();