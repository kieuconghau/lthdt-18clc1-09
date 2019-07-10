#include "cScreen.h"

void cScreen::screen_account()
{
	system("cls");

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " ____    ___    ____  ___           __  ____    ___    _____  _____ ____  ____    ____       ____   ____  ___ ___    ___ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, "|    \\  /   \\  /    ||   \\         /  ]|    \\  /   \\  / ___/ / ___/|    ||    \\  /    |     /    | /    ||   |   |  /  _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "|  D  )|     ||  o  ||    \\       /  / |  D  )|     |(   \\_ (   \\_  |  | |  _  ||   __|    |   __||  o  || _   _ | /  [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, "|    / |  O  ||     ||  D  |     /  /  |    / |  O  | \\__  | \\__  | |  | |  |  ||  |  |    |  |  ||     ||  \\_/  ||    _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, "|    \\ |     ||  _  ||     |    /   \\_ |    \\ |     | /  \\ | /  \\ | |  | |  |  ||  |_ |    |  |_ ||  _  ||   |   ||   [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, "|  .  \\|     ||  |  ||     |    \\     ||  .  \\|     | \\    | \\    | |  | |  |  ||     |    |     ||  |  ||   |   ||     |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "|__|\\_| \\___/ |__|__||_____|     \\____||__|\\_| \\___/   \\___|  \\___||____||__|__||___,_|    |___,_||__|__||___|___||_____|", ecColor::CYAN, true);

	print_text_at_middle(middleY - 7, "========= Group 09 * 18CLC1 =========", ecColor::BLUE, true);

	cTextBox signUp(cTextBox::ecScreenType::SIGN_UP, middleX, middleY - 2, 25, "SIGN UP", ecColor::WHITE, ecColor::WHITE);
	cTextBox signIn(cTextBox::ecScreenType::SIGN_IN, middleX, middleY + 2, 25, "SIGN IN", ecColor::WHITE, ecColor::WHITE);
	cTextBox guest(cTextBox::ecScreenType::MENU, middleX, middleY + 6, 25, "GUEST", ecColor::WHITE, ecColor::WHITE);
	cTextBox about(cTextBox::ecScreenType::ABOUT, middleX, middleY + 10, 25, "ABOUT", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { signUp, signIn, guest, about };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::SIGN_UP)
		screen_sign_up();
	else if (choice == cTextBox::ecScreenType::SIGN_IN)
		screen_sign_in();
	else if (choice == cTextBox::ecScreenType::MENU)
		screen_menu();
	else if (choice == cTextBox::ecScreenType::ABOUT)
		screen_about();
	else
		throw;
}

void cScreen::screen_sign_up()
{
	system("cls");

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "  _____ ____   ____  ____       __ __  ____  ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, " / ___/|    | /    ||    \\     |  |  ||    \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "(   \\_  |  | |   __||  _  |    |  |  ||  o  )", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, " \\__  | |  | |  |  ||  |  |    |  |  ||   _/", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, " /  \\ | |  | |  |_ ||  |  |    |  :  ||  |   ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, " \\    | |  | |     ||  |  |    |     ||  |   ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "  \\___||____||___,_||__|__|     \\__,_||__|   ", ecColor::CYAN, true);

	print_text_at_middle(middleY - 5, "< Coming soon >", ecColor::WHITE, true);

	cTextBox back(cTextBox::ecScreenType::ACCOUNT, middleX, middleY + 2, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { back };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::ACCOUNT)
		screen_account();
	else
		throw;
}

void cScreen::screen_sign_in()
{
	system("cls");

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "  _____ ____   ____  ____       ____  ____  ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, " / ___/|    | /    ||    \\     |    ||    \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "(   \\_  |  | |   __||  _  |     |  | |  _  |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, " \\__  | |  | |  |  ||  |  |     |  | |  |  |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, " /  \\ | |  | |  |_ ||  |  |     |  | |  |  |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, " \\    | |  | |     ||  |  |     |  | |  |  |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "  \\___||____||___,_||__|__|    |____||__|__|", ecColor::CYAN, true);

	print_text_at_middle(middleY - 5, "< Coming soon >", ecColor::WHITE, true);

	cTextBox back(cTextBox::ecScreenType::ACCOUNT, middleX, middleY + 2, 25, "Back", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { back };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::ACCOUNT)
		screen_account();
	else
		throw;
}

void cScreen::screen_about()
{
	system("cls");

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " ____    ___    ____  ___           __  ____    ___    _____  _____ ____  ____    ____       ____   ____  ___ ___    ___ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, "|    \\  /   \\  /    ||   \\         /  ]|    \\  /   \\  / ___/ / ___/|    ||    \\  /    |     /    | /    ||   |   |  /  _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "|  D  )|     ||  o  ||    \\       /  / |  D  )|     |(   \\_ (   \\_  |  | |  _  ||   __|    |   __||  o  || _   _ | /  [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, "|    / |  O  ||     ||  D  |     /  /  |    / |  O  | \\__  | \\__  | |  | |  |  ||  |  |    |  |  ||     ||  \\_/  ||    _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, "|    \\ |     ||  _  ||     |    /   \\_ |    \\ |     | /  \\ | /  \\ | |  | |  |  ||  |_ |    |  |_ ||  _  ||   |   ||   [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, "|  .  \\|     ||  |  ||     |    \\     ||  .  \\|     | \\    | \\    | |  | |  |  ||     |    |     ||  |  ||   |   ||     |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "|__|\\_| \\___/ |__|__||_____|     \\____||__|\\_| \\___/   \\___|  \\___||____||__|__||___,_|    |___,_||__|__||___|___||_____|", ecColor::CYAN, true);

	print_text_at_middle(middleY - 7, "========= Group 09 * 18CLC1 =========", ecColor::BLUE, true);

	cTextBox back(cTextBox::ecScreenType::ACCOUNT, middleX, middleY + 10, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { back };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::ACCOUNT)
		screen_account();
	else
		throw;
}

void cScreen::screen_menu()
{
	system("cls");

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " ____    ___    ____  ___           __  ____    ___    _____  _____ ____  ____    ____       ____   ____  ___ ___    ___ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, "|    \\  /   \\  /    ||   \\         /  ]|    \\  /   \\  / ___/ / ___/|    ||    \\  /    |     /    | /    ||   |   |  /  _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "|  D  )|     ||  o  ||    \\       /  / |  D  )|     |(   \\_ (   \\_  |  | |  _  ||   __|    |   __||  o  || _   _ | /  [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, "|    / |  O  ||     ||  D  |     /  /  |    / |  O  | \\__  | \\__  | |  | |  |  ||  |  |    |  |  ||     ||  \\_/  ||    _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, "|    \\ |     ||  _  ||     |    /   \\_ |    \\ |     | /  \\ | /  \\ | |  | |  |  ||  |_ |    |  |_ ||  _  ||   |   ||   [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, "|  .  \\|     ||  |  ||     |    \\     ||  .  \\|     | \\    | \\    | |  | |  |  ||     |    |     ||  |  ||   |   ||     |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "|__|\\_| \\___/ |__|__||_____|     \\____||__|\\_| \\___/   \\___|  \\___||____||__|__||___,_|    |___,_||__|__||___|___||_____|", ecColor::CYAN, true);

	print_text_at_middle(middleY - 7, "========= Group 09 * 18CLC1 =========", ecColor::BLUE, true);

	cTextBox newGame(cTextBox::ecScreenType::GAME, middleX, middleY - 2, 25, "NEW GAME", ecColor::WHITE, ecColor::WHITE);
	cTextBox loadGame(cTextBox::ecScreenType::LOAD_GAME, middleX, middleY + 2, 25, "LOAD GAME", ecColor::WHITE, ecColor::WHITE);
	cTextBox setting(cTextBox::ecScreenType::SETTING, middleX, middleY + 6, 25, "SETTING", ecColor::WHITE, ecColor::WHITE);
	cTextBox back(cTextBox::ecScreenType::ACCOUNT, middleX, middleY + 10, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { newGame , loadGame, setting, back };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::GAME)
		screen_game();
	else if (choice == cTextBox::ecScreenType::LOAD_GAME)
		screen_load_game();
	else if (choice == cTextBox::ecScreenType::SETTING)
		screen_setting();
	else if (choice == cTextBox::ecScreenType::ACCOUNT)
		screen_account();
	else
		throw;

}

void cScreen::screen_game()
{
	system("cls");

	/*
		Start game
	*/
}

void cScreen::screen_load_game()
{
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " _       ___    ____  ___         ____   ____  ___ ___    ___ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 14, "| |     /   \\  /    ||   \\       /    | /    ||   |   |  /  _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 13, "| |    |     ||  o  ||    \\     |   __||  o  || _   _ | /  [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 12, "| |___ |  O  ||     ||  D  |    |  |  ||     ||  \\_/  ||    _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 11, "|     ||     ||  _  ||     |    |  |_ ||  _  ||   |   ||   [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 10, "|     ||     ||  |  ||     |    |     ||  |  ||   |   ||     |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 9, "|_____| \\___/ |__|__||_____|    |___,_||__|__||___|___||_____|", ecColor::BLUE, true);

	cTextBox loadGame(cTextBox::ecScreenType::LOAD_GAME, middleX, middleY - 2, 25, "LOAD GAME", ecColor::WHITE, ecColor::WHITE);
	cTextBox back(cTextBox::ecScreenType::MENU, middleX, middleY + 2, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { loadGame, back };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::LOAD_GAME)
	{
		/*
			Load game
		*/
	}
	else if (choice == cTextBox::ecScreenType::MENU)
		screen_menu();
	else
		throw;
}

void cScreen::screen_save_game()
{
	system("cls");

	/*
		Save game
	*/
}

void cScreen::screen_setting()
{
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	cTextBox back(cTextBox::ecScreenType::MENU, middleX, middleY + 2, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { back };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::MENU)
		screen_menu();
	else
		throw;
}

void cScreen::screen_continue()
{
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "    __   ___   ____   ______  ____  ____   __ __    ___      _____ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 14, "   /  ] /   \\ |    \\ |      ||    ||    \\ |  |  |  /  _]    /     |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 13, "  /  / |     ||  _  ||      | |  | |  _  ||  |  | /  [_     |  Y  |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 12, " /  /  |  O  ||  |  ||_|  |_| |  | |  |  ||  |  ||    _]    |__|  |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 11, "/   \\_ |     ||  |  |  |  |   |  | |  |  ||  :  ||   [_        |__|", ecColor::BLUE, true);
	print_text_at_middle(middleY - 10, "\\     ||     ||  |  |  |  |   |  | |  |  ||     ||     |        __ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 9, " \\____| \\___/ |__|__|  |__|  |____||__|__| \\____||_____|       |__|", ecColor::BLUE, true);

	cTextBox yes(cTextBox::ecScreenType::GAME, middleX - 18, middleY + 2, 25, "Yes", ecColor::WHITE, ecColor::WHITE);
	cTextBox no(cTextBox::ecScreenType::ENDING, middleX + 18, middleY + 2, 25, "No", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menuLoadGame = { yes,no };

	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menuLoadGame, ecColor::RED);

	if (choice == cTextBox::ecScreenType::GAME)
	{
		/*
			Play game
		*/
	}
	else if (choice == cTextBox::ecScreenType::ENDING)
		screen_ending();
	else
		throw;
}

void cScreen::screen_win()
{
	system("cls");

	screen_border_decoration(17);
	screen_border_decoration(20);
	screen_border_decoration(23);
	screen_border_decoration(29);
	screen_border_decoration(32);
	screen_border_decoration(35);

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 8, "                                                   ,---,  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY - 7, "                                   ,--.         ,`--.' |  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY - 6, "           .---.    ,---,        ,--.'|         |   :  :  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY - 5, "          /. ./| ,`--.' |    ,--,:  : |         '   '  ;  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY - 4, "      .--'.  ' ; |   :  : ,`--.'`|  ' :         |   |  |  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY - 3, "     /__./ \\ : | :   |  ' |   :  :  | |         '   :  ;  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY - 2, " .--'.  '   \\' . |   :  | :   |   \\ | :         |   |  '  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY - 1, "/___/ \\ |    ' ' '   '  ; |   : '  '; |         '   :  |  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY, ";   \\  \\;      : |   |  | '   ' ;.    ;         ;   |  ;  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 1, " \\   ;  `      | '   :  ; |   | | \\   |         `---'. |  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 2, "  .   \\    .\\  ; |   |  ' '   : |  ; .'          `--..`;  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 3, "   \\   \\   ' \\ | '   :  | |   | '`--'           .--,_     ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 4, "    :   '  |--'  ;   |.'  '   : |               |    |`.  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 5, "     \\   \\ ;     '---'    ;   |.'               `-- -`, ; ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 6, "      '---'               '---'                   '---`'  ", ecColor::YELLOW, true);

	cTextBox ok(cTextBox::ecScreenType::CONTINUE, middleX, middleY + 10, 35, "Winner Winner Chicken Dinner", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { ok };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::CONTINUE)
		screen_continue();
	else
		throw;
}

void cScreen::screen_game_over()
{
	system("cls");

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "  ____   ____  ___ ___    ___       ___   __ __    ___  ____", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, " /    | /    ||   |   |  /  _]     /   \\ |  |  |  /  _]|    \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "|   __||  o  || _   _ | /  [_     |     ||  |  | /  [_ |  D  ) ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, "|  |  ||     ||  \\_/  ||    _]    |  O  ||  |  ||    _]|    / ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, "|  |_ ||  _  ||   |   ||   [_     |     ||  :  ||   [_ |    \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, "|     ||  |  ||   |   ||     |    |     | \\   / |     ||  .  \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "|___,_||__|__||___|___||_____|     \\___/   \\_/  |_____||__|\\_| ", ecColor::CYAN, true);

	cTextBox ok(cTextBox::ecScreenType::CONTINUE, middleX, middleY - 10, 25, "OK FINE", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { ok };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::CONTINUE)
		screen_continue();
	else
		throw;
}

void cScreen::draw_coming_soon()
{
	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "    __   ___   ___ ___  ____  ____    ____       _____  ___    ___   ____                  ", ecColor::GREY, true);
	print_text_at_middle(middleY - 14, "   /  ] /   \\ |   |   ||    ||    \\  /    |     / ___/ /   \\  /   \\ |    \\                 ", ecColor::GREY, true);
	print_text_at_middle(middleY - 13, "  /  / |     || _   _ | |  | |  _  ||   __|    (   \\_ |     ||     ||  _  |                ", ecColor::GREY, true);
	print_text_at_middle(middleY - 12, " /  /  |  O  ||  \\_/  | |  | |  |  ||  |  |     \\__  ||  O  ||  O  ||  |  |                ", ecColor::GREY, true);
	print_text_at_middle(middleY - 11, "/   \\_ |     ||   |   | |  | |  |  ||  |_ |     /  \\ ||     ||     ||  |  |     __  __  __ ", ecColor::GREY, true);
	print_text_at_middle(middleY - 10, "\\     ||     ||   |   | |  | |  |  ||     |     \\    ||     ||     ||  |  |    |  ||  ||  |", ecColor::GREY, true);
	print_text_at_middle(middleY - 9, " \\____| \\___/ |___|___||____||__|__||_____|      \\___| \\___/  \\___/ |__|__|    |__||__||__|", ecColor::GREY, true);
}

void cScreen::screen_border_decoration(int distanceFromScreenBorder)
{
	unsigned screenHeight = get_console_height();
	unsigned screenWidth = get_console_width();

	//space from screen border to corners decoration
	unsigned space1 = distanceFromScreenBorder;

	//space from corners decoration to sides decoration
	unsigned space2 = 1;
	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED);

	goto_xy(space1, space1);
	cout << char(201);

	goto_xy(screenWidth - space1, space1);
	cout << char(187);

	goto_xy(screenWidth - space1, screenHeight - space1);
	cout << char(188);

	goto_xy(space1, screenHeight - space1);
	cout << char(200);

	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED);

	goto_xy(space1 + space2, space1);
	for (int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
		cout << char(205);
	}

	goto_xy(space1 + space2, screenHeight - space1);
	for (int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
		cout << char(205);
	}

	goto_xy(space1, space1 + space2);
	for (int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(space1, i);
		cout << char(186);
	}

	goto_xy(screenWidth - space1, space1 + space2);
	for (int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(screenWidth - space1, i);
		cout << char(186);
	}

	SetConsoleTextAttribute(hstdout, 15);
}

void cScreen::screen_ending()
{
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 18, " _________    ___  ___      ________      ________       ___  __             ___    ___  ________      ___  ___         ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 17, "|\\___   ___\\ |\\  \\|\\  \\    |\\   __  \\    |\\   ___  \\    |\\  \\|\\  \\          |\\  \\  /  /||\\   __  \\    |\\  \\|\\  \\        ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 16, "\\|___ \\  \\_| \\ \\  \\\\\\  \\   \\ \\  \\|\\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\/  /|_        \\ \\  \\/  / /\\ \\  \\|\\  \\   \\ \\  \\\\\\  \\       ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 15, "     \\ \\  \\   \\ \\   __  \\   \\ \\   __  \\   \\ \\  \\\\ \\  \\   \\ \\   ___  \\        \\ \\    / /  \\ \\  \\\\\\  \\   \\ \\  \\\\\\  \\      ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, "      \\ \\  \\   \\ \\  \\ \\  \\   \\ \\  \\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\\\ \\  \\        \\/  /  /    \\ \\  \\\\\\  \\   \\ \\  \\\\\\  \\     ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "       \\ \\__\\   \\ \\__\\ \\__\\   \\ \\__\\ \\__\\   \\ \\__\\\\ \\__\\   \\ \\__\\\\ \\__\\     __/  / /       \\ \\_______\\   \\ \\_______\\     ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, "        \\|__|    \\|__|\\|__|    \\|__|\\|__|    \\|__| \\|__|    \\|__| \\|__|    |\\___/ /         \\|_______|    \\|_______|     ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, "                                                                           \\|___|/                                      ", ecColor::CYAN, true);

	print_text_at_middle(middleY - 6, " ________  ________      ________          ________    ___           ________       ___    ___  ___      ________       ________      ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 5, "|\\  _____\\|\\   __  \\    |\\   __  \\        |\\   __  \\  |\\  \\         |\\   __  \\     |\\  \\  /  /||\\  \\    |\\   ___  \\    |\\   ____\\     ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 4, "\\ \\  \\__/ \\ \\  \\|\\  \\   \\ \\  \\|\\  \\       \\ \\  \\|\\  \\ \\ \\  \\        \\ \\  \\|\\  \\    \\ \\  \\/  / /\\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\___|     ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 3, " \\ \\   __\\ \\ \\  \\\\\\  \\   \\ \\   _  _\\       \\ \\   ____\\ \\ \\  \\        \\ \\   __  \\    \\ \\    / /  \\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\  ___   ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 2, "  \\ \\  \\_|  \\ \\  \\\\\\  \\   \\ \\  \\\\  \\|       \\ \\  \\___|  \\ \\  \\____    \\ \\  \\ \\  \\    \\/  /  /    \\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\|\\  \\  ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 1, "   \\ \\__\\    \\ \\_______\\   \\ \\__\\\\ _\\        \\ \\__\\      \\ \\_______\\   \\ \\__\\ \\__\\ __/  / /       \\ \\__\\   \\ \\__\\\\ \\__\\   \\ \\_______\\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY, "    \\|__|     \\|_______|    \\|__|\\|__|        \\|__|       \\|_______|    \\|__|\\|__||\\___/ /         \\|__|    \\|__| \\|__|    \\|_______| ", ecColor::CYAN, true);
	print_text_at_middle(middleY + 1, "                                                                                  \\|___|/                                             ", ecColor::CYAN, true);

	Sleep(2000);
	print_text_at_middle(middleY + 14, "This game was made by: GROUP 9 - 18CLC1", ecColor::GREEN, true);
	Sleep(500);

	print_text_at_middle(middleY + 17, "18127259 - Kieu Cong Hau", ecColor::GREY, true);
	Sleep(500);
	print_text_at_middle(middleY + 19, "18127118 - Mai Dang Khanh", ecColor::GREY, true);
	Sleep(500);
	print_text_at_middle(middleY + 21, "18127014 - Huynh Nhat Nam", ecColor::GREY, true);
	Sleep(500);

	goto_xy(middleX - 15, middleY + 5);
	system("pause");
}
