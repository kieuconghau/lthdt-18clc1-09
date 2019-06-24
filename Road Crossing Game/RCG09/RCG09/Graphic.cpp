#include "Graphic.h"

void goto_xy(const unsigned int& column, const unsigned int& line)
{
	COORD coord = { column, line };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

unsigned int where_x()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.X;
}

unsigned int where_y()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwCursorPosition.Y;
}

void text_color(const cColor& color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), int(color));
}

void text_size(const unsigned int& size) {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;						// Width of each character in the font
	cfi.dwFontSize.Y = size;					// Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy(cfi.FaceName, L"Consolas");			// Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void zoom_full_console_window() {
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}

unsigned int get_console_width() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	return columns;
}

unsigned int get_console_height() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int rows;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	return rows;
}

void print_text_at_middle(unsigned int y, string text, cColor color, bool endline)
{
	text_color(color);
	goto_xy(get_console_width() / 2 - text.length() / 2, y);
	cout << text;
	if (endline == true) {
		std::cout << endl;
	}
	text_color();
}