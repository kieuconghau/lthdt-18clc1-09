#include "cTextBox.h"

cTextBox::cTextBox(cTextBox::ecScreenType screenType, int x, int y, int width, string text, ecColor textColor, ecColor lineColor)
{
	this->ScreenType = screenType;
	this->X = x;
	this->Y = y;
	this->Width = (width / 2) * 2 + 1;
	this->Text = text;
	this->TextColor = textColor;
	this->LineColor = lineColor;
}

cTextBox::~cTextBox() {}

void cTextBox::draw()
{
	text_color(this->TextColor);
	goto_xy(this->X - int(this->Text.length()) / 2, this->Y);
	cout << this->Text;

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

	text_color();
	goto_xy(0, 0);
}

void cTextBox::draw(ecColor textColor, ecColor lineColor)
{
	text_color(textColor);
	goto_xy(this->X - int(this->Text.length()) / 2, this->Y);
	cout << this->Text;

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

	text_color();
	goto_xy(0, 0);
}

cTextBox::ecScreenType cTextBox::scrolling_menu(vector<cTextBox> menu, ecColor color)
{
	Sleep(150);

	int pointer = 0;
	int n = int(menu.size());

	while (true)
	{
		int flag = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i == pointer)
				menu[i].draw(color, color);
			else
				menu[i].draw();
		}

		while (true)
		{
			if ((GetAsyncKeyState(VK_UP) & 0x8000) && (flag == 0))
			{
				flag = 1;
				pointer--;
				if (pointer == -1)
					pointer = n - 1;
				break;
			}
			else if ((GetAsyncKeyState(VK_DOWN) & 0x8000) && (flag == 0))
			{
				flag = 1;	
				pointer++;
				if (pointer == n)
					pointer = 0;
				break;
			}
			else if ((GetAsyncKeyState(VK_RETURN) & 0x8000) && (flag == 0))
			{
				flag = 1;
				Sleep(150);
				return menu[pointer].ScreenType;
			}
		}

		Sleep(150);
	}
}