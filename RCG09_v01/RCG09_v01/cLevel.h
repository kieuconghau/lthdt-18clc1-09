#pragma once

#include "cScreen.h"
#include "cSetting.h"
#include "cPeople.h"
#include "cLaneFactory.h"

class cLevel
{
public:
	enum class ecState : char
	{
		PLAYING,
		DEFEAT,
		VICTORY
	};
	cLevel();
	~cLevel();

	void play();
	void set_up(int laneCount,int timeAlotted,int maxCoin, int finishLine, vector<cObject::ecType> objectTypes, vector<ecDirection> directions, vector<ecColor> objectColors
		, vector<int> objectCounts, vector<vector<int>> times, vector<int> steps, int leftLimit, int rightLimit);

	bool win(cPeople* people);
	bool lose(cPeople* people);


private:
	int FinishLine;
	int FinishBlock;
	int LaneCount;
	int MaxCoin;
	int CurrentCoin;
	int TimeAlotted;
	cLane** Lanes;
	cPeople* People;
	cLevel::ecState State;
	void draw();
	void draw_finish_block();
	void destroy_finish_block();
	int unblockCount;
};