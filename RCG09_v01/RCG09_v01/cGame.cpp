#include "cGame.h"
#include <limits>

cGame* cGame::Instance = nullptr;

const int cGame::LevelCount = 2;


cGame* cGame::get_instance()
{
	if (cGame::Instance == nullptr)
	{
		cGame::Instance = new cGame;
	}

	return cGame::Instance;
}

cGame::cGame()
{
	this->Levels = new cLevel[cGame::LevelCount];
	this->CurrentLevel = 1;
	this->State = cGame::ecState::PLAYING;

	/* Setting: Levels */
	const int laneCounts[cGame::LevelCount] = { 6, 7 };
	const int leftLimit = cSetting::Game::LEFT_LIMIT + 1;
	const int rightLimit = cSetting::Game::RIGHT_LIMIT - 1;

	/* Level 1 */
	int timeAlotted0 = 10;//second... kind of
	int finishLine0 = cSetting::Game::TOP_LIMIT + 1;
	int maxCoin0 = 2; // must be equal to the number of level's coins;
	vector<cObject::ecType> objectTypes0 =	{ cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MV_CAR		, cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MF_WOOD	, cObject::ecType::MA_BIRD		, cObject::ecType::MV_TRAIN };
	vector<ecDirection> directions0 =		{ ecDirection::RIGHT					, ecDirection::LEFT				, ecDirection::RIGHT					, ecDirection::RIGHT		, ecDirection::LEFT				, ecDirection::RIGHT };
	vector<ecColor> colors0 =				{ ecColor::GREY							, ecColor::PURPLE				, ecColor::GREY							, ecColor::BLUE				, ecColor::LIGHT_GREEN			, ecColor::CYAN };
	vector<int> objectCounts0 =				{ 25									, 4								, 30									, 9							, 6								, 1 };
	vector<vector<int>> times0 =			{ {0, 0, 0}								, {10, 15, 15}					, {0, 0, 0}								, {0, 0, 0}					, {0, 10, 20}						, {0, 0, 0} };
	vector<int> steps0 =					{ 2										, 1								, 1										, 1							, 1								, 9	};
	vector<int> crazySteps0 =				{ 0										, 2								, 0										, 0							, 1								, 0 };
	this->Levels[0].set_up(1, laneCounts[0], finishLine0, maxCoin0, timeAlotted0, objectTypes0, directions0, colors0, objectCounts0, times0, steps0, crazySteps0, leftLimit, rightLimit);

	/* Level 2 */
	int timeAlotted1 = 30;//second... kind of
	int finishLine1 = cSetting::Game::TOP_LIMIT + 1;
	int maxCoin1 = 2; // must be equal to the number of level's coins;
	vector<cObject::ecType> objectTypes1 =	{ cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MV_CAR	, cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MF_WOOD	, cObject::ecType::MA_BIRD		, cObject::ecType::MV_TRAIN	, cObject::ecType::MF_WOOD };
	vector<ecDirection> directions1 =		{ ecDirection::RIGHT					, ecDirection::LEFT			, ecDirection::RIGHT					, ecDirection::RIGHT		, ecDirection::LEFT				, ecDirection::RIGHT		, ecDirection::LEFT };
	vector<ecColor> colors1 =				{ ecColor::GREY							, ecColor::PURPLE			, ecColor::GREY							, ecColor::BLUE				, ecColor::LIGHT_GREEN			, ecColor::CYAN				, ecColor::BLUE };
	vector<int> objectCounts1 =				{ 25									, 4							, 30									, 9							, 6								, 1							, 6 };
	vector<vector<int>> times1 =			{ {0, 0, 0}								, {7, 5, 10}				, {0, 0, 0}								, {0, 0, 0}				    , {0, 5, 15}					, {0, 0, 0}					, {0, 0, 0} };
	vector<int> steps1 =					{ 2										, 1							, 1										, 1							, 1								, 9							, 1 };
	vector<int> crazySteps1 =				{ 0										, 2							, 0										, 0							, 1								, 0							, 0	};
	this->Levels[1].set_up(2, laneCounts[1], finishLine1, maxCoin1, timeAlotted1, objectTypes1, directions1, colors1, objectCounts1, times1, steps1, crazySteps1, leftLimit, rightLimit);
}

cGame::~cGame()
{
	delete[] this->Levels;
}

void cGame::play()
{
	this->State = ecState::PLAYING;

	while (true) {

		if (this->CurrentLevel > this->LevelCount) {
			this->CurrentLevel = this->LevelCount;
			cScreen::screen_reach_max_level();
			break;
		}


		this->Levels[CurrentLevel - 1].play();

		if (this->Levels[CurrentLevel - 1].won()) {
			this->CurrentLevel++;
			continue;
		}

		if (this->Levels[CurrentLevel - 1].lost() && (this->State == ecState::PLAYING)) {
			continue;
		}

		if (this->State == ecState::LOADING) {
			this->State = ecState::PLAYING;
			continue;
		}

		if (this->State == ecState::DEFEAT) {
			break;
		}

		if (this->State == ecState::VICTORY) {
			break;
		}
	}
}

void cGame::save_game()
{
	ShowConsoleCursor(true);
	system("cls");

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	int distanceFromLeftBorder = 30;

	ecColor textColor = ecColor::CYAN;

	string path;

	ofstream f;

	while (true) {
		system("cls");
		path.clear();

		try {
			cScreen::draw_save_game();

			text_color(textColor);
			goto_xy(0, middleY);

			cout << "Enter file's path or name (file's type is text file, you can enter 0 to return): ";

			getline(cin, path);
			cin.clear();

			if (path == "0") {
				ShowConsoleCursor(false);
				return ;
			}

			if (path == "")
			{
				continue;
			}

			if ((path.length() < 4) || (path[path.length() - 1] != 't') || (path[path.length() - 2] != 'x') || (path[path.length() - 3] != 't') || (path[path.length() - 4] != '.')) {
				throw "!.txt";
			}

			f.open(path);

			if (!f.is_open()) {
				throw false;
			}
			
			break;
		}
		catch (const char* msg) {
			//system("cls");
			path.clear();
			goto_xy(distanceFromLeftBorder, middleY + 2);
			if (msg == "!.txt") {
				text_color(ecColor::RED);
				cout << "This is not a text file. Please enter again." << endl;
				text_color(textColor);
				Sleep(500);
			}
		}
		catch (bool fopen) {
			//system("cls");
			goto_xy(distanceFromLeftBorder, middleY + 2);
			if (!fopen) {
				text_color(ecColor::RED);
				cout << "Can't open this file or this path doesn't exist" << endl;
				text_color(textColor);
				Sleep(500);
			}
		}
	}


	f << "RCG09" << endl;
	f << this->CurrentLevel;

	f.close();

	goto_xy(distanceFromLeftBorder, middleY + 2);
	cout << "                                                                          ";

	goto_xy(distanceFromLeftBorder, middleY + 2);
	cout << "Save game successfully. " << endl;
	goto_xy(distanceFromLeftBorder, middleY + 3);
	cout << "Game was saved in: " << path << endl;
	goto_xy(distanceFromLeftBorder, middleY + 4);
	system("pause");

	ShowConsoleCursor(false);
}

void cGame::load_game()
{
	ShowConsoleCursor(true);
	system("cls");

	int middleX = get_console_width() / 2;
	int middleY = get_console_height() / 2;

	int distanceFromLeftBorder = 30;

	ecColor textColor = ecColor::CYAN;

	string path;

	ifstream f;

	while (true) {
		system("cls");
		path.clear();

		try {

			cScreen::draw_load_game();

			text_color(textColor);
			goto_xy(0, middleY);

			cout << "Enter file's path or name (file's type is text file, you can enter 0 to return): ";

			getline(cin, path);
			cin.clear();


			if (path == "0") {
				ShowConsoleCursor(false);
				return;
			}

			if (path == "")
			{
				continue;
			}

			if ((path.length() < 4) || (path[path.length() - 1] != 't') || (path[path.length() - 2] != 'x') || (path[path.length() - 3] != 't') || (path[path.length() - 4] != '.')) {
				throw "!.txt";
			}

			f.open(path);

			if (!f.is_open()) {
				throw false;
			}

			string signature;

			getline(f, signature, '\n');

			if (signature != "RCG09") {
				throw "!signature";
			}

			break;
		}
		catch (const char* msg) {
			path.clear();
			goto_xy(distanceFromLeftBorder, middleY + 2);
			if (msg == "!.txt") {
				text_color(ecColor::RED);
				cout << "This is not saved file's type. Please enter again." << endl;
				text_color(textColor);
				Sleep(500);
			}
			if (msg == "!signature") {
				text_color(ecColor::RED);
				cout << "This is not saved file of this game. Please enter again." << endl;
				text_color(textColor);
				Sleep(500);
			}
		}
		catch (bool fopen) {
			goto_xy(distanceFromLeftBorder, middleY + 2);
			if (!fopen) {
				text_color(ecColor::RED);
				cout << "Can't open this file or this path doesn't exist" << endl;
				text_color(textColor);
				Sleep(500);
			}
		}
	}

	int level; 
	f >> level;
	
	f.close();

	if ((level > 0) && (level <= this->LevelCount))
	{
		this->CurrentLevel = level;
	}
	
	cGame* game = cGame::get_instance();
	game->loading();

	ShowConsoleCursor(false);
}

void cGame::give_up()
{
	this->State = ecState::DEFEAT;
}

void cGame::loading()
{
	this->State = ecState::LOADING;
}

bool cGame::state_is_loading()
{
	return (this->State == ecState::LOADING);
}

bool cGame::state_is_defeat() {
	return (this->State == ecState::DEFEAT);
}

void cGame::new_game()
{
	this->CurrentLevel = 1;
	this->play();
}

void cGame::playing()
{
	this->State = ecState::PLAYING;
}