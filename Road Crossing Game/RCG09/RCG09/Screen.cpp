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

//<<<<<<< HEAD
	unsigned int middleX = get_console_width() / 2;
	unsigned int middleY = get_console_height() / 2;


	print_text_at_middle(middleY - 15, "  _____ ____   ____  ____       __ __  ____  ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, " / ___/|    | /    ||    \\     |  |  ||    \\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "(   \\_  |  | |   __||  _  |    |  |  ||  o  )", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, " \\__  | |  | |  |  ||  |  |    |  |  ||   _/", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, " /  \\ | |  | |  |_ ||  |  |    |  :  ||  |   ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, " \\    | |  | |     ||  |  |    |     ||  |   ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 9, "  \\___||____||___,_||__|__|     \\__,_||__|   ", ecColor::CYAN, true);

	print_text_at_middle(middleY - 7, " Coming soon! ", ecColor::BLUE, true);

	cTextBox back(cScreen::ACCOUNT, middleX, middleY + 10, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

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

	print_text_at_middle(middleY - 18, "                                         _                                                                                                          ", ecColor::GREEN, true);
	print_text_at_middle(middleY - 17, "                                        |_|                                                                                                         " , ecColor::GREEN, true);
	print_text_at_middle(middleY - 16, " ______     ________     __________     ___     _____    __     _______              ______     ________     ________     _____    __               ", ecColor::GREEN, true);
	print_text_at_middle(middleY - 15, "/      \\   /   __   \\   |          |   |   |   |     \\  |  |   /       \\            /  ____|   /   __   \\   /   __   \\   |     \\  |  |               ", ecColor::GREEN, true);
	print_text_at_middle(middleY - 14, "|   ___|   |  |  |  |   |  |\\  /|  |   |   |   |  |\\  \\ |  |   |  _____|            |  |       |  |  |  |   |  |  |  |   |  |\\  \\ |  |               ", ecColor::GREEN, true);
	print_text_at_middle(middleY - 13, "|  |       |  |  |  |   |  | \\/ |  |   |   |   |  | \\  \\|  |   |  |                  \\  \\      |  |  |  |   |  |  |  |   |  | \\  \\|  |               ", ecColor::GREEN, true);
	print_text_at_middle(middleY - 12, "|  |       |  |  |  |   |  |    |  |   |   |   |  |  \\     |   |  | _____             \\  \\     |  |  |  |   |  |  |  |   |  |  \\     |               ", ecColor::GREEN, true);
	print_text_at_middle(middleY - 11, "|  |___    |  |  |  |   |  |    |  |   |   |   |  |   \\    |   |  ||__ __|             \\  \\    |  |  |  |   |  |  |  |   |  |   \\    |               ", ecColor::GREEN, true);
	print_text_at_middle(middleY - 10, "|      |   |  |__|  |   |  |    |  |   |   |   |  |    \\   |   |  |__| |             ___|  |   |  |__|  |   |  |__|  |   |  |    \\   |   _    _    _", ecColor::GREEN, true);
	print_text_at_middle(middleY - 9 , "\\______/   \\________/   |__|    |__|   |___|   |__|     |__|   \\_______/            |______/   \\________/   \\________/   |__|     |__|  |_|  |_|  |_|", ecColor::GREEN, true);


}
