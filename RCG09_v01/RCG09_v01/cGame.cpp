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
	const int laneCounts[cGame::LevelCount] = { 6 };
	const int leftLimit = cSetting::Game::LEFT_LIMIT + 1;
	const int rightLimit = cSetting::Game::RIGHT_LIMIT - 1;

	/* Level 1 */
	int timeAlotted0 =						60;//second... kind of
	vector<cObject::ecType> objectTypes0 =	{ cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MV_CAR	, cObject::ecType::MIX_STONE_AND_COIN	, cObject::ecType::MF_WOOD	, cObject::ecType::MA_BIRD		, cObject::ecType::MV_TRAIN };
	vector<ecDirection> directions0 =		{ ecDirection::RIGHT					, ecDirection::LEFT			, ecDirection::RIGHT					, ecDirection::RIGHT		, ecDirection::LEFT				, ecDirection::RIGHT		};
	vector<ecColor> colors0 =				{ ecColor::GREY							, ecColor::PURPLE			, ecColor::GREY							, ecColor::BLUE				, ecColor::LIGHT_GREEN			, ecColor::CYAN				};
	vector<int> objectCounts0 =				{ 25									, 4							, 30									, 9							, 6								, 1							};
	vector<vector<int>> times0 =			{ {0, 0, 0}								, {7, 5, 10}				, {0, 0, 0}								, {0, 0, 0}				    , {5, 5, 15}					, {0, 0, 0}					};
	vector<int> steps0 =					{ 2										, 1							, 1										, 1							, 1								, 9							};
	this->Levels[0].set_up(laneCounts[0],timeAlotted0, objectTypes0, directions0, colors0, objectCounts0, times0, steps0, leftLimit, rightLimit);
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
