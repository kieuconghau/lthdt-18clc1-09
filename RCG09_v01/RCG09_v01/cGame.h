#pragma once

#include "cSetting.h"
#include "cScreen.h"
#include "cLevel.h"

class cGame
{
public:
	cGame();
	~cGame();

	void play();

private:
	static const int LevelCount;
	cLevel* Levels;
	int CurrentLevel;
};

