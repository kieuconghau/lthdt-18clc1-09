#include "cLevel.h"
#include <thread>

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
	/* Draw borders */
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


	/* Draw lanes */
	for (int i = 0; i < this->LaneCount; i++)
	{
		this->Lanes[i]->draw();
	}


	/*  */

	text_color();
	goto_xy(0, 0);
}

void cLevel::play()
{
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

			// Get brick shape and color of current lane
			int count = 0;
			for (count = 0; count < this->LaneCount; ++count)
			{
				if (this->Lanes[count]->has_people(this->People))
				{
					this->Lanes[count]->change_people_brick(this->People);
					break;
				}
			}
			if (count == this->LaneCount)
			{
				People->change_brick(char(219), ecColor::BLACK);
			}

			if (this->People->is_dead())
			{
				this->People->draw();
				break;
			}
		}

		// Objects move
		for (int i = 0; i < this->LaneCount; i++)
		{
			this->Lanes[i]->impact(this->People);

			if (this->People->is_dead())
			{
				this->People->draw();
				break;
			}
			else
			{
				this->Lanes[i]->work();
			}
		}

		//Hot keys		
		int flag = 0;
		if ((GetAsyncKeyState(0x50)&0x8000)&&(flag==0))
		{
			flag = 1;
			thread P(cScreen::screen_pause_game);
			P.join();
			system("cls");
			this->draw();
			this->People->draw();
		}
		if ((GetAsyncKeyState(0x53) & 0x8000) && (flag == 0))
		{
			flag = 1;
			thread S(cScreen::screen_save_game);
			if(GetAsyncKeyState(0x53))
			S.join();
			system("cls");
			this->draw();
			this->People->draw();			
		}	
		if ((GetAsyncKeyState(0x4C) & 0x8000) && (flag == 0))
		{
			flag = 1;
			thread L(cScreen::screen_load_mid_game);
			L.join();
			system("cls");
			this->draw();
			this->People->draw();
		}
		if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) && (flag == 0))
		{
			flag = 1;
			thread Esc(cScreen::screen_escape);
			Esc.join();
			system("cls");
			this->draw();
			this->People->draw();
		}

		if (this->People->is_dead())
		{
			this->People->draw();
			break;
		}

		Sleep(50);
		this->TimeAlotted -= 75;

		if (this->TimeAlotted <= 0)
		{
			break;
		}
	}
}

void cLevel::set_up(int laneCount,int timeAlotted, vector<cObject::ecType> objectTypes, vector<ecDirection> directions, vector<ecColor> objectColors
	, vector<int> objectCounts, vector<vector<int>> times, vector<int> steps, int leftLimit, int rightLimit)
{
	for (int i = 0; i < this->LaneCount; i++)
		delete this->Lanes[i];
	delete[] this->Lanes;

	this->LaneCount = laneCount;
	this->TimeAlotted = timeAlotted*1000;
	this->State = cLevel::ecState::PLAYING;
	this->People = cPeople::get_instance();

	this->Lanes = new cLane * [this->LaneCount];
	for (int i = 0; i < this->LaneCount; i++)
	{
		this->Lanes[i] = cLaneFactory::create(objectTypes[i], directions[i], objectColors[i]
			, objectCounts[i], cSetting::Game::TOP_LIMIT + 2 + i, times[i], steps[i], leftLimit, rightLimit);
	}
}

