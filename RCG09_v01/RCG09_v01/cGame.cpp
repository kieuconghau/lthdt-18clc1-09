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
	const int laneCounts[cGame::LevelCount] = { 7, 9 };
	const int leftLimit = cSetting::Game::LEFT_LIMIT + 1;
	const int rightLimit = cSetting::Game::RIGHT_LIMIT - 1;

	/* Level 1 */
	int timeAlotted0 = 25;//second... kind of
	int finishLine0 = cSetting::Game::TOP_LIMIT + 1;
	int maxCoin0 = 1; // must be equal to the number of level's coins;
	vector<cObject::ecType> objectTypes0 =	{ cObject::ecType::MV_CAR			, cObject::ecType::MF_WOOD		, cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MV_TRUCK		, cObject::ecType::MF_WOOD			, cObject::ecType::MF_WOOD		, cObject::ecType::MV_CAR	};
	vector<ecDirection> directions0 =		{ ecDirection::RIGHT				, ecDirection::LEFT				, ecDirection::RIGHT					, ecDirection::RIGHT			, ecDirection::LEFT					, ecDirection::RIGHT			, ecDirection::LEFT					};
	vector<ecColor> colors0 =				{ ecColor::CYAN						, ecColor::LIGHT_BLUE			, ecColor::GREY							, ecColor::RED					, ecColor::LIGHT_BLUE				, ecColor::LIGHT_BLUE			, ecColor::CYAN							};
	vector<int> objectCounts0 =				{ 5									, 9								, 30									, 6								, 8									, 9								, 5									};
	vector<vector<int>> times0 =			{ {15, 0, 45}						, {0, 0, 1}						, {0, 0, 0}								, {15, 0, 55}					, {0, 0, 1}							, {0, 0, 1}						, {7, 0, 35}								};
	vector<int> steps0 =					{ 1									, 1								, 0										, 1								, 1									, 1								, 1										};
	vector<int> crazySteps0 =				{ 0									, 0								, 0										, 0								, 0									, 0								, 0										};
	this->Levels[0].set_up(1, laneCounts[0], finishLine0, maxCoin0, timeAlotted0, objectTypes0, directions0, colors0, objectCounts0, times0, steps0, crazySteps0, leftLimit, rightLimit);

	/* Level 2 */
	int timeAlotted1 = 45;//second... kind of
	int finishLine1 = cSetting::Game::TOP_LIMIT + 1;
	int maxCoin1 = 2; // must be equal to the number of level's coins;
	vector<cObject::ecType> objectTypes1 =		{ cObject::ecType::MV_TRAIN			, cObject::ecType::MV_CAR		, cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MA_DINOSAUR	, cObject::ecType::MF_WOOD			, cObject::ecType::MV_TRUCK		, cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MA_BIRD	, cObject::ecType::MV_CAR };
	vector<ecDirection> directions1 =			{ ecDirection::RIGHT				, ecDirection::LEFT				, ecDirection::RIGHT					, ecDirection::RIGHT			, ecDirection::LEFT					, ecDirection::RIGHT			, ecDirection::RIGHT					, ecDirection::LEFT			, ecDirection::RIGHT };
	vector<ecColor> colors1 =					{ ecColor::PURPLE					, ecColor::CYAN					, ecColor::GREY							, ecColor::YELLOW				, ecColor::LIGHT_BLUE				, ecColor::RED					, ecColor::GREY							, ecColor::PURPLE			, ecColor::CYAN };
	vector<int> objectCounts1 =					{ 1									, 6								, 25									, 5								, 7									, 5								, 26									, 5							, 7 };
	vector<vector<int>> times1 =				{ {0, 0, 1}							, {9, 0, 50}					, {0, 0, 1}								, {0, 10, 45}					, {0, 0, 1}							, {15, 20, 40}					, {0, 0, 1}								, {0, 0, 1}					, {10, 30, 20} };
	vector<int> steps1 =						{ 9									, 1								, 0										, 1								, 1									, 1								, 1										, 1							, 1 };
	vector<int> crazySteps1 =					{ 0									, 1								, 0										, 0								, 1									, 1								, 0										, 1							, 2 };
	this->Levels[1].set_up(2, laneCounts[1], finishLine1, maxCoin1, timeAlotted1, objectTypes1, directions1, colors1, objectCounts1, times1, steps1, crazySteps1, leftLimit, rightLimit);


	///* Level 2 */
	//int timeAlotted1 = 30;//second... kind of
	//int finishLine1 = cSetting::Game::TOP_LIMIT + 1;
	//int maxCoin1 = 2; // must be equal to the number of level's coins;
	//vector<cObject::ecType> objectTypes1 =	{ cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MV_CAR	, cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MF_WOOD	, cObject::ecType::MA_BIRD		, cObject::ecType::MV_TRAIN	, cObject::ecType::MF_WOOD	};
	//vector<ecDirection> directions1 =		{ ecDirection::RIGHT					, ecDirection::LEFT			, ecDirection::RIGHT					, ecDirection::RIGHT		, ecDirection::LEFT				, ecDirection::RIGHT		, ecDirection::LEFT			};
	//vector<ecColor> colors1 =				{ ecColor::GREY							, ecColor::PURPLE			, ecColor::GREY							, ecColor::BLUE				, ecColor::LIGHT_GREEN			, ecColor::CYAN				, ecColor::BLUE };
	//vector<int> objectCounts1 =				{ 25									, 4							, 30									, 9							, 6								, 1							, 6 };
	//vector<vector<int>> times1 =			{ {0, 0, 0}								, {7, 5, 10}				, {0, 0, 0}								, {0, 0, 0}				    , {0, 5, 15}					, {0, 0, 0}					, {0, 0, 0} };
	//vector<int> steps1 =					{ 2										, 1							, 1										, 1							, 1								, 9							, 1 };
	//vector<int> crazySteps1 =				{ 0										, 2							, 0										, 0							, 1								, 0							, 0	};
	//this->Levels[1].set_up(2, laneCounts[1], finishLine1, maxCoin1, timeAlotted1, objectTypes1, directions1, colors1, objectCounts1, times1, steps1, crazySteps1, leftLimit, rightLimit);

	///* Level 3 */
	//int timeAlotted2 = 30;//second... kind of
	//int finishLine2 = cSetting::Game::TOP_LIMIT + 1;
	//int maxCoin2 = 2; // must be equal to the number of level's coins;
	//vector<cObject::ecType> objectTypes2 =	{ cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MV_CAR	, cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MF_WOOD	, cObject::ecType::MA_BIRD		, cObject::ecType::MV_TRAIN	, cObject::ecType::MF_WOOD };
	//vector<ecDirection> directions2 =		{ ecDirection::RIGHT					, ecDirection::LEFT			, ecDirection::RIGHT					, ecDirection::RIGHT		, ecDirection::LEFT				, ecDirection::RIGHT		, ecDirection::LEFT };
	//vector<ecColor> colors2 =				{ ecColor::GREY							, ecColor::PURPLE			, ecColor::GREY							, ecColor::BLUE				, ecColor::LIGHT_GREEN			, ecColor::CYAN				, ecColor::BLUE };
	//vector<int> objectCounts2 =				{ 25									, 4							, 30									, 9							, 6								, 1							, 6 };
	//vector<vector<int>> times2 =			{ {0, 0, 0}								, {7, 5, 10}				, {0, 0, 0}								, {0, 0, 0}				    , {0, 5, 15}					, {0, 0, 0}					, {0, 0, 0} };
	//vector<int> steps2 =					{ 2										, 1							, 1										, 1							, 1								, 9							, 1 };
	//vector<int> crazySteps2 =				{ 0										, 2							, 0										, 0							, 1								, 0							, 0 };
	//this->Levels[2].set_up(3, laneCounts[2], finishLine2, maxCoin2, timeAlotted2, objectTypes2, directions2, colors2, objectCounts2, times2, steps2, crazySteps2, leftLimit, rightLimit);

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