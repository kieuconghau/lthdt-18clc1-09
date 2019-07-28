#pragma once

#include "cSetting.h"
#include "cScreen.h"
#include "cLevel.h"
#include <fstream>

using namespace std;

class cGame
{
public:
	enum class ecState
	{
		PLAYING,
		VICTORY,
		DEFEAT,
		LOADING
	};

public:
	static cGame* get_instance();

public:
	cGame();
	~cGame();


public:
	void play();
	void save_game();
	void load_game();

	void give_up();
	void loading();
	void playing();

	bool state_is_loading();
	bool state_is_defeat();
	
	void new_game();

private:
	static cGame* Instance;
	static const int LevelCount;

private:
	cLevel* Levels;
	int CurrentLevel;
	cGame::ecState State;
};

