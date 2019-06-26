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
	print_text_at_middle(middleY - 9,  "|__|\\_| \\___/ |__|__||_____|     \\____||__|\\_| \\___/   \\___|  \\___||____||__|__||___,_|    |___,_||__|__||___|___||_____|", cColor::CYAN, true);

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

	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;

	cTextBox back(cScreen::ACCOUNT, middleX, middleY + 10, 25, "BACK", cColor::WHITE, cColor::WHITE);

	vector<cTextBox> menuAbout = { back };
	cScreen choice = scrolling_menu(menuAbout, cColor::RED);

	if (choice == cScreen::ACCOUNT)
		screen_account();
	else throw;
	cout << "Sign up" << endl;
}

void screen_sign_in()
{
	system("cls");
	cout << "Sign in" << endl;
}

void screen_about()
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

	cTextBox back(cScreen::ACCOUNT, middleX, middleY + 10, 25, "BACK", cColor::WHITE, cColor::WHITE);

	vector<cTextBox> menuAbout = { back };
	cScreen choice = scrolling_menu(menuAbout, cColor::RED);

	if (choice == cScreen::ACCOUNT)
		screen_account();
	else throw;
}

void screen_menu()
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

	cTextBox newGame(cScreen::GAME, middleX, middleY - 2, 25, "NEW GAME", cColor::WHITE, cColor::WHITE);
	cTextBox loadGame(cScreen::LOAD_GAME, middleX, middleY + 2, 25, "LOAD GAME", cColor::WHITE, cColor::WHITE);
	cTextBox setting(cScreen::SETTING, middleX, middleY + 6, 25, "SETTING", cColor::WHITE, cColor::WHITE);

	vector<cTextBox> menu = {newGame , loadGame, setting};
	cScreen choice = scrolling_menu(menu, cColor::RED);

	if (choice == cScreen::GAME)
		screen_game();
	else if (choice == cScreen::LOAD_GAME)
		screen_load_game();
	else if (choice == cScreen::SETTING)
		screen_setting();
	else
		throw;

}

void screen_game()
{
	system("cls");
	cout << "Game" << endl;
}

void screen_load_game()
{
	system("cls");
	cout << "Load game" << endl;
}

void screen_save_game()
{
	system("cls");
	cout << "Save game" << endl;
}

void screen_setting()
{
	system("cls");
	cout << "Setting" << endl;
}

void screen_continue()
{
	system("cls");
	cout << "Continue" << endl;
}

void screen_win()
{
	system("cls");
	cout << "Win" << endl;
}

void screen_game_over()
{
	system("cls");

	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "  ____   ____  ___ ___    ___       ___   __ __    ___  ____", cColor::CYAN, true);
	print_text_at_middle(middleY - 14, " /    | /    ||   |   |  /  _]     /   \\ |  |  |  /  _]|    \\ ", cColor::CYAN, true);
	print_text_at_middle(middleY - 13, "|   __||  o  || _   _ | /  [_     |     ||  |  | /  [_ |  D  ) ", cColor::CYAN, true);
	print_text_at_middle(middleY - 12, "|  |  ||     ||  \\_/  ||    _]    |  O  ||  |  ||    _]|    / ", cColor::CYAN, true);
	print_text_at_middle(middleY - 11, "|  |_ ||  _  ||   |   ||   [_     |     ||  :  ||   [_ |    \\ ", cColor::CYAN, true);
	print_text_at_middle(middleY - 10, "|     ||  |  ||   |   ||     |    |     | \\   / |     ||  .  \\ ", cColor::CYAN, true);
	print_text_at_middle(middleY - 9, "|___,_||__|__||___|___||_____|     \\___/   \\_/  |_____||__|\\_| ", cColor::CYAN, true);

	cTextBox _continue(cScreen::CONTINUE, middleX, middleY - 10, 25, "OK", cColor::WHITE, cColor::WHITE);

	vector<cTextBox> menuGameOver = { _continue};
	cScreen choice = scrolling_menu(menuGameOver, cColor::RED);

	if (choice == cScreen::CONTINUE)
		screen_continue();
	else
		throw;
}
