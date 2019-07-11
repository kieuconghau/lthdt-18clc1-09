#include "cLevel.h"

cLevel::cLevel()
{
	this->LaneCount = 0;
	this->Lanes = nullptr;
	this->People = cPeople::get_instance();
	this->State = cLevel::ecState::PLAYING;
}

cLevel::~cLevel()
{
	for (int i = 0; i < this->LaneCount; i++)
		delete this->Lanes[i];

	delete[] this->Lanes;
}

void cLevel::draw()
{
	text_color(cSetting::Game::BORDER_COLOR);

	goto_xy(cSetting::Game::LEFT_LIMIT, cSetting::Game::TOP_LIMIT);
	cout << char(201);
	for (int i = 0; i < cSetting::Game::RIGHT_LIMIT - cSetting::Game::LEFT_LIMIT - 1; i++)
		cout << char(205);
	cout << char(187);

	for (int i = 0; i < cSetting::Game::BOT_LIMIT - cSetting::Game::TOP_LIMIT - 1; i++)
	{
		goto_xy(cSetting::Game::LEFT_LIMIT, i + cSetting::Game::TOP_LIMIT + 1);
		cout << char(186);
		goto_xy(cSetting::Game::RIGHT_LIMIT, i + cSetting::Game::TOP_LIMIT + 1);
		cout << char(186);
	}

	goto_xy(cSetting::Game::LEFT_LIMIT, cSetting::Game::BOT_LIMIT);
	cout << char(200);
	for (int i = 0; i < cSetting::Game::RIGHT_LIMIT - cSetting::Game::LEFT_LIMIT - 1; i++)
		cout << char(205);
	cout << char(188);

	text_color();
	goto_xy(0, 0);
}

void cLevel::play()
{
	// Draw border
	this->draw();

	// Set starting position for people
	this->People->set_starting_pos((cSetting::Game::RIGHT_LIMIT + cSetting::Game::LEFT_LIMIT)/2, cSetting::Game::BOT_LIMIT - 2);

	// Play
	while (true)
	{
		// Update people's position
		this->People->move(cSetting::Game::LEFT_LIMIT + 1, cSetting::Game::RIGHT_LIMIT - 1
			, cSetting::Game::TOP_LIMIT + 1, cSetting::Game::BOT_LIMIT - 1);

		// Check if people impact on objects
		if (!People->stand_still())
		{
			for (int i = 0; i < this->LaneCount; ++i)
			{
				this->Lanes[i]->impact(this->People);	// Polymorphism
			}

			// Draw people at updated position
			this->People->update_pos();

			if (this->People->is_dead())
				break;
		}

		// Objects move
		for (int i = 0; i < this->LaneCount; i++)
		{
			if (this->Lanes[i]->has_people(this->People))
			{
				//this->Lanes[i]->
			}
			else
			{
				this->Lanes[i]->work();
			}
		}

		Sleep(50);
		if (GetAsyncKeyState(VK_RETURN))
			break;
	}
}

void cLevel::set_up(int laneCount, vector<cObject::ecType> objectTypes, vector<ecDirection> directions, vector<ecColor> objectColors
	, vector<int> objectCounts, vector<vector<int>> times, vector<int> steps, int leftLimit, int rightLimit)
{
	for (int i = 0; i < this->LaneCount; i++)
		delete this->Lanes[i];
	delete[] this->Lanes;

	this->LaneCount = laneCount;
	this->State = cLevel::ecState::PLAYING;
	this->People = cPeople::get_instance();

	this->Lanes = new cLane * [this->LaneCount];
	for (int i = 0; i < this->LaneCount; i++)
	{
		this->Lanes[i] = cLaneFactory::create(objectTypes[i], directions[i], objectColors[i], objectCounts[i], cSetting::Game::TOP_LIMIT + 2 + 2*i, times[i], steps[i], leftLimit, rightLimit);	// Testing
		//this->Lanes[i] = cLaneFactory::create(objectTypes[i], directions[i], objectColors[i], objectCounts[i], cSetting::Game::TOP_LIMIT + 2 + i, times[i], steps[i], leftLimit, rightLimit);	// Official
	}
}




