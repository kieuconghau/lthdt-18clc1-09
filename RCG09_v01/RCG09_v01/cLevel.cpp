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

void cLevel::pause()
{
	//Pause game()
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " ____   ____  __ __  _____   ___ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 14, "|    \\ /    ||  |  |/ ___/  /  _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 13, "|  o  )  o  ||  |  (   \\_  /  [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 12, "|   _/|     ||  |  |\\__  ||    _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 11, "|  |  |  _  ||  :  |/  \\ ||   [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 10, "|  |  |  |  ||     |\\    ||     |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 9, "|__|  |__|__| \\__,_| \\___||_____|", ecColor::BLUE, true);

	system("pause");
	system("cls");
	this->draw();
}

void cLevel::load()
{
	//Load Game
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, " _       ___    ____  ___         ____   ____  ___ ___    ___ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 14, "| |     /   \\  /    ||   \\       /    | /    ||   |   |  /  _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 13, "| |    |     ||  o  ||    \\     |   __||  o  || _   _ | /  [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 12, "| |___ |  O  ||     ||  D  |    |  |  ||     ||  \\_/  ||    _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 11, "|     ||     ||  _  ||     |    |  |_ ||  _  ||   |   ||   [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 10, "|     ||     ||  |  ||     |    |     ||  |  ||   |   ||     |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 9, "|_____| \\___/ |__|__||_____|    |___,_||__|__||___|___||_____|", ecColor::BLUE, true);

	system("pause");
	system("cls");
	this->draw();
}

void cLevel::save()
{
	//Save Game
	system("cls");

	unsigned middleX = get_console_width() / 2;
	unsigned middleY = get_console_height() / 2;

	print_text_at_middle(middleY - 15, "   _____  ____  __ __    ___       ____   ____  ___ ___    ___", ecColor::BLUE, true);
	print_text_at_middle(middleY - 14, "  / ___/ /    ||  |  |  /  _]     /    | /    ||   |   |  /  _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 13, " (   \\_ |  o  ||  |  | /  [_     |   __||  o  || _   _ | /  [_ ", ecColor::BLUE, true);
	print_text_at_middle(middleY - 12, "  \\__  ||     ||  |  ||    _]    |  |  ||     ||  \\_/  ||    _]", ecColor::BLUE, true);
	print_text_at_middle(middleY - 11, " /  \\ ||  _  ||  :  ||   [_     |  |_ ||  _  ||   |   ||   [_", ecColor::BLUE, true);
	print_text_at_middle(middleY - 10, "  \\    ||  |  | \\   / |     |    |     ||  |  ||   |   ||     |", ecColor::BLUE, true);
	print_text_at_middle(middleY - 9, "   \\___||__|__|  \\_/  |_____|    |___,_||__|__||___|___||_____|", ecColor::BLUE, true);

	system("pause");
	system("cls");
	this->draw();
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
		if (GetAsyncKeyState(0x50))
		{
			thread P(&cLevel::pause, this);
			P.join();
		}
		if (GetAsyncKeyState(0x35)) // "5" key, 'cause "S" conflict with movement key :v
		{
			thread S(&cLevel::save, this);
			S.join();
		}
		if (GetAsyncKeyState(0x4C))
		{
			thread L(&cLevel::load, this);
			L.join();
		if (this->People->is_dead())
		{
			this->People->draw();
			break;
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
		this->Lanes[i] = cLaneFactory::create(objectTypes[i], directions[i], objectColors[i]
			, objectCounts[i], cSetting::Game::TOP_LIMIT + 2 + i, times[i], steps[i], leftLimit, rightLimit);
	}
}

