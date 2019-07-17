#pragma once

#include "cTextBox.h"
#include "Graphic.h"
#include <iostream>

class cScreen
{
public:
	static void screen_account();
	static void screen_sign_up();
	static void screen_sign_in();
	static void screen_about();
	static void screen_menu();
	static void screen_game();
	static void screen_load_game();
	static void screen_load_mid_game();
	static void screen_save_game();
	static void screen_pause_game();
	static void screen_setting();
	static void screen_continue();
	static void screen_win();
	static void screen_game_over();
	static void screen_ending();
private:
	static void draw_coming_soon();
	static void screen_border_decoration(int distanceFromScreenBorder,int numberOfLine);
	static void screen_border_decoration_inside(int distanceFromScreenBorder);
	static void screen_border_decoration_outside_border(int distanceFromScreenBorder);
	static void screen_border_decoration_inside_border(int distanceFromScreenBorder);
	static void draw_win(ecColor color);
};

