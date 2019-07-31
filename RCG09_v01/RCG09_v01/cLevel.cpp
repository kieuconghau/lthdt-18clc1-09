#include "cLevel.h"
#include <thread>
#include "cGame.h"

cLevel::cLevel()
{
	this->LaneCount = 0;
	this->Lanes = nullptr;
	this->People = cPeople::get_instance();
	this->State = cLevel::ecState::PLAYING;
	this->TimeAlotted = 0;
	this->CurrentCoin = 0;
	this->FinishBlock = 0;
	this->FinishLine = 0;
	this->MaxCoin = 0;
	this->TimeCount = 0;
	this->UnblockCount = 0;
	this->Level = 0;
}

cLevel::~cLevel()
{
	for (int i = 0; i < this->LaneCount; i++)
		delete this->Lanes[i];

	delete[] this->Lanes;
}


void cLevel::draw()
{
	/* Draw game's borders */
	text_color(cSetting::Game::BORDER_COLOR);

	goto_xy(cSetting::Game::LEFT_LIMIT, cSetting::Game::TOP_LIMIT_1);
	cout << char(201);
	for (int i = 0; i < cSetting::Game::RIGHT_LIMIT - cSetting::Game::LEFT_LIMIT - 1; i++)
		cout << char(205);
	cout << char(187);

	for (int i = 0; i < cSetting::Game::BOT_LIMIT - cSetting::Game::TOP_LIMIT_1 - 1; i++)
	{
		goto_xy(cSetting::Game::LEFT_LIMIT, i + cSetting::Game::TOP_LIMIT_1 + 1);
		cout << char(186);
		goto_xy(cSetting::Game::RIGHT_LIMIT, i + cSetting::Game::TOP_LIMIT_1 + 1);
		cout << char(186);
	}

	goto_xy(cSetting::Game::LEFT_LIMIT, cSetting::Game::BOT_LIMIT);
	cout << char(200);
	for (int i = 0; i < cSetting::Game::RIGHT_LIMIT - cSetting::Game::LEFT_LIMIT - 1; i++)
		cout << char(205);
	cout << char(188);

	goto_xy(cSetting::Game::LEFT_LIMIT, cSetting::Game::TOP_LIMIT);
	cout << char(204);
	for (int i = 0; i < cSetting::Game::RIGHT_LIMIT - cSetting::Game::LEFT_LIMIT - 1; i++)
		cout << char(205);
	cout << char(185);

	goto_xy(cSetting::Game::LEFT_LIMIT_1, cSetting::Game::TOP_LIMIT_1);
	cout << char(203);
	for (int y = cSetting::Game::TOP_LIMIT_1 + 1; y < cSetting::Game::TOP_LIMIT; y++)
	{
		goto_xy(cSetting::Game::LEFT_LIMIT_1, y);
		cout << char(186);
	}
	goto_xy(cSetting::Game::LEFT_LIMIT_1, cSetting::Game::TOP_LIMIT);
	cout << char(202);

	/* Draw lanes */
	for (int i = 0; i < this->LaneCount; i++)
	{
		this->Lanes[i]->draw();
	}


	/* Draw finish line  */
	ecColor flFirstColor = ecColor::WHITE;
	ecColor flSecondColor = ecColor::WHITE;
	for (int i = cSetting::Game::LEFT_LIMIT + 1; i <= cSetting::Game::RIGHT_LIMIT - 1; i++) {
		if (i % 2 == 0) {
			text_color(flFirstColor);
			goto_xy(i, FinishLine);
			cout << char(220);
		}
		if (i % 2 == 1) {

			text_color(flSecondColor);
			goto_xy(i, FinishLine);
			cout << char(223);
		}
	}


	/* Draw finishing block */
	this->draw_finish_block();


	/* Draw current level */
	goto_xy(cSetting::Game::LEFT_LIMIT + 2, cSetting::Game::TOP_LIMIT_1 + 1);
	text_color(ecColor::CYAN);
	cout << "LEVEL " << this->Level;

	text_color();
	goto_xy(0, 0);
}

//void cLevel::play()
//{
//	system("cls");
//
//	//used only for knowing game's current state
//	cGame* gameStateOnly = cGame::get_instance();
//
//	this->reset();
//
//	this->State = ecState::PLAYING;
//
//	this->draw();
//
//	// Set starting position for people
//	this->People->set_starting_pos((cSetting::Game::RIGHT_LIMIT + cSetting::Game::LEFT_LIMIT)/2, cSetting::Game::BOT_LIMIT - 2);
//
//	int topLimit = this->FinishBlock + 1;
//	// Play
//	while (true)
//	{
//		// Update people's position
//		this->People->move(cSetting::Game::LEFT_LIMIT + 1, cSetting::Game::RIGHT_LIMIT - 1
//			, topLimit , cSetting::Game::BOT_LIMIT - 1);
//
//		// Check if people impact on objects
//		if (!People->stand_still())
//		{
//			for (int i = 0; i < this->LaneCount; ++i)
//			{
//				this->CurrentCoin += this->Lanes[i]->impact(this->People);	// Polymorphism
//			}
//
//			// Draw people at updated position
//			this->People->update_pos();
//
//			// Get brick shape and color of current lane
//			int count = 0;
//			for (count = 0; count < this->LaneCount; ++count)
//			{
//				if (this->Lanes[count]->has_people(this->People))
//				{
//					this->Lanes[count]->change_people_brick(this->People);
//					break;
//				}
//			}
//			if (count == this->LaneCount)
//			{
//				People->change_brick(char(219), ecColor::BLACK);
//			}
//
//			if (this->lose(People)) {
//				People->losing_effect();
//				cScreen::screen_game_over();
//				break;
//			}
//
//			if ((this->CurrentCoin == this->MaxCoin) && (UnblockCount == 0)) {
//				UnblockCount++;
//				this->destroy_finish_block();
//				topLimit = FinishLine - 1;
//			}
//
//			if (this->win(People)) {
//				People->winning_effect();
//				cScreen::screen_win();
//				break;
//			}
//		}
//
//		// Objects move
//		for (int i = 0; i < this->LaneCount; i++)
//		{
//			this->CurrentCoin += this->Lanes[i]->impact(this->People);
//
//			if (this->People->is_dead())
//			{
//				this->People->draw();
//				break;
//			}
//			else
//			{
//				this->Lanes[i]->work();
//			}
//		}
//
//		//Hot keys		
//		int flag = 0;
//		if ((GetAsyncKeyState(0x50) & 0x8000) && (flag == 0))
//		{
//			flag = 1;
//			thread P(cScreen::screen_pause_game);
//			P.join();
//			system("cls");
//			this->draw();
//			this->People->draw();
//		}
//		if ((GetAsyncKeyState(0x53) & 0x8000) && (flag == 0))
//		{
//			flag = 1;
//			thread S(cScreen::screen_save_game);
//			if(GetAsyncKeyState(0x53))
//			S.join();
//			system("cls");
//			this->draw();
//			this->People->draw();			
//		}	
//		if ((GetAsyncKeyState(0x4C) & 0x8000) && (flag == 0))
//		{
//			flag = 1;
//			thread L(cScreen::screen_load_mid_game);
//			L.join();
//			system("cls");
//			
//			if (gameStateOnly->state_is_loading()) {
//				break;
//			}
//
//			this->draw();
//			this->People->draw();
//		}
//		if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) && (flag == 0))
//		{
//			flag = 1;
//			thread Esc(cScreen::screen_escape);
//			Esc.join();
//
//			system("cls");
//
//			if (gameStateOnly->state_is_loading()) {
//				break;
//			}
//
//			if (gameStateOnly->state_is_defeat()) {
//				break;
//			}
//
//			this->draw();
//			this->People->draw();
//		}
//
//
//		Sleep(50);
//		this->TimeCount -= 75;
//
//		if (this->lose(People)) {
//			People->losing_effect();
//			cScreen::screen_game_over();
//			break;
//		}
//
//		if ((this->CurrentCoin == this->MaxCoin) && (UnblockCount == 0)) {
//			UnblockCount++;
//			this->destroy_finish_block();
//			topLimit = FinishLine - 1;
//		}
//
//		if (this->win(People)) {
//			People->winning_effect();
//			cScreen::screen_win();
//			break;
//		}
//	}
//}

void cLevel::play()
{
	system("cls");

	//used only for knowing game's current state
	cGame* gameStateOnly = cGame::get_instance();

	this->reset();

	this->State = ecState::PLAYING;

	this->draw();

	// Set starting position for people
	this->People->set_starting_pos((cSetting::Game::RIGHT_LIMIT + cSetting::Game::LEFT_LIMIT) / 2, cSetting::Game::BOT_LIMIT - 2);

	int topLimit = this->FinishBlock + 1;
	
	// Play
	while (true)
	{
		// People move
		this->People->move(cSetting::Game::LEFT_LIMIT + 1, cSetting::Game::RIGHT_LIMIT - 1, topLimit, cSetting::Game::BOT_LIMIT - 1);

		// Update people
		if (!People->stand_still())
		{
			// Check impact
			for (int i = 0; i < this->LaneCount; ++i)
			{
				this->CurrentCoin += this->Lanes[i]->impact(this->People);	// Polymorphism
			}

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

			// Check lose
			if (this->lose(People))
			{
				People->losing_effect();
				cScreen::screen_game_over();
				break;
			}

			// Check block
			if ((this->CurrentCoin == this->MaxCoin) && (UnblockCount == 0))
			{
				UnblockCount++;
				this->destroy_finish_block();
				topLimit = FinishLine - 1;
			}

			// Check win
			if (this->win(People))
			{
				People->winning_effect();
				cScreen::screen_win();
				break;
			}
		}

		// Objects move
		for (int i = 0; i < this->LaneCount; i++)
		{
			this->Lanes[i]->work(this->People);

			this->CurrentCoin += this->Lanes[i]->impact(this->People);

			if (this->People->is_dead())
			{
				this->People->draw();
				break;
			}
		}

		//Hot keys		
		int flag = 0;
		if ((GetAsyncKeyState(0x50) & 0x8000) && (flag == 0))
		{
			char temp;
			while (true)
			{
				temp = _getch();
				if (temp == 'p' || temp == 'P')
					break;
			}

			flag = 1;
			thread P(cScreen::screen_pause_game);
			P.join();
			system("cls");
			this->draw();
			this->People->draw();
		}
		if ((GetAsyncKeyState(0x53) & 0x8000) && (flag == 0))
		{
			char temp;
			while (true)
			{
				temp = _getch();
				if (temp == 's' || temp == 'S')
					break;
			}

			flag = 1;
			thread S(cScreen::screen_save_game);
			/*if (GetAsyncKeyState(0x53) & 0x8000)
				S.join();*/
			S.join();
			system("cls");
			this->draw();
			this->People->draw();
		}
		if ((GetAsyncKeyState(0x4C) & 0x8000) && (flag == 0))
		{
			char temp;
			while (true)
			{
				temp = _getch();
				if (temp == 'l' || temp == 'L')
					break;
			}

			flag = 1;
			thread L(cScreen::screen_load_mid_game);
			L.join();
			system("cls");

			if (gameStateOnly->state_is_loading()) {
				break;
			}

			this->draw();
			this->People->draw();
		}
		if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000) && (flag == 0))
		{
			flag = 1;
			thread Esc(cScreen::screen_escape);
			Esc.join();

			system("cls");

			if (gameStateOnly->state_is_loading()) {
				break;
			}

			if (gameStateOnly->state_is_defeat()) {
				break;
			}

			this->draw();
			this->People->draw();
		}


		Sleep(50);
		this->TimeCount -= 75;

		if (this->lose(People)) {
			People->losing_effect();
			cScreen::screen_game_over();
			break;
		}

		if ((this->CurrentCoin == this->MaxCoin) && (UnblockCount == 0)) {
			UnblockCount++;
			this->destroy_finish_block();
			topLimit = FinishLine - 1;
		}

		if (this->win(People)) {
			People->winning_effect();
			cScreen::screen_win();
			break;
		}
	}
}

void cLevel::set_up(int level, int laneCount,int finishLine,int maxCoin, int timeAlotted, vector<cObject::ecType> objectTypes, vector<ecDirection> directions, vector<ecColor> objectColors
	, vector<int> objectCounts, vector<vector<int>> times, vector<int> steps, vector<int> crazySteps, int leftLimit, int rightLimit)
{
	for (int i = 0; i < this->LaneCount; i++)
		delete this->Lanes[i];
	delete[] this->Lanes;

	this->Level = level;
	this->LaneCount = laneCount;
	this->FinishLine = finishLine;
	this->FinishBlock = finishLine + 1;
	this->UnblockCount = 0;
	this->MaxCoin = maxCoin;
	this->CurrentCoin = 0;
	this->TimeCount = 0;
	this->TimeAlotted = timeAlotted * 1000;
	this->State = cLevel::ecState::PLAYING;
	this->People = cPeople::get_instance();

	this->Lanes = new cLane*[this->LaneCount];
	for (int i = 0; i < this->LaneCount; i++)
	{
		this->Lanes[i] = cLaneFactory::create(objectTypes[i], directions[i], objectColors[i]
			, objectCounts[i], cSetting::Game::TOP_LIMIT + 3 + i, times[i], steps[i], crazySteps[i], leftLimit, rightLimit);
	}
}

bool cLevel::win(cPeople* people)
{
	if ((this->CurrentCoin == this->MaxCoin) && (people->is_in_line(this->FinishLine)) && (this->TimeCount > 0)) {
		this->State = ecState::VICTORY;
		return true;
	}
	return false;
}

bool cLevel::lose(cPeople* people)
{
	if ((people->is_dead()) || (this->TimeCount <= 0) ){
		this->State = ecState::DEFEAT;
		return true;
	}
	return false;
}

void cLevel::draw_finish_block()
{
	if (this->UnblockCount > 0) {
		return;
	}
	ecColor flFirstColor = ecColor::LIGHT_RED;
	ecColor flSecondColor = ecColor::WHITE;

	text_color(flFirstColor);
	goto_xy(cSetting::Game::LEFT_LIMIT + 1, FinishBlock);
	cout << char(175);

	int i = 0;
	for ( i = cSetting::Game::LEFT_LIMIT + 2; i <= cSetting::Game::RIGHT_LIMIT - 2; i++) {
		cout << char(176);
		//cout << char(35);
	}

	cout << char(174);

	print_text_at_middle(FinishBlock, "BLOCKED", ecColor::RED, false);

	text_color();
	goto_xy(0, 0);
}

void cLevel::destroy_finish_block()
{
	this->UnblockCount++;
	ecColor flFirstColor = ecColor::LIGHT_RED;
	ecColor flSecondColor = ecColor::BLACK;

	int speed = 40;
	int middeX = get_console_width() / 2;

	int count = 1;
	print_text_at_middle(FinishBlock, "UNBLOCKING", ecColor::RED, false);

	int i,j;
	for (i = cSetting::Game::LEFT_LIMIT + 2,j = cSetting::Game::RIGHT_LIMIT - 2; i <= middeX - 1; i++,j--) {
		text_color(flFirstColor);
		goto_xy(i, FinishBlock);
		cout << char(175);

		text_color(flSecondColor);
		goto_xy(i-1, FinishBlock);
		cout << char(175);

		text_color(flFirstColor);
		goto_xy(j, FinishBlock);
		cout << char(174);

		text_color(flSecondColor);
		goto_xy(j+1 , FinishBlock);
		cout << char(174);

		if ( i % 14 == 0) {
			if (count %2 ==0) {
				print_text_at_middle(FinishBlock, "UNBLOCKING", ecColor::RED, false);
				count++;
			}
			else {
				print_text_at_middle(FinishBlock, "UNBLOCKING", ecColor::BLACK, false);
				count++;
			}

		}
		Sleep(speed);
	}
	print_text_at_middle(FinishBlock, "UNBLOCKING", ecColor::BLACK, false);
	text_color();
	goto_xy(0, 0);
}

bool cLevel::won()
{
	return (this->State == ecState::VICTORY);
}

bool cLevel::lost()
{
	return (this->State == ecState::DEFEAT);
}

void cLevel::reset()
{
	this->TimeCount = this->TimeAlotted;
	this->UnblockCount = 0;
	this->CurrentCoin = 0;

	for (int i = 0; i < this->LaneCount; i++) {
		this->Lanes[i]->reset();
	}
}

