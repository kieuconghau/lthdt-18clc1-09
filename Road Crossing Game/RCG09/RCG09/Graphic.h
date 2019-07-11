#pragma once
#pragma warning(disable:4996)

#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;

enum class ecColor : char
{
	BLACK,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	LIGHT_WHITE,
	GREY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	PURPLE,
	YELLOW,
	WHITE
};

enum class ecDirection : char
{
	NONE,
	LEFT,
	RIGHT,
	DOWN,
	UP
};

void goto_xy(const int& column, const int& line);
int where_x();
int where_y();

void text_color(const ecColor& color = ecColor::BLACK);
bool text_size(const int& size);

bool zoom_full_console_window();
bool remove_scroll_bar();
bool fix_console_window();

int get_console_width();
int get_console_height();

void print_text_at_middle(int y, string text, ecColor color, bool endline);
