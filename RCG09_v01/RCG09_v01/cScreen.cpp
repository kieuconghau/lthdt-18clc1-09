#include "cScreen.h"
#include "cObject.h"
#include "cLane.h"
#include  "cBird.h"
#include "cDinosaur.h"
#include "cCar.h"
#include "cCoin.h"
#include "cFixedObjectLane.h"
#include "cMovableObjectLane.h"
#include "cStone.h"
#include "cTrain.h"
#include "cTruck.h"
#include "cWood.h"
#include "cGame.h"

/*void cScreen::screen_account()
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
	// How to play?

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
}*/

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

	print_text_at_middle(middleY - 4, "18127259 - Kieu Cong Hau", ecColor::GREY, true);
	print_text_at_middle(middleY -2, "18127118 - Mai Dang Khanh", ecColor::GREY, true);
	print_text_at_middle(middleY + 0, "18127014 - Huynh Nhat Nam", ecColor::GREY, true);


	cTextBox back(cTextBox::ecScreenType::MENU, middleX, middleY + 10, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { back };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::MENU)
		return;
	else
		throw;

}

void cScreen::screen_menu()
{
	while (true) {
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
		cTextBox loadGame(cTextBox::ecScreenType::LOAD_GAME, middleX, middleY + 1, 25, "LOAD GAME", ecColor::WHITE, ecColor::WHITE);
		cTextBox setting(cTextBox::ecScreenType::SETTING, middleX, middleY + 4, 25, "SETTING", ecColor::WHITE, ecColor::WHITE);
		cTextBox about(cTextBox::ecScreenType::ABOUT, middleX, middleY + 7, 25, "ABOUT", ecColor::WHITE, ecColor::WHITE);
		cTextBox howToPlay(cTextBox::ecScreenType::HOW_TO_PLAY, middleX, middleY + 10, 25, "HOW TO PLAY", ecColor::WHITE, ecColor::WHITE);
		cTextBox back(cTextBox::ecScreenType::ENDING, middleX, middleY + 13, 25, "EXIT", ecColor::WHITE, ecColor::WHITE);

		vector<cTextBox> menu = { newGame , loadGame, setting, about, howToPlay, back };
		cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

		if (choice == cTextBox::ecScreenType::GAME)
			screen_game();
		else if (choice == cTextBox::ecScreenType::LOAD_GAME)
			screen_load_game();
		else if (choice == cTextBox::ecScreenType::SETTING)
			screen_setting();
		else if (choice == cTextBox::ecScreenType::ABOUT)
			screen_about();
		else if (choice == cTextBox::ecScreenType::HOW_TO_PLAY)
			screen_how_to_play();
		else if (choice == cTextBox::ecScreenType::ENDING) {
			screen_ending();
			break;
		}
		else
			throw;
	}
}

void cScreen::screen_game()
{
	system("cls");
	cGame* game = cGame::get_instance();
	game->new_game();
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
		cGame* g = cGame::get_instance();
		g->load_game();
		if (g->state_is_loading()) {
			g->play();
		}
	}
	else if (choice == cTextBox::ecScreenType::MENU)
		return;
	else
		throw;
}

void cScreen::screen_load_mid_game()
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
	cTextBox back(cTextBox::ecScreenType::GAME, middleX, middleY + 2, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { loadGame, back };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::LOAD_GAME)
	{
		cGame* g = cGame::get_instance();
		g->load_game();
		system("cls");
	}
	else if (choice == cTextBox::ecScreenType::GAME)
		system("cls");
	else
		throw;
}

void cScreen::screen_save_game()
{
		//Save Game
		system("cls");

		unsigned middleX = get_console_width() / 2;
		unsigned middleY = get_console_height() / 2;

		print_text_at_middle(middleY - 15, "   _____  ____  __ __    ___       ____   ____  ___ ___    ___", ecColor::BLUE, true);
		print_text_at_middle(middleY - 14, "  / ___/ /    ||  |  |  /  _]     /    | /    ||   |   |  /  _]", ecColor::BLUE, true);
		print_text_at_middle(middleY - 13, " (   \\_ |  o  ||  |  | /  [_     |   __||  o  || _   _ | /  [_ ", ecColor::BLUE, true);
		print_text_at_middle(middleY - 12, "  \\__  ||     ||  |  ||    _]    |  |  ||     ||  \\_/  ||    _]", ecColor::BLUE, true);
		print_text_at_middle(middleY - 11, " /  \\ ||  _  ||  :  ||   [_     |  |_ ||  _  ||   |   ||   [_", ecColor::BLUE, true);
		print_text_at_middle(middleY - 10, "  \\    ||  |  | \\   / |     |    |     ||  |  ||   |   ||     |", ecColor::BLUE, true);
		print_text_at_middle(middleY - 9, "   \\___||__|__|  \\_/  |_____|    |___,_||__|__||___|___||_____|", ecColor::BLUE, true);

		cTextBox saveGame(cTextBox::ecScreenType::SAVE_GAME, middleX, middleY - 2, 25, "SAVE GAME", ecColor::WHITE, ecColor::WHITE);
		cTextBox back(cTextBox::ecScreenType::GAME, middleX, middleY + 2, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

		vector<cTextBox> menu = { saveGame, back };
		cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

		if (choice == cTextBox::ecScreenType::SAVE_GAME)
		{
			cGame* g = cGame::get_instance();
			g->save_game();
			system("cls");
		}
		else if (choice == cTextBox::ecScreenType::GAME)
			system("cls");
		else
			throw;
}

void cScreen::screen_pause_game()
{
	//Pause game()
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " ____   ____  __ __  _____   ___ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 14, "|    \\ /    ||  |  |/ ___/  /  _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 13, "|  o  )  o  ||  |  (   \\_  /  [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 12, "|   _/|     ||  |  |\\__  ||    _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 11, "|  |  |  _  ||  :  |/  \\ ||   [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 10, "|  |  |  |  ||     |\\    ||     |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 9, "|__|  |__|__| \\__,_| \\___||_____|", ecColor::BLUE, true);

	cTextBox back(cTextBox::ecScreenType::GAME, middleX, middleY - 2, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { back };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::GAME)
		system("cls");
	else
		throw;
}


void cScreen::screen_setting()
{
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	cScreen::draw_coming_soon();

	cTextBox back(cTextBox::ecScreenType::MENU, middleX, middleY + 2, 25, "BACK", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { back };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::MENU)
		return;
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

	cTextBox yes(cTextBox::ecScreenType::YES, middleX , middleY , 25, "Yes", ecColor::WHITE, ecColor::WHITE);
	cTextBox no(cTextBox::ecScreenType::NO, middleX , middleY + 4, 25, "No", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menuLoadGame = { yes,no };

	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menuLoadGame, ecColor::RED);

	if (choice == cTextBox::ecScreenType::YES)
	{
		cGame* game = cGame::get_instance();
		game->playing();
	}
	else if (choice == cTextBox::ecScreenType::NO) {
		cGame* game = cGame::get_instance();
		game->give_up();
	}	
	else
		throw;
}

void cScreen::screen_win()
{
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	screen_border_decoration(0,12);

	print_text_at_middle(middleY + 8, "press enter to continue", ecColor::LIGHT_WHITE, true);

	int speed = 50;

	while(true) {
	
		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::RED);
		Sleep(speed);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::LIGHT_RED);
		Sleep(speed);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::LIGHT_YELLOW);
		Sleep(speed);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::GREEN);
		Sleep(speed);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::CYAN);
		Sleep(speed);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::LIGHT_PURPLE);
		Sleep(speed);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::PURPLE);
		Sleep(speed);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::GREY);
		Sleep(speed);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::GREEN);
		Sleep(speed);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::BLUE);
		Sleep(speed);

		if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
			break;
		}
		draw_win(ecColor::YELLOW);
		Sleep(speed);
	}
	Sleep(100);
	system("CLS");

	cTextBox ok(cTextBox::ecScreenType::CONTINUE, middleX, middleY , 35, "Winner Winner Chicken Dinner !!!", ecColor::WHITE, ecColor::WHITE);

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

	cTextBox ok(cTextBox::ecScreenType::CONTINUE, middleX, middleY , 25, "OK FINE", ecColor::WHITE, ecColor::WHITE);

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

void cScreen::screen_border_decoration(int distanceFromScreenBorder,int numberOfLine)
{
	screen_border_decoration_outside_border(distanceFromScreenBorder);

	for (int i = 0; i < numberOfLine; i++) {
		screen_border_decoration_inside(++distanceFromScreenBorder);
	}
	screen_border_decoration_inside_border(distanceFromScreenBorder);
}

void cScreen::screen_border_decoration_inside(int distanceFromScreenBorder)
{
	unsigned screenHeight = get_console_height();
	unsigned screenWidth = get_console_width();

	//space from screen border to corners decoration
	unsigned space1 = distanceFromScreenBorder;

	//space from corners decoration to sides decoration
	unsigned space2 = 1;
	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	text_color(ecColor::RED);

	goto_xy(space1, space1);
	cout << char(206);

	goto_xy(screenWidth - space1, space1);
	cout << char(206);

	goto_xy(screenWidth - space1, screenHeight - space1);
	cout << char(206);

	goto_xy(space1, screenHeight - space1);
	cout << char(206);

	text_color(ecColor::YELLOW);

	goto_xy(space1 + space2, space1);
	for (int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
		cout << char(206);
	}

	goto_xy(space1 + space2, screenHeight - space1);
	for (int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
		cout << char(206);
	}

	goto_xy(space1, space1 + space2);
	for (int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(space1, i);
		cout << char(206);
	}

	goto_xy(screenWidth - space1, space1 + space2);
	for (int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(screenWidth - space1, i);
		cout << char(206);
	}

	text_color(ecColor::BLACK);
}

void cScreen::screen_border_decoration_outside_border(int distanceFromScreenBorder)
{
	unsigned screenHeight = get_console_height();
	unsigned screenWidth = get_console_width();

	//space from screen border to corners decoration
	unsigned space1 = distanceFromScreenBorder;

	//space from corners decoration to sides decoration
	unsigned space2 = 1;
	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	text_color(ecColor::RED);

	goto_xy(space1, space1);
	cout << char(201);

	goto_xy(screenWidth - space1, space1);
	cout << char(187);

	goto_xy(screenWidth - space1, screenHeight - space1);
	cout << char(188);

	goto_xy(space1, screenHeight - space1);
	cout << char(200);

	text_color(ecColor::YELLOW);

	goto_xy(space1 + space2, space1);
	for (int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
		cout << char(203);
	}

	goto_xy(space1 + space2, screenHeight - space1);
	for (int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
		cout << char(202);
	}

	goto_xy(space1, space1 + space2);
	for (int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(space1, i);
		cout << char(204);
	}

	goto_xy(screenWidth - space1, space1 + space2);
	for (int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(screenWidth - space1, i);
		cout << char(185);
	}

	text_color(ecColor::BLACK);
}

void cScreen::screen_border_decoration_inside_border(int distanceFromScreenBorder)
{
	unsigned screenHeight = get_console_height();
	unsigned screenWidth = get_console_width();

	//space from screen border to corners decoration
	unsigned space1 = distanceFromScreenBorder;

	//space from corners decoration to sides decoration
	unsigned space2 = 1;
	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	text_color(ecColor::RED);

	goto_xy(space1, space1);
	cout << char(206);

	goto_xy(screenWidth - space1, space1);
	cout << char(206);

	goto_xy(screenWidth - space1, screenHeight - space1);
	cout << char(206);

	goto_xy(space1, screenHeight - space1);
	cout << char(206);

	text_color(ecColor::YELLOW);

	goto_xy(space1 + space2, space1);
	for (int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
		cout << char(202);

	}

	goto_xy(space1 + space2, screenHeight - space1);
	for (int i = space1 + space2; i <= screenWidth - space1 - space2; i++) {
		cout << char(203);

	}

	goto_xy(space1, space1 + space2);
	for (int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(space1, i);
		cout << char(185);
	}

	goto_xy(screenWidth - space1, space1 + space2);
	for (int i = space1 + space2; i <= screenHeight - space1 - space2; i++) {
		goto_xy(screenWidth - space1, i);
		cout << char(204);
	}

	text_color(ecColor::BLACK);

}

void cScreen::screen_ending()
{
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	unsigned lastY = get_console_height();

	print_text_at_middle(middleY - 17, " _________    ___  ___      ________      ________       ___  __             ___    ___  ________      ___  ___         ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 16, "|\\___   ___\\ |\\  \\|\\  \\    |\\   __  \\    |\\   ___  \\    |\\  \\|\\  \\          |\\  \\  /  /||\\   __  \\    |\\  \\|\\  \\        ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 15, "\\|___ \\  \\_| \\ \\  \\\\\\  \\   \\ \\  \\|\\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\/  /|_        \\ \\  \\/  / /\\ \\  \\|\\  \\   \\ \\  \\\\\\  \\       ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 14, "     \\ \\  \\   \\ \\   __  \\   \\ \\   __  \\   \\ \\  \\\\ \\  \\   \\ \\   ___  \\        \\ \\    / /  \\ \\  \\\\\\  \\   \\ \\  \\\\\\  \\      ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 13, "      \\ \\  \\   \\ \\  \\ \\  \\   \\ \\  \\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\\\ \\  \\        \\/  /  /    \\ \\  \\\\\\  \\   \\ \\  \\\\\\  \\     ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 12, "       \\ \\__\\   \\ \\__\\ \\__\\   \\ \\__\\ \\__\\   \\ \\__\\\\ \\__\\   \\ \\__\\\\ \\__\\     __/  / /       \\ \\_______\\   \\ \\_______\\     ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 11, "        \\|__|    \\|__|\\|__|    \\|__|\\|__|    \\|__| \\|__|    \\|__| \\|__|    |\\___/ /         \\|_______|    \\|_______|     ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 10, "                                                                           \\|___|/                                      ", ecColor::CYAN, true);

	print_text_at_middle(middleY - 7, " ________  ________      ________          ________    ___           ________       ___    ___  ___      ________       ________      ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 6, "|\\  _____\\|\\   __  \\    |\\   __  \\        |\\   __  \\  |\\  \\         |\\   __  \\     |\\  \\  /  /||\\  \\    |\\   ___  \\    |\\   ____\\     ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 5, "\\ \\  \\__/ \\ \\  \\|\\  \\   \\ \\  \\|\\  \\       \\ \\  \\|\\  \\ \\ \\  \\        \\ \\  \\|\\  \\    \\ \\  \\/  / /\\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\___|     ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 4, " \\ \\   __\\ \\ \\  \\\\\\  \\   \\ \\   _  _\\       \\ \\   ____\\ \\ \\  \\        \\ \\   __  \\    \\ \\    / /  \\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\  ___   ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 3, "  \\ \\  \\_|  \\ \\  \\\\\\  \\   \\ \\  \\\\  \\|       \\ \\  \\___|  \\ \\  \\____    \\ \\  \\ \\  \\    \\/  /  /    \\ \\  \\   \\ \\  \\\\ \\  \\   \\ \\  \\|\\  \\  ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 2, "   \\ \\__\\    \\ \\_______\\   \\ \\__\\\\ _\\        \\ \\__\\      \\ \\_______\\   \\ \\__\\ \\__\\ __/  / /       \\ \\__\\   \\ \\__\\\\ \\__\\   \\ \\_______\\ ", ecColor::CYAN, true);
	print_text_at_middle(middleY - 1, "    \\|__|     \\|_______|    \\|__|\\|__|        \\|__|       \\|_______|    \\|__|\\|__||\\___/ /         \\|__|    \\|__| \\|__|    \\|_______| ", ecColor::CYAN, true);
	print_text_at_middle(middleY + 0, "                                                                                  \\|___|/                                             ", ecColor::CYAN, true);

	Sleep(300);
	print_text_at_middle(lastY - 16, "This game was made by: GROUP 9 - 18CLC1", ecColor::GREEN, true);
	Sleep(300);

	print_text_at_middle(lastY - 14, "18127259 - Kieu Cong Hau", ecColor::GREY, true);
	Sleep(300);
	print_text_at_middle(lastY - 12 , "18127118 - Mai Dang Khanh", ecColor::GREY, true);
	Sleep(300);
	print_text_at_middle(lastY - 10, "18127014 - Huynh Nhat Nam", ecColor::GREY, true);
	Sleep(300);

	cTextBox exit(cTextBox::ecScreenType::CONTINUE, middleX, lastY - 6, 25, "BYE BYE", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { exit };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	cGame* game = cGame::get_instance();
	delete game;
}

void cScreen::draw_win(ecColor color)
{
	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;
	print_text_at_middle(middleY - 8, "                                                   ,---,  ", color, true);
	print_text_at_middle(middleY - 7, "                                   ,--.         ,`--.' |  ", color, true);
	print_text_at_middle(middleY - 6, "           .---.    ,---,        ,--.'|         |   :  :  ", color, true);
	print_text_at_middle(middleY - 5, "          /. ./| ,`--.' |    ,--,:  : |         '   '  ;  ", color, true);
	print_text_at_middle(middleY - 4, "      .--'.  ' ; |   :  : ,`--.'`|  ' :         |   |  |  ", color, true);
	print_text_at_middle(middleY - 3, "     /__./ \\ : | :   |  ' |   :  :  | |         '   :  ;  ", color, true);
	print_text_at_middle(middleY - 2, " .--'.  '   \\' . |   :  | :   |   \\ | :         |   |  '  ", color, true);
	print_text_at_middle(middleY - 1, "/___/ \\ |    ' ' '   '  ; |   : '  '; |         '   :  |  ", color, true);
	print_text_at_middle(middleY, ";   \\  \\;      : |   |  | '   ' ;.    ;         ;   |  ;  ", color, true);
	print_text_at_middle(middleY + 1, " \\   ;  `      | '   :  ; |   | | \\   |         `---'. |  ", color, true);
	print_text_at_middle(middleY + 2, "  .   \\    .\\  ; |   |  ' '   : |  ; .'          `--..`;  ", color, true);
	print_text_at_middle(middleY + 3, "   \\   \\   ' \\ | '   :  | |   | '`--'           .--,_     ", color, true);
	print_text_at_middle(middleY + 4, "    :   '  |--'  ;   |.'  '   : |               |    |`.  ", color, true);
	print_text_at_middle(middleY + 5, "     \\   \\ ;     '---'    ;   |.'               `-- -`, ; ", color, true);
	print_text_at_middle(middleY + 6, "      '---'               '---'                   '---`'  ", color, true);
}

void cScreen::screen_escape()
{
	system("cls");

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " ____   ____  __ __  _____   ___ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 14, "|    \\ /    ||  |  |/ ___/  /  _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 13, "|  o  )  o  ||  |  (   \\_  /  [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 12, "|   _/|     ||  |  |\\__  ||    _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 11, "|  |  |  _  ||  :  |/  \\ ||   [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 10, "|  |  |  |  ||     |\\    ||     |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 9, "|__|  |__|__| \\__,_| \\___||_____|", ecColor::BLUE, true);

	cTextBox resume(cTextBox::ecScreenType::CONTINUE, middleX, middleY - 2, 25, "RESUME GAME", ecColor::WHITE, ecColor::WHITE);
	cTextBox save(cTextBox::ecScreenType::SAVE_GAME, middleX, middleY + 2, 25, "SAVE GAME", ecColor::WHITE, ecColor::WHITE);
	cTextBox load(cTextBox::ecScreenType::LOAD_GAME, middleX, middleY + 6, 25, "LOAD GAME", ecColor::WHITE, ecColor::WHITE);;
	cTextBox quit(cTextBox::ecScreenType::MENU, middleX, middleY + 10, 25, "QUIT GAME", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { resume,save,load,quit };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::CONTINUE)
		system("cls");
	else if (choice == cTextBox::ecScreenType::SAVE_GAME)
		screen_save_game();
	else if (choice == cTextBox::ecScreenType::LOAD_GAME)
		screen_load_mid_game();
	else if (choice == cTextBox::ecScreenType::MENU) {
		cGame* game = cGame::get_instance();
		game->give_up();
	}
	else
		throw;
}

bool cScreen::screen_confirm()
{
	system("cls");


	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 14, "Are you sure?", ecColor::WHITE, true);

	cTextBox yes(cTextBox::ecScreenType::YES, middleX, middleY - 12, 25, "YES", ecColor::WHITE, ecColor::WHITE);
	cTextBox no(cTextBox::ecScreenType::NO, middleX, middleY - 8, 25, "NO", ecColor::WHITE, ecColor::WHITE);

	vector<cTextBox> menu = { yes,no };
	cTextBox::ecScreenType choice = cTextBox::scrolling_menu(menu, ecColor::RED);

	if (choice == cTextBox::ecScreenType::YES)
		return true;
	else if (choice == cTextBox::ecScreenType::NO)
		return false;
	else throw;

}

void cScreen::screen_how_to_play()
{
	system("cls");

	ecColor textColor = ecColor::CYAN;

	int distanceFromLeftBorder = 3;
	int i = 1;

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	print_text_at_middle(0, " __ __   ___   __    __      ______   ___       ____   _       ____  __ __ ", ecColor::BLUE, true);
	print_text_at_middle(1, "|  |  | /   \\ |  |__|  |    |      | /   \\     |    \\ | |     /    ||  |  |", ecColor::BLUE, true);
	print_text_at_middle(2, "|  |  ||     ||  |  |  |    |      ||     |    |  o  )| |    |  o  ||  |  |", ecColor::BLUE, true);
	print_text_at_middle(3, "|  _  ||  O  ||  |  |  |    |_|  |_||  O  |    |   _/ | |___ |     ||  ~  |", ecColor::BLUE, true);
	print_text_at_middle(4, "|  |  ||     ||  `  '  |      |  |  |     |    |  |   |     ||  _  ||___, |", ecColor::BLUE, true);
	print_text_at_middle(5, "|  |  ||     | \\      /       |  |  |     |    |  |   |     ||  |  ||     |", ecColor::BLUE, true);
	print_text_at_middle(6, "|__|__| \\___/   \\_/\\_/        |__|   \\___/     |__|   |_____||__|__||____/ ", ecColor::BLUE, true);

	ecDirection direction = ecDirection::RIGHT;

	ecColor firstColor = ecColor::RED;
	ecColor secondColor = ecColor::BLUE;
	ecColor thirdColor = ecColor::CYAN;
	ecColor fourthColor = ecColor::GREEN;
	ecColor fifthColor = ecColor::YELLOW;

	int firstLeftLimit = 1;
	int firstRightLimit = middleX - 2;

	int secondLeftLimit = middleX + 2;
	int secondRightLimit = get_console_width() - 1;

	cPeople* People = cPeople::get_instance();
	People->set_starting_pos(24, 8);

	goto_xy(distanceFromLeftBorder, 8);
	text_color(textColor);
	cout << i++ << ". CONTROL CHARACTER  ";
	cout << " BY USING ARROW KEYS." << endl;

	goto_xy(distanceFromLeftBorder, 10);
	cout << i++ << ". TOUCH THESE THINGS IF YOU REALLY WANT TO DIE!!! " << endl;

	int distanceBetweenObjects = get_console_width() / 5;

	text_color(ecColor::GREY);
	goto_xy(distanceFromLeftBorder + distanceBetweenObjects * 0 + 10, 11);
	cout << "Bird";

	goto_xy(distanceFromLeftBorder + distanceBetweenObjects * 1 + 10, 11);
	cout << "Dinosaur";

	goto_xy(distanceFromLeftBorder + distanceBetweenObjects * 2 + 10, 11);
	cout << "Car";

	goto_xy(distanceFromLeftBorder + distanceBetweenObjects * 3 + 10, 11);
	cout << "Train";

	goto_xy(distanceFromLeftBorder + distanceBetweenObjects * 4 + 10, 11);
	cout << "Truck";

	cBird bird(direction, firstColor, distanceFromLeftBorder + distanceBetweenObjects * 0 + 13, 13, 1, 0);
	bird.draw(0, get_console_width());

	cDinosaur dinosaur(direction, secondColor, distanceFromLeftBorder + distanceBetweenObjects * 1 + 13, 13, 1, 0);
	dinosaur.draw(0, get_console_width());

	cCar car(direction, thirdColor, distanceFromLeftBorder + distanceBetweenObjects * 2 + 13, 13, 1, 0);
	car.draw(0, get_console_width());

	cTrain train(direction, fourthColor, distanceFromLeftBorder + distanceBetweenObjects * 3 + 28, 13, 1, 0);
	train.draw(0, get_console_width());

	cTruck truck(direction, fifthColor, distanceFromLeftBorder + distanceBetweenObjects * 4 + 13, 13, 1, 0);
	truck.draw(0, get_console_width());

	goto_xy(distanceFromLeftBorder, 15);
	text_color(textColor);
	cout << i++ << ". THE RIVER. YOU SUCK AT SWIMMING, SO YOU WILL DROWN. BUT LUCKILY, THERE ARE WOODS FOR YOU TO CROSS IT. " << endl;
	cMovableObjectLane waterLane(cObject::ecType::MF_WOOD, direction, ecColor::BLUE, 10, 17, { 0,0,0 }, 1, 0, 0, get_console_width() - 1, 0);
	waterLane.draw();

	goto_xy(distanceFromLeftBorder, 19);
	text_color(textColor);
	cout << i++ << ". THERE ARE ROCKS: ";
	text_color(ecColor::GREY);
	cout << char(219) << char(219) << char(219);
	text_color(textColor);
	cout << " THEY BLOCK YOUR WAY AND YOU CAN'T DO ANYTHING TO THEM. " << endl;

	goto_xy(distanceFromLeftBorder, 21);
	text_color(textColor);
	cout << i++ << ". THERE ARE COINS ";
	cCoin coin(direction, ecColor::YELLOW, 25, 21);
	coin.draw(0,70);
	
	goto_xy(distanceFromLeftBorder + 25 + 4, 21);
	text_color(textColor);
	cout << "AND YOU REALLY NEED TO COLLECT ALL OF THEM. " << endl;


	goto_xy(distanceFromLeftBorder, 23);
	text_color(textColor);
	cout << i++ << ". HOW TO LOSE:" << endl;
	int j = 1;
	cout << "	" << j++ << ". dead." << endl;
	cout << "	" << j++ << ". DEAD." << endl;
	cout << "	" << j++ << ". Out of time (there will be time limit for each level, please PAY ATTENTION)." << endl;


	goto_xy(distanceFromLeftBorder, 28);
	text_color(textColor);
	cout << i++ << ". HOW TO WIN:" << endl;
	j = 1;
	cout << "	" << j++ << ". DON'T LOSE FIRST. " << endl;
	cout << "	" << j++ << ". There will be a roadblock in front of finish line so you need to collect ALL coins to destroy it." << endl;
	cout << "	" << j++ << ". Reach the finish line" << endl;

	goto_xy(distanceFromLeftBorder, 33);
	cout << i++ << ". SOME HOT KEYS FOR YOU: " << " P: pause game	" << "S: save game	" << "L: load game	" << "ESC: exit";

	print_text_at_middle(35, "GOOD LUCK!!! press enter to continue", ecColor::LIGHT_YELLOW, true);

	while (true) {
		waterLane.work(People);

		if (GetAsyncKeyState(VK_RETURN) != 0) {
			Sleep(50);
			break;
		}
		Sleep(50);
	}

	goto_xy(0, 0);

	
}

void cScreen::draw_save_game()
{
	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "   _____  ____  __ __    ___       ____   ____  ___ ___    ___", ecColor::BLUE, true);
	print_text_at_middle(middleY - 14, "  / ___/ /    ||  |  |  /  _]     /    | /    ||   |   |  /  _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 13, " (   \\_ |  o  ||  |  | /  [_     |   __||  o  || _   _ | /  [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 12, "  \\__  ||     ||  |  ||    _]    |  |  ||     ||  \\_/  ||    _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 11, " /  \\ ||  _  ||  :  ||   [_     |  |_ ||  _  ||   |   ||   [_", ecColor::BLUE, true);
	print_text_at_middle(middleY - 10, "  \\    ||  |  | \\   / |     |    |     ||  |  ||   |   ||     |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 9, "   \\___||__|__|  \\_/  |_____|    |___,_||__|__||___|___||_____|", ecColor::BLUE, true);
}

void cScreen::draw_load_game()
{
	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " _       ___    ____  ___         ____   ____  ___ ___    ___ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 14, "| |     /   \\  /    ||   \\       /    | /    ||   |   |  /  _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 13, "| |    |     ||  o  ||    \\     |   __||  o  || _   _ | /  [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 12, "| |___ |  O  ||     ||  D  |    |  |  ||     ||  \\_/  ||    _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 11, "|     ||     ||  _  ||     |    |  |_ ||  _  ||   |   ||   [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 10, "|     ||     ||  |  ||     |    |     ||  |  ||   |   ||     |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 9, "|_____| \\___/ |__|__||_____|    |___,_||__|__||___|___||_____|", ecColor::BLUE, true);
}

void cScreen::screen_reach_max_level()
{
	system("CLS");

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	goto_xy(middleX - 10, middleY);

	text_color(ecColor::CYAN);
	cout << "CONGRATULATIONS!!! YOU HAVE REACHED MAX LEVEL" << endl;
	goto_xy(middleX - 10, middleY + 2);
	system("pause");
}