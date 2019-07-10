#pragma once
#pragma warning(disable:4996)

#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

enum class ecColor
{
<<<<<<< HEAD
	BLACK = 0,
	GREY = 8,
=======
	LIGHT_BLUE = 1,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	LIGHT_WHITE,
	GREY,
>>>>>>> 3cd397dbc61891256a431c7f9d0043b150b100b0
	BLUE,
	GREEN,
	CYAN,
	RED,
	PURPLE,
	YELLOW,
	WHITE
};

enum class ecDirection
{
	LEFT,
	RIGHT,
	DOWN,
	UP
};

void goto_xy(const unsigned int& column, const unsigned int& line);
unsigned int where_x();
unsigned int where_y();

void text_color(const ecColor& color=ecColor::WHITE);
void text_size(const unsigned int& size);

void zoom_full_console_window();
unsigned int get_console_width();
unsigned int get_console_height();

void print_text_at_middle(unsigned int y, string text, ecColor color, bool endline);
