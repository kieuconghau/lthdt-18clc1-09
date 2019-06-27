#include "Screen.h"

void screen_account()
{
	system("cls");

	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " ____    ___    ____  ___           __  ____    ___    _____  _____ ____  ____    ____       ____   ____  ___ ___    ___ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, "|    \\  /   \\  /    ||   \\         /  ]|    \\  /   \\  / ___/ / ___/|    ||    \\  /    |     /    | /    ||   |   |  /  _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "|  D  )|     ||  o  ||    \\       /  / |  D  )|     |(   \\_ (   \\_  |  | |  _  ||   __|    |   __||  o  || _   _ | /  [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, "|    / |  O  ||     ||  D  |     /  /  |    / |  O  | \\__  | \\__  | |  | |  |  ||  |  |    |  |  ||     ||  \\_/  ||    _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, "|    \\ |     ||  _  ||     |    /   \\_ |    \\ |     | /  \\ | /  \\ | |  | |  |  ||  |_ |    |  |_ ||  _  ||   |   ||   [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, "|  .  \\|     ||  |  ||     |    \\     ||  .  \\|     | \\    | \\    | |  | |  |  ||     |    |     ||  |  ||   |   ||     |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9,  "|__|\\_| \\___/ |__|__||_____|     \\____||__|\\_| \\___/   \\___|  \\___||____||__|__||___,_|    |___,_||__|__||___|___||_____|", ecColor::CYAN, true);

	print_text_at_middle(middleY - 7, "========= Group 09 * 18CLC1 =========", ecColor::BLUE, true);

	cTextBox signUp(cScreen::SIGN_UP, middleX, middleY - 2, 25, "SIGN UP", ecColor::WHITE, ecColor::WHITE);
	cTextBox signIn(cScreen::SIGN_IN, middleX, middleY + 2, 25, "SIGN IN", ecColor::WHITE, ecColor::WHITE);
	cTextBox guest(cScreen::MENU, middleX, middleY + 6, 25, "GUEST", ecColor::WHITE, ecColor::WHITE);
	cTextBox about(cScreen::ABOUT, middleX, middleY + 10, 25, "ABOUT", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menuAccount = { signUp, signIn, guest, about };
	cScreen choice = scrolling_menu(menuAccount, ecColor::RED);

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
  
	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "  _____ ____   ____  ____       __ __  ____  ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, " / ___/|    | /    ||    \\     |  |  ||    \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "(   \\_  |  | |   __||  _  |    |  |  ||  o  )", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, " \\__  | |  | |  |  ||  |  |    |  |  ||   _/", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, " /  \\ | |  | |  |_ ||  |  |    |  :  ||  |   ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, " \\    | |  | |     ||  |  |    |     ||  |   ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "  \\___||____||___,_||__|__|     \\__,_||__|   ", ecColor::CYAN, true);

	print_text_at_middle(middleY - 5, "< Coming soon >", ecColor::WHITE, true);

	cTextBox back(cScreen::ACCOUNT, middleX, middleY, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menuAbout = { back };
	cScreen choice = scrolling_menu(menuAbout, ecColor::RED);

	if (choice == cScreen::ACCOUNT)
		screen_account();
	else throw;
}

void screen_sign_in()
{
	system("cls");

	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "  _____ ____   ____  ____       ____  ____  ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, " / ___/|    | /    ||    \\     |    ||    \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "(   \\_  |  | |   __||  _  |     |  | |  _  |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, " \\__  | |  | |  |  ||  |  |     |  | |  |  |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, " /  \\ | |  | |  |_ ||  |  |     |  | |  |  |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, " \\    | |  | |     ||  |  |     |  | |  |  |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "  \\___||____||___,_||__|__|    |____||__|__|", ecColor::CYAN, true);

	print_text_at_middle(middleY - 5, "< Coming soon >", ecColor::WHITE, true);

	cTextBox back(cScreen::ACCOUNT, middleX, middleY, 25, "Back", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menuAccount = { back };
	cScreen choice = scrolling_menu(menuAccount, ecColor::RED);

	if (choice == cScreen::ACCOUNT)
		screen_account();
	else
		throw;
}

void screen_about()
{
	system("cls");

	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " ____    ___    ____  ___           __  ____    ___    _____  _____ ____  ____    ____       ____   ____  ___ ___    ___ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, "|    \\  /   \\  /    ||   \\         /  ]|    \\  /   \\  / ___/ / ___/|    ||    \\  /    |     /    | /    ||   |   |  /  _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "|  D  )|     ||  o  ||    \\       /  / |  D  )|     |(   \\_ (   \\_  |  | |  _  ||   __|    |   __||  o  || _   _ | /  [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, "|    / |  O  ||     ||  D  |     /  /  |    / |  O  | \\__  | \\__  | |  | |  |  ||  |  |    |  |  ||     ||  \\_/  ||    _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, "|    \\ |     ||  _  ||     |    /   \\_ |    \\ |     | /  \\ | /  \\ | |  | |  |  ||  |_ |    |  |_ ||  _  ||   |   ||   [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, "|  .  \\|     ||  |  ||     |    \\     ||  .  \\|     | \\    | \\    | |  | |  |  ||     |    |     ||  |  ||   |   ||     |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "|__|\\_| \\___/ |__|__||_____|     \\____||__|\\_| \\___/   \\___|  \\___||____||__|__||___,_|    |___,_||__|__||___|___||_____|", ecColor::CYAN, true);

	print_text_at_middle(middleY - 7, "========= Group 09 * 18CLC1 =========", ecColor::BLUE, true);

	cTextBox back(cScreen::ACCOUNT, middleX, middleY + 10, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menuAbout = { back };
	cScreen choice = scrolling_menu(menuAbout, ecColor::RED);

	if (choice == cScreen::ACCOUNT)
		screen_account();
	else throw;
}

void screen_menu()
{
	system("cls");

	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " ____    ___    ____  ___           __  ____    ___    _____  _____ ____  ____    ____       ____   ____  ___ ___    ___ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, "|    \\  /   \\  /    ||   \\         /  ]|    \\  /   \\  / ___/ / ___/|    ||    \\  /    |     /    | /    ||   |   |  /  _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "|  D  )|     ||  o  ||    \\       /  / |  D  )|     |(   \\_ (   \\_  |  | |  _  ||   __|    |   __||  o  || _   _ | /  [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, "|    / |  O  ||     ||  D  |     /  /  |    / |  O  | \\__  | \\__  | |  | |  |  ||  |  |    |  |  ||     ||  \\_/  ||    _]", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, "|    \\ |     ||  _  ||     |    /   \\_ |    \\ |     | /  \\ | /  \\ | |  | |  |  ||  |_ |    |  |_ ||  _  ||   |   ||   [_ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, "|  .  \\|     ||  |  ||     |    \\     ||  .  \\|     | \\    | \\    | |  | |  |  ||     |    |     ||  |  ||   |   ||     |", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "|__|\\_| \\___/ |__|__||_____|     \\____||__|\\_| \\___/   \\___|  \\___||____||__|__||___,_|    |___,_||__|__||___|___||_____|", ecColor::CYAN, true);

	print_text_at_middle(middleY - 7, "========= Group 09 * 18CLC1 =========", ecColor::BLUE, true);

	cTextBox newGame(cScreen::GAME, middleX, middleY - 2, 25, "NEW GAME", ecColor::WHITE, ecColor::WHITE);
	cTextBox loadGame(cScreen::LOAD_GAME, middleX, middleY + 2, 25, "LOAD GAME", ecColor::WHITE, ecColor::WHITE);
	cTextBox setting(cScreen::SETTING, middleX, middleY + 6, 25, "SETTING", ecColor::WHITE, ecColor::WHITE);
	cTextBox back(cScreen::ACCOUNT, middleX, middleY + 10, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { newGame , loadGame, setting, back };
	cScreen choice = scrolling_menu(menu, ecColor::RED);

	if (choice == cScreen::GAME)
		screen_game();
	else if (choice == cScreen::LOAD_GAME)
		screen_load_game();
	else if (choice == cScreen::SETTING)
		screen_setting();
	else if (choice == cScreen::ACCOUNT)
		screen_account();
	else
		throw;

}

void screen_game()
{
	system("cls");

	cGame game;
	game.start();
}

void screen_load_game()
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

	cTextBox loadGame(cScreen::LOAD_GAME, middleX, middleY - 2, 25, "LOAD GAME", ecColor::WHITE, ecColor::WHITE);
	cTextBox back(cScreen::MENU, middleX, middleY + 2, 25,"BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menuLoadGame = { loadGame,back };

	cScreen choice = scrolling_menu(menuLoadGame, ecColor::RED);

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

	cTextBox back(cScreen::MENU, middleX, middleY + 2, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menuLoadGame = { back };

	cScreen choice = scrolling_menu(menuLoadGame, ecColor::RED);

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

	print_text_at_middle(middleY - 15, "    __   ___   ____   ______  ____  ____   __ __    ___      _____ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 14, "   /  ] /   \\ |    \\ |      ||    ||    \\ |  |  |  /  _]    /     |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 13, "  /  / |     ||  _  ||      | |  | |  _  ||  |  | /  [_     |  Y  |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 12, " /  /  |  O  ||  |  ||_|  |_| |  | |  |  ||  |  ||    _]    |__|  |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 11, "/   \\_ |     ||  |  |  |  |   |  | |  |  ||  :  ||   [_        |__|", ecColor::BLUE, true);
	print_text_at_middle(middleY - 10, "\\     ||     ||  |  |  |  |   |  | |  |  ||     ||     |        __ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 9, " \\____| \\___/ |__|__|  |__|  |____||__|__| \\____||_____|       |__|", ecColor::BLUE, true);

	cTextBox yes(cScreen::GAME, middleX, middleY - 2, 25, "Yes", ecColor::WHITE, ecColor::WHITE);
	cTextBox no(cScreen::ENDING, middleX, middleY + 2, 25, "No", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menuLoadGame = { yes,no };

	cScreen choice = scrolling_menu(menuLoadGame, ecColor::RED);

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
	print_text_at_middle(middleY ,    ";   \\  \\;      : |   |  | '   ' ;.    ;         ;   |  ;  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 1, " \\   ;  `      | '   :  ; |   | | \\   |         `---'. |  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 2, "  .   \\    .\\  ; |   |  ' '   : |  ; .'          `--..`;  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 3, "   \\   \\   ' \\ | '   :  | |   | '`--'           .--,_     ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 4, "    :   '  |--'  ;   |.'  '   : |               |    |`.  ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 5, "     \\   \\ ;     '---'    ;   |.'               `-- -`, ; ", ecColor::YELLOW, true);
	print_text_at_middle(middleY + 6, "      '---'               '---'                   '---`'  ", ecColor::YELLOW, true);
}

void screen_game_over()
{
	system("cls");

	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "  ____   ____  ___ ___    ___       ___   __ __    ___  ____", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, " /    | /    ||   |   |  /  _]     /   \\ |  |  |  /  _]|    \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "|   __||  o  || _   _ | /  [_     |     ||  |  | /  [_ |  D  ) ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, "|  |  ||     ||  \\_/  ||    _]    |  O  ||  |  ||    _]|    / ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, "|  |_ ||  _  ||   |   ||   [_     |     ||  :  ||   [_ |    \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, "|     ||  |  ||   |   ||     |    |     | \\   / |     ||  .  \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "|___,_||__|__||___|___||_____|     \\___/   \\_/  |_____||__|\\_| ", ecColor::CYAN, true);

	cTextBox _continue(cScreen::CONTINUE, middleX, middleY - 10, 25, "OK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menuGameOver = { _continue};
	cScreen choice = scrolling_menu(menuGameOver, ecColor::RED);

	if (choice == cScreen::CONTINUE)
		screen_continue();
	else
		throw;
}

void draw_coming_soon()
{
	unsigned middleX = get_console_width()/2;
	unsigned middleY = get_console_height()/2;
<<<<<<< HEAD

=======
	
>>>>>>> 45747e6f7f799f3e2cd474550de8ca916ad5310d
	print_text_at_middle(middleY - 15, "    __   ___   ___ ___  ____  ____    ____       _____  ___    ___   ____                  ", ecColor::GREY, true);
	print_text_at_middle(middleY - 14, "   /  ] /   \\ |   |   ||    ||    \\  /    |     / ___/ /   \\  /   \\ |    \\                 ", ecColor::GREY, true);
	print_text_at_middle(middleY - 13, "  /  / |     || _   _ | |  | |  _  ||   __|    (   \\_ |     ||     ||  _  |                ", ecColor::GREY, true);
	print_text_at_middle(middleY - 12, " /  /  |  O  ||  \\_/  | |  | |  |  ||  |  |     \\__  ||  O  ||  O  ||  |  |                ", ecColor::GREY, true);
	print_text_at_middle(middleY - 11, "/   \\_ |     ||   |   | |  | |  |  ||  |_ |     /  \\ ||     ||     ||  |  |     __  __  __ ", ecColor::GREY, true);
	print_text_at_middle(middleY - 10, "\\     ||     ||   |   | |  | |  |  ||     |     \\    ||     ||     ||  |  |    |  ||  ||  |", ecColor::GREY, true);
	print_text_at_middle(middleY - 9 , " \\____| \\___/ |___|___||____||__|__||_____|      \\___| \\___/  \\___/ |__|__|    |__||__||__|", ecColor::GREY, true);
}

void screen_border_decoration(int distanceFromScreenBorder) 
{
	unsigned screenHeight = get_console_height();
	unsigned screenWidth = get_console_width();

	//space from screen border to corners decoration
	unsigned space1 = distanceFromScreenBorder;

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
	for (unsigned int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
		cout << char(205);
	}

	goto_xy(space1 + space2, screenHeight - space1);
	for (unsigned int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
			cout << char(205);
	}

	goto_xy(space1 , space1 + space2);
	for (unsigned int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(space1, i);
		cout <<char(186);
	}

	goto_xy(screenWidth - space1 , space1 + space2);
	for (unsigned int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(screenWidth - space1, i);
		cout << char(186);
	}
  
	SetConsoleTextAttribute(hstdout, 15);
}

void screen_ending()
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
	print_text_at_middle(middleY , "    \\|__|     \\|_______|    \\|__|\\|__|        \\|__|       \\|_______|    \\|__|\\|__||\\___/ /         \\|__|    \\|__| \\|__|    \\|_______| ", ecColor::CYAN, true);
	print_text_at_middle(middleY + 1, "                                                                                  \\|___|/                                             ", ecColor::CYAN, true);

	Sleep(2000);
<<<<<<< HEAD
	print_text_at_middle(middleY + 6, "This game was made by: GROUP 9 - 18CLC1", ecColor::GREEN, true);
	Sleep(1500);

	print_text_at_middle(middleY + 8, "18127259 - Kieu Cong Hau", ecColor::GREY, true);
	Sleep(1000);
	print_text_at_middle(middleY + 10, "18127118 - Mai Dang Khanh", ecColor::GREY, true);
	Sleep(1000);
	print_text_at_middle(middleY + 12, "18127014 - Huynh Nhat Nam", ecColor::GREY, true);
	Sleep(1000);

	print_text_at_middle(middleY + 14, "Press Any Key To Exit", ecColor::WHITE, true);
}



=======
	print_text_at_middle(middleY + 14, "This game was made by: GROUP 9 - 18CLC1", ecColor::GREEN, true);
	Sleep(500);

	print_text_at_middle(middleY + 17, "18127259 - Kieu Cong Hau", ecColor::GREY, true);
	Sleep(500);
	print_text_at_middle(middleY + 19, "18127118 - Mai Dang Khanh", ecColor::GREY, true);
	Sleep(500);
	print_text_at_middle(middleY + 21, "18127014 - Huynh Nhat Nam", ecColor::GREY, true);
	Sleep(500);

	goto_xy(middleX-15, middleY + 5);
	system("pause");
}
>>>>>>> 45747e6f7f799f3e2cd474550de8ca916ad5310d
