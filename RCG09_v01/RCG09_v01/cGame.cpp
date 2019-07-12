#include "cGame.h"


cGame* cGame::Instance = nullptr;

const int cGame::LevelCount = 1;


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
	const int laneCounts[cGame::LevelCount] = { 5 };
	const int leftLimit = cSetting::Game::LEFT_LIMIT + 1;
	const int rightLimit = cSetting::Game::RIGHT_LIMIT - 1;

	/* Level 1 */
	vector<cObject::ecType> objectTypes0 =	{ cObject::ecType::MA_DINOSAUR	, cObject::ecType::MV_CAR	, cObject::ecType::MV_TRUCK	, cObject::ecType::MV_CAR	, cObject::ecType::MA_BIRD		};
	vector<ecDirection> directions0 =		{ ecDirection::RIGHT			, ecDirection::LEFT			, ecDirection::RIGHT		, ecDirection::LEFT			, ecDirection::RIGHT			};
	vector<ecColor> colors0 =				{ ecColor::BLUE					, ecColor::RED				, ecColor::CYAN				, ecColor::GREEN			, ecColor::YELLOW				};
	vector<int> objectCounts0 =				{ 7								, 4							, 5							, 3							, 5								};
	vector<vector<int>> times0 =			{ {10, 5, 20}                   , {7, 5, 10}				, {5, 5, 10}                , {15, 3, 20}               , {5, 5, 15}					};
	vector<int> steps0 =					{ 2								, 1							, 1							, 3							, 1								};
	this->Levels[0].set_up(laneCounts[0], objectTypes0, directions0, colors0, objectCounts0, times0, steps0, leftLimit, rightLimit);
}

cGame::~cGame()
{
	delete[] this->Levels;

	delete cGame::Instance;
}

void cGame::play()
{
	this->Levels[0].play();
}
