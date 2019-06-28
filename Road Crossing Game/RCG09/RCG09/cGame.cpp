#include "cGame.h"

cGame::cGame()
{
	this->CurrentLevel = 0;

	/* Set up information for each level */
	const unsigned int laneCount[cGame::MAX_LEVEL] = { 4, 5 };

	/* Level 0 */
	vector<ecObjectType> objectTypes0 =		{ ecObjectType::CAR		, ecObjectType::TRUCK	, ecObjectType::CAR		, ecObjectType::TRUCK	};
	vector<ecDirection> directions0 =		{ ecDirection::RIGHT	, ecDirection::LEFT		, ecDirection::RIGHT	, ecDirection::LEFT		};
	vector<ecColor> colors0 =				{ ecColor::PURPLE		, ecColor::BLUE			, ecColor::CYAN			, ecColor::YELLOW		};
	vector<unsigned int> objectCounts0 =	{ 3						, 4						, 5						, 6						};
	unsigned int timeRed0 = 20;
	unsigned int timeYellow0 = 10;
	unsigned int timeGreen0 = 20;
	this->Levels[0].set_up(laneCount[0], objectTypes0, directions0, colors0, objectCounts0, timeRed0, timeYellow0, timeGreen0);

	/* Level 1 */
	vector<ecObjectType> objectTypes1 =		{ ecObjectType::TRUCK	, ecObjectType::CAR		, ecObjectType::BIRD	, ecObjectType::DINOSAUR, ecObjectType::TRUCK	};
	vector<ecDirection> directions1 =		{ ecDirection::RIGHT	, ecDirection::LEFT		, ecDirection::RIGHT	, ecDirection::LEFT		, ecDirection::RIGHT	};
	vector<ecColor> colors1 =				{ ecColor::RED			, ecColor::CYAN			, ecColor::BLUE			, ecColor::GREEN		, ecColor::WHITE		};
	vector<unsigned int> objectCounts1 =	{ 3						, 4						, 5						, 6						, 4						};
	unsigned int timeRed1 = 15;
	unsigned int timeYellow1 = 10;
	unsigned int timeGreen1 = 20;
	this->Levels[1].set_up(laneCount[1], objectTypes1, directions1, colors1, objectCounts1, timeRed1, timeYellow1, timeGreen1);
}

cGame::~cGame()
{
}

void cGame::draw()
{
}

void cGame::start()
{
	this->Levels[this->CurrentLevel].start();

	system("cls");
	this->CurrentLevel++;		// Level up
	this->Levels[this->CurrentLevel].start();
}