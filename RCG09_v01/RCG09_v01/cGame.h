#pragma once

#include "cSetting.h"
#include "cScreen.h"
#include "cLevel.h"

class cGame
{
public:
	enum class ecState
	{
		PLAYING,
		VICTORY,
		DEFEAT
	};

public:
	static cGame* get_instance();

public:
	cGame();
	~cGame();

public:
	void play();

private:
	static cGame* Instance;
	static const int LevelCount;

private:
	cLevel* Levels;
	int CurrentLevel;
	cGame::ecState State;
};

