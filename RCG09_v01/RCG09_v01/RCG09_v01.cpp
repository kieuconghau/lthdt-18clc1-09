#include "cGame.h"

int main()
{
	srand(time(nullptr));
	cGame* game = cGame::get_instance();
	game->play();

	//cScreen::screen_how_to_play();
	return 0;
}