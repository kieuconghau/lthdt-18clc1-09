#include "cGame.h"

int main()
{
	srand(time(nullptr));
	cGame* game = cGame::get_instance();
	game->play();

	return 0;
}