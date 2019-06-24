#include "cTextBox.h"

cTextBox::cTextBox(cScreen screen, unsigned int x, unsigned int y, unsigned int width, string text, cColor textColor, cColor lineColor)
{
	this->Screen = screen;
	this->X = x;
	this->Y = y;
	this->Width = (width / 2) * 2 + 1;
	this->Text = text;
	this->TextColor = textColor;
	this->LineColor = lineColor;
}

void cTextBox::draw()
{
	// Draw Text
	text_color(this->TextColor);
	goto_xy(this->X - this->Text.length() / 2, this->Y);
	cout << this->Text;
	
	// Draw outline
	text_color(this->LineColor);
	goto_xy(this->X - this->Width / 2, this->Y - 1);
	cout << char(201);
	for (int i = 0; i < this->Width - 2; i++)
		cout << char(205);
	cout << char(187);
	goto_xy(this->X - this->Width / 2, this->Y);
	cout << char(186);
	goto_xy(this->X + this->Width / 2, this->Y);
	cout << char(186);
	goto_xy(this->X - this->Width / 2, this->Y + 1);
	cout << char(200);
	for (int i = 0; i < this->Width - 2; i++)
		cout << char(205);
	cout << char(188);

	// Reset color
	text_color();
	goto_xy(0, 0);
}

void cTextBox::draw(cColor textColor, cColor lineColor)
{
	// Draw Text
	text_color(textColor);
	goto_xy(this->X - this->Text.length() / 2, this->Y);
	cout << this->Text;

	// Draw outline
	text_color(lineColor);
	goto_xy(this->X - this->Width / 2, this->Y - 1);
	cout << char(201);
	for (int i = 0; i < this->Width - 2; i++)
		cout << char(205);
	cout << char(187);
	goto_xy(this->X - this->Width / 2, this->Y);
	cout << char(186);
	goto_xy(this->X + this->Width / 2, this->Y);
	cout << char(186);
	goto_xy(this->X - this->Width / 2, this->Y + 1);
	cout << char(200);
	for (int i = 0; i < this->Width - 2; i++)
		cout << char(205);
	cout << char(188);

	// Reset color
	text_color();
	goto_xy(0, 0);
}

cScreen scrolling_menu(vector<cTextBox> menu, cColor color)
{
	int pointer = 0;
	int n = menu.size();

	while (true)
	{
		for (int i = 0; i < n; ++i)
			if (i == pointer)
				menu[i].draw(color, color);
			else
				menu[i].draw();

		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer--;
				if (pointer == -1)
					pointer = n - 1;
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer++;
				if (pointer == n)
					pointer = 0;
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				Sleep(200);
				return menu[pointer].Screen;
			}
		}

		Sleep(150);
	}
}