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
	cout << "Sign in" << endl;
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
	cout << "Game over" << endl;
}

void draw_coming_soon()
{
	unsigned middleX = get_console_width()/2;
	unsigned middleY = get_console_height()/2;

	print_text_at_middle(middleY - 18, "                                         _                                                                                                          ", cColor::GREEN, true);
	print_text_at_middle(middleY - 17, "                                        |_|                                                                                                         " , cColor::GREEN, true);
	print_text_at_middle(middleY - 16, " ______     ________     __________     ___     _____    __     _______              ______     ________     ________     _____    __               ", cColor::GREEN, true);
	print_text_at_middle(middleY - 15, "/      \\   /   __   \\   |          |   |   |   |     \\  |  |   /       \\            /  ____|   /   __   \\   /   __   \\   |     \\  |  |               ", cColor::GREEN, true);
	print_text_at_middle(middleY - 14, "|   ___|   |  |  |  |   |  |\\  /|  |   |   |   |  |\\  \\ |  |   |  _____|            |  |       |  |  |  |   |  |  |  |   |  |\\  \\ |  |               ", cColor::GREEN, true);
	print_text_at_middle(middleY - 13, "|  |       |  |  |  |   |  | \\/ |  |   |   |   |  | \\  \\|  |   |  |                  \\  \\      |  |  |  |   |  |  |  |   |  | \\  \\|  |               ", cColor::GREEN, true);
	print_text_at_middle(middleY - 12, "|  |       |  |  |  |   |  |    |  |   |   |   |  |  \\     |   |  | _____             \\  \\     |  |  |  |   |  |  |  |   |  |  \\     |               ", cColor::GREEN, true);
	print_text_at_middle(middleY - 11, "|  |___    |  |  |  |   |  |    |  |   |   |   |  |   \\    |   |  ||__ __|             \\  \\    |  |  |  |   |  |  |  |   |  |   \\    |               ", cColor::GREEN, true);
	print_text_at_middle(middleY - 10, "|      |   |  |__|  |   |  |    |  |   |   |   |  |    \\   |   |  |__| |             ___|  |   |  |__|  |   |  |__|  |   |  |    \\   |   _    _    _", cColor::GREEN, true);
	print_text_at_middle(middleY - 9 , "\\______/   \\________/   |__|    |__|   |___|   |__|     |__|   \\_______/            |______/   \\________/   \\________/   |__|     |__|  |_|  |_|  |_|", cColor::GREEN, true);


}
