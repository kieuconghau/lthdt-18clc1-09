#include <iostream>
#include <conio.h>
using namespace std;

#include "cGame.h"

int main()
{
	int x = 0, y = 0;

	//system("color 80");
	text_color(cColor::CYAN);
	for (int i = 0; i < 75; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			goto_xy(2 + i, 2 * (j + 1) + 1);
			
			if (j % 4 == 0)
				cout << char(32) << char(220) << char(219) << char(219) << char(220) << endl;
			else if (j % 4 == 1)
				cout << char(32) << char(220) << char(220) << char(219) << char(219) << endl;
			else if (j % 4 == 2)
				cout << char(32) << char(223) << char(220) << char(220) << char(223) << endl;
			else
				cout << char(32) << char(254) << char(220) << char(219) << char(223) << endl;
		}

		if (GetAsyncKeyState(VK_LEFT) != 0)
		{
			if (--x < 0)
				x = 0;
			goto_xy(x, y);
			cout << char(32) << char(79) << char(32);
		}
		else if (GetAsyncKeyState(VK_RIGHT) != 0)
		{
			if (++x >= 21)
				x = 20;
			goto_xy(x, y);
			cout << char(32) << char(79) << char(32);
		}
		else if (GetAsyncKeyState(VK_DOWN) != 0)
		{
			if (++y >= 21)
				y = 20;

			goto_xy(x, y - 1);
			cout << char(32);

			goto_xy(x, y);
			cout << char(79);
		}
		else if (GetAsyncKeyState(VK_UP) != 0)
		{
			if (--y < 0)
				y = 0;
			goto_xy(x, y);
			cout << char(79);
		}

		Sleep(100);
	}

	return 0;
}