#include "Screen.h"

void screen_account()
{
	system("cls");

	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " ____    ___    ____  ___           __  ____    ___    _____  _____ ____  ____    ____       ____   ____  ___ ___    ___ ", cColor::CYAN, true);
	print_text_at_middle(middleY - 14, "|    \\  /   \\  /    ||   \\         /  ]|    \\  /   \\  / ___/ / ___/|    ||    \\  /    |     /    | /    ||   |   |  /  _]", cColor::CYAN, true);
	print_text_at_middle(middleY - 13, "|  D  )|     ||  o  ||    \\       /  / |  D  )|     |(   \\_ (   \\_  |  | |  _  ||   __|    |   __||  o  || _   _ | /  [_ ", cColor::CYAN, true);
	print_text_at_middle(middleY - 12, "|    / |  O  ||     ||  D  |     /  /  |    / |  O  | \\__  | \\__  | |  | |  |  ||  |  |    |  |  ||     ||  \\_/  ||    _]", cColor::CYAN, true);
	print_text_at_middle(middleY - 11, "|    \\ |     ||  _  ||     |    /   \\_ |    \\ |     | /  \\ | /  \\ | |  | |  |  ||  |_ |    |  |_ ||  _  ||   |   ||   [_ ", cColor::CYAN, true);
	print_text_at_middle(middleY - 10, "|  .  \\|     ||  |  ||     |    \\     ||  .  \\|     | \\    | \\    | |  | |  |  ||     |    |     ||  |  ||   |   ||     |", cColor::CYAN, true);
	print_text_at_middle(middleY - 9, "|__|\\_| \\___/ |__|__||_____|     \\____||__|\\_| \\___/   \\___|  \\___||____||__|__||___,_|    |___,_||__|__||___|___||_____|", cColor::CYAN, true);

	print_text_at_middle(middleY - 7, "========= Group 09 * 18CLC1 =========", cColor::BLUE, true);

	cTextBox signUp(cScreen::SIGN_UP, middleX, middleY - 2, 25, "SIGN UP", cColor::WHITE, cColor::WHITE);
	cTextBox signIn(cScreen::SIGN_IN, middleX, middleY + 2, 25, "SIGN IN", cColor::WHITE, cColor::WHITE);
	cTextBox guest(cScreen::MENU, middleX, middleY + 6, 25, "GUEST", cColor::WHITE, cColor::WHITE);
	cTextBox about(cScreen::ABOUT, middleX, middleY + 10, 25, "ABOUT", cColor::WHITE, cColor::WHITE);

	vector<cTextBox> menuAccount = { signUp, signIn, guest, about };
	cScreen choice = scrolling_menu(menuAccount, cColor::RED);

	if (choice == cScreen::SIGN_UP)
		screen_sign_up();
	else if (choice == cScreen::SIGN_IN)
		screen_sign_in();
	else if (choice == cScreen::MENU)
		screen_menu();
	else if (choice == cScreen::ABOUT)
		screen_about();
	else
		throw;
}

void screen_sign_up()
{
	system("cls");




	cout << "Sign up" << endl;
}

void screen_sign_in()
{
	system("cls");

	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "  _____ ____   ____  ____       ____  ____  ", cColor::CYAN, true);
	print_text_at_middle(middleY - 14, " / ___/|    | /    ||    \\     |    ||    \\ ", cColor::CYAN, true);
	print_text_at_middle(middleY - 13, "(   \\_  |  | |   __||  _  |     |  | |  _  |", cColor::CYAN, true);
	print_text_at_middle(middleY - 12, " \\__  | |  | |  |  ||  |  |     |  | |  |  |", cColor::CYAN, true);
	print_text_at_middle(middleY - 11, " /  \\ | |  | |  |_ ||  |  |     |  | |  |  |", cColor::CYAN, true);
	print_text_at_middle(middleY - 10, " \\    | |  | |     ||  |  |     |  | |  |  |", cColor::CYAN, true);
	print_text_at_middle(middleY - 9, "  \\___||____||___,_||__|__|    |____||__|__|", cColor::CYAN, true);

	print_text_at_middle(middleY - 5, "< Coming soon >", cColor::WHITE, true);

	cTextBox back(cScreen::ACCOUNT, middleX, middleY, 25, "Back", cColor::WHITE, cColor::WHITE);

	vector<cTextBox> menuAccount = { back };
	cScreen choice = scrolling_menu(menuAccount, cColor::RED);

	if (choice == cScreen::ACCOUNT)
		screen_account();
	else
		throw;
}

void screen_about()
{
	system("cls");
	cout << "About" << endl;
}

void screen_menu()
{
	system("cls");
	cout << "Menu" << endl;
}

void screen_game()
{
	system("cls");

	int x = 0, y = 0;
	system("color 80");
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
}

void screen_load_game()
{
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;
	
	print_text_at_middle(middleY - 15, " _       ___    ____  ___         ____   ____  ___ ___    ___ ", cColor::BLUE, true);
	print_text_at_middle(middleY - 14, "| |     /   \\  /    ||   \\       /    | /    ||   |   |  /  _]", cColor::BLUE, true);
	print_text_at_middle(middleY - 13, "| |    |     ||  o  ||    \\     |   __||  o  || _   _ | /  [_ ", cColor::BLUE, true);
	print_text_at_middle(middleY - 12, "| |___ |  O  ||     ||  D  |    |  |  ||     ||  \\_/  ||    _]", cColor::BLUE, true);
	print_text_at_middle(middleY - 11, "|     ||     ||  _  ||     |    |  |_ ||  _  ||   |   ||   [_ ", cColor::BLUE, true);
	print_text_at_middle(middleY - 10, "|     ||     ||  |  ||     |    |     ||  |  ||   |   ||     |", cColor::BLUE, true);
	print_text_at_middle(middleY - 9, "|_____| \\___/ |__|__||_____|    |___,_||__|__||___|___||_____|", cColor::BLUE, true);

	cTextBox loadGame(cScreen::LOAD_GAME, middleX, middleY - 2, 25, "LOAD GAME", cColor::WHITE, cColor::WHITE);
	cTextBox back(cScreen::MENU, middleX, middleY + 2, 25,"BACK", cColor::WHITE, cColor::WHITE);

	vector<cTextBox> menuLoadGame = { loadGame,back };

	cScreen choice = scrolling_menu(menuLoadGame, cColor::RED);

	if (choice == cScreen::LOAD_GAME) {
		//loadgame;
	}
	else if (choice == cScreen::MENU) {
		screen_menu();
	}
	else exit(0);

}

void screen_save_game()
{
	system("cls");
	cout << "Save game" << endl;
}

void screen_setting()
{
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	draw_coming_soon();

	cTextBox back(cScreen::MENU, middleX, middleY + 2, 25, "BACK", cColor::WHITE, cColor::WHITE);

	vector<cTextBox> menuLoadGame = { back };

	cScreen choice = scrolling_menu(menuLoadGame, cColor::RED);

	if (choice == cScreen::SETTING) {
		//setting;
	}
	else if (choice == cScreen::MENU) {
		screen_menu();
	}
	else exit(0);
}

void screen_continue()
{
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "    __   ___   ____   ______  ____  ____   __ __    ___      _____ ", cColor::BLUE, true);
	print_text_at_middle(middleY - 14, "   /  ] /   \\ |    \\ |      ||    ||    \\ |  |  |  /  _]    /     |", cColor::BLUE, true);
	print_text_at_middle(middleY - 13, "  /  / |     ||  _  ||      | |  | |  _  ||  |  | /  [_     |  Y  |", cColor::BLUE, true);
	print_text_at_middle(middleY - 12, " /  /  |  O  ||  |  ||_|  |_| |  | |  |  ||  |  ||    _]    |__|  |", cColor::BLUE, true);
	print_text_at_middle(middleY - 11, "/   \\_ |     ||  |  |  |  |   |  | |  |  ||  :  ||   [_        |__|", cColor::BLUE, true);
	print_text_at_middle(middleY - 10, "\\     ||     ||  |  |  |  |   |  | |  |  ||     ||     |        __ ", cColor::BLUE, true);
	print_text_at_middle(middleY - 9, " \\____| \\___/ |__|__|  |__|  |____||__|__| \\____||_____|       |__|", cColor::BLUE, true);

	cTextBox yes(cScreen::GAME, middleX, middleY - 2, 25, "Yes", cColor::WHITE, cColor::WHITE);
	cTextBox no(cScreen::ENDING, middleX, middleY + 2, 25, "No", cColor::WHITE, cColor::WHITE);

	vector<cTextBox> menuLoadGame = { yes,no };

	cScreen choice = scrolling_menu(menuLoadGame, cColor::RED);

	if (choice == cScreen::GAME) {
		//game;
	}
	else if (choice == cScreen::ENDING) {
		screen_ending();
	}
	else exit(0);
	
}

void screen_win()
{
	system("cls");
	
	screen_border_decoration(17);

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 8, "                                                   ,---,  ", cColor::YELLOW, true);
	print_text_at_middle(middleY - 7, "                                   ,--.         ,`--.' |  ", cColor::YELLOW, true);
	print_text_at_middle(middleY - 6, "           .---.    ,---,        ,--.'|         |   :  :  ", cColor::YELLOW, true);
	print_text_at_middle(middleY - 5, "          /. ./| ,`--.' |    ,--,:  : |         '   '  ;  ", cColor::YELLOW, true);
	print_text_at_middle(middleY - 4, "      .--'.  ' ; |   :  : ,`--.'`|  ' :         |   |  |  ", cColor::YELLOW, true);
	print_text_at_middle(middleY - 3, "     /__./ \\ : | :   |  ' |   :  :  | |         '   :  ;  ", cColor::YELLOW, true);
	print_text_at_middle(middleY - 2, " .--'.  '   \\' . |   :  | :   |   \\ | :         |   |  '  ", cColor::YELLOW, true);
	print_text_at_middle(middleY - 1, "/___/ \\ |    ' ' '   '  ; |   : '  '; |         '   :  |  ", cColor::YELLOW, true);
	print_text_at_middle(middleY ,    ";   \\  \\;      : |   |  | '   ' ;.    ;         ;   |  ;  ", cColor::YELLOW, true);
	print_text_at_middle(middleY + 1, " \\   ;  `      | '   :  ; |   | | \\   |         `---'. |  ", cColor::YELLOW, true);
	print_text_at_middle(middleY + 2, "  .   \\    .\\  ; |   |  ' '   : |  ; .'          `--..`;  ", cColor::YELLOW, true);
	print_text_at_middle(middleY + 3, "   \\   \\   ' \\ | '   :  | |   | '`--'           .--,_     ", cColor::YELLOW, true);
	print_text_at_middle(middleY + 4, "    :   '  |--'  ;   |.'  '   : |               |    |`.  ", cColor::YELLOW, true);
	print_text_at_middle(middleY + 5, "     \\   \\ ;     '---'    ;   |.'               `-- -`, ; ", cColor::YELLOW, true);
	print_text_at_middle(middleY + 6, "      '---'               '---'                   '---`'  ", cColor::YELLOW, true);
}

void screen_game_over()
{
	system("cls");
	cout << "Game over" << endl;
}

void draw_coming_soon()
{
	unsigned middleX = get_console_width()/2;
	unsigned middleY = get_console_height()/2;

	
	print_text_at_middle(middleY - 15, "    __   ___   ___ ___  ____  ____    ____       _____  ___    ___   ____                  ", cColor::GREY, true);
	print_text_at_middle(middleY - 14, "   /  ] /   \\ |   |   ||    ||    \\  /    |     / ___/ /   \\  /   \\ |    \\                 ", cColor::GREY, true);
	print_text_at_middle(middleY - 13, "  /  / |     || _   _ | |  | |  _  ||   __|    (   \\_ |     ||     ||  _  |                ", cColor::GREY, true);
	print_text_at_middle(middleY - 12, " /  /  |  O  ||  \\_/  | |  | |  |  ||  |  |     \\__  ||  O  ||  O  ||  |  |                ", cColor::GREY, true);
	print_text_at_middle(middleY - 11, "/   \\_ |     ||   |   | |  | |  |  ||  |_ |     /  \\ ||     ||     ||  |  |     __  __  __ ", cColor::GREY, true);
	print_text_at_middle(middleY - 10, "\\     ||     ||   |   | |  | |  |  ||     |     \\    ||     ||     ||  |  |    |  ||  ||  |", cColor::GREY, true);
	print_text_at_middle(middleY - 9 , " \\____| \\___/ |___|___||____||__|__||_____|      \\___| \\___/  \\___/ |__|__|    |__||__||__|", cColor::GREY, true);

}

void screen_border_decoration(int distance_from_screen_border) 
{
	unsigned screenHeight = get_console_height();
	unsigned screenWidth = get_console_width();

	//space from screen border to corners decoration
	unsigned space1 = distance_from_screen_border;

	//space from corners decoration to sides decoration
	unsigned space2 = 1;

	unsigned middleX = get_console_width()/2;
	unsigned middleY = get_console_height() / 2;

	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED);
	
	goto_xy(space1, space1);
	cout << char(201);

	goto_xy(screenWidth- space1, space1);
	cout << char(187);

	goto_xy(screenWidth- space1,screenHeight- space1);
	cout << char(188);

	goto_xy(space1, screenHeight - space1);
	cout << char(200);

	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED);

	goto_xy(space1 + space2, space1  );
	for (int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
		cout << char(205);
	}

	goto_xy(space1 + space2, screenHeight - space1);
	for (int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
			cout << char(205);
	}

	goto_xy(space1 , space1 + space2);
	for (int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(space1, i);
		cout <<char(186);
	}

	goto_xy(screenWidth - space1 , space1 + space2);
	for (int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(screenWidth - space1, i);
		cout << char(186);
	}




	SetConsoleTextAttribute(hstdout, 15);
}

void screen_ending()
{
	system("CLS");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 18, " _________    ___  ___      ________      ________       ___  __             ___    ___  ________      ___  ___         ", cColor::CYAN, true);
	print_text_at_middle(middleY - 17, "|\\___   ___\\ |\\  \\|\\  \\    |\\   __  \\    |\\   ___  \\    |\\  \\|\\  \\          |\\  \\  /  /||\\   __  \\    |\\  \\|\\  \\        ", cColor::CYAN, true);
	print_text_at_middle(middleY - 16, "\\|___ \\  \\_| \\ \\  \\\\\\  \\   \\ \\  \\|\\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\/  /|_        \\ \\  \\/  / /\\ \\  \\|\\  \\   \\ \\  \\\\\\  \\       ", cColor::CYAN, true);
	print_text_at_middle(middleY - 15, "     \\ \\  \\   \\ \\   __  \\   \\ \\   __  \\   \\ \\  \\\\ \\  \\   \\ \\   ___  \\        \\ \\    / /  \\ \\  \\\\\\  \\   \\ \\  \\\\\\  \\      ", cColor::CYAN, true);
	print_text_at_middle(middleY - 14, "      \\ \\  \\   \\ \\  \\ \\  \\   \\ \\  \\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\\\ \\  \\        \\/  /  /    \\ \\  \\\\\\  \\   \\ \\  \\\\\\  \\     ", cColor::CYAN, true);
	print_text_at_middle(middleY - 13, "       \\ \\__\\   \\ \\__\\ \\__\\   \\ \\__\\ \\__\\   \\ \\__\\\\ \\__\\   \\ \\__\\\\ \\__\\     __/  / /       \\ \\_______\\   \\ \\_______\\     ", cColor::CYAN, true);
	print_text_at_middle(middleY - 12, "        \\|__|    \\|__|\\|__|    \\|__|\\|__|    \\|__| \\|__|    \\|__| \\|__|    |\\___/ /         \\|_______|    \\|_______|     ", cColor::CYAN, true);
	print_text_at_middle(middleY - 11, "                                                                           \\|___|/                                      ", cColor::CYAN, true);

	print_text_at_middle(middleY - 6, " ________  ________      ________          ________    ___           ________       ___    ___  ___      ________       ________      ", cColor::CYAN, true);
	print_text_at_middle(middleY - 5, "|\\  _____\\|\\   __  \\    |\\   __  \\        |\\   __  \\  |\\  \\         |\\   __  \\     |\\  \\  /  /||\\  \\    |\\   ___  \\    |\\   ____\\     ", cColor::CYAN, true);
	print_text_at_middle(middleY - 4, "\\ \\  \\__/ \\ \\  \\|\\  \\   \\ \\  \\|\\  \\       \\ \\  \\|\\  \\ \\ \\  \\        \\ \\  \\|\\  \\    \\ \\  \\/  / /\\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\___|     ", cColor::CYAN, true);
	print_text_at_middle(middleY - 3, " \\ \\   __\\ \\ \\  \\\\\\  \\   \\ \\   _  _\\       \\ \\   ____\\ \\ \\  \\        \\ \\   __  \\    \\ \\    / /  \\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\  ___   ", cColor::CYAN, true);
	print_text_at_middle(middleY - 2, "  \\ \\  \\_|  \\ \\  \\\\\\  \\   \\ \\  \\\\  \\|       \\ \\  \\___|  \\ \\  \\____    \\ \\  \\ \\  \\    \\/  /  /    \\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\|\\  \\  ", cColor::CYAN, true);
	print_text_at_middle(middleY - 1, "   \\ \\__\\    \\ \\_______\\   \\ \\__\\\\ _\\        \\ \\__\\      \\ \\_______\\   \\ \\__\\ \\__\\ __/  / /       \\ \\__\\   \\ \\__\\\\ \\__\\   \\ \\_______\\ ", cColor::CYAN, true);
	print_text_at_middle(middleY , "    \\|__|     \\|_______|    \\|__|\\|__|        \\|__|       \\|_______|    \\|__|\\|__||\\___/ /         \\|__|    \\|__| \\|__|    \\|_______| ", cColor::CYAN, true);
	print_text_at_middle(middleY + 1, "                                                                                  \\|___|/                                             ", cColor::CYAN, true);

	Sleep(2 * 1000);

	print_text_at_middle(middleY + 15, "This game was made by: GROUP 9 - 18CLC1", cColor::GREEN, true);
	
	Sleep(1.5 * 1000);

	print_text_at_middle(middleY + 18, "18127259 - Kieu Cong Hau", cColor::GREY, true);
	Sleep(1 * 1000);
	print_text_at_middle(middleY + 20, "181272118 - Mai Dang Khanh", cColor::GREY, true);
	Sleep(1 * 1000);
	print_text_at_middle(middleY + 22, "181272014 - Huynh Nhat Nam", cColor::GREY, true);
	Sleep(1 * 1000);


	print_text_at_middle(middleY + 6, "Press Any Key To Exit", cColor::WHITE, true);
}



