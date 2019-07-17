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
	void set_up(int laneCount, vector<cObject::ecType> objectTypes, vector<ecDirection> directions, vector<ecColor> objectColors
		, vector<int> objectCounts, vector<vector<int>> times, vector<int> steps, int leftLimit, int rightLimit);

private:
	int LaneCount;
	cLane** Lanes;
	cPeople* People;
	cLevel::ecState State;
	void draw();
};