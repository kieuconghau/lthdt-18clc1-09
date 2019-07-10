#include "cPeople.h"

cPeople* cPeople::Instance = nullptr;

const char cPeople::Shapes[cPeople::N] = { char(219), char(32) };

cPeople* cPeople::get_instance()
{
	if (cPeople::Instance == nullptr) {
		cPeople::Instance = new cPeople;
		cPeople::Instance->X = new int[cPeople::N];
		cPeople::Instance->Y = new int[cPeople::N];
		cPeople::Instance->State = ecState::ALIVE;
		cPeople::Instance->Color = ecColor::WHITE;
	}

	return cPeople::Instance;
}

cPeople::cPeople()
{
	this->X = nullptr;
	this->Y = nullptr;
	this->State = ecState::ALIVE;
	this->Color = ecColor::WHITE;
}

cPeople::~cPeople()
{	
	delete[] this->X;

	delete[] this->Y;

	delete cPeople::Instance;
}

void cPeople::draw()
{
	text_color(this->Color);

	goto_xy(this->X[0], this->Y[0]);
	cout << this->Shapes[0];

	goto_xy(this->X[1], this->Y[1]);
	cout << this->Shapes[1];

	text_color();
	goto_xy(0, 0);
}

void cPeople::move_up(int topLimit)
{
	if (this->Y[0] > topLimit)
	{
		this->X[1] = this->X[0];
		this->Y[1] = this->Y[0];

		this->Y[0] --;

		//this->draw();
	}
}

void cPeople::move_down(int botLimit)
{
	if (this->Y[0] < botLimit)
	{
		this->X[1] = this->X[0];
		this->Y[1] = this->Y[0];

		this->Y[0] ++;

		//this->draw();
	}
}

void cPeople::move_left(int leftLimit)
{
	if (this->X[0] > leftLimit)
	{
		this->X[1] = this->X[0];
		this->Y[1] = this->Y[0];

		this->X[0] --;

		//this->draw();
	}
}

void cPeople::move_right(int rightLimit)
{
	if (this->X[0] < rightLimit)
	{
		this->X[1] = this->X[0];
		this->Y[1] = this->Y[0];

		this->X[0] ++;

		//this->draw();
	}
}

void cPeople::set_starting_pos(int xStart, int yStart)
{
	this->X[0] = xStart;
	this->X[1] = xStart;

	this->Y[0] = yStart;
	this->Y[1] = yStart + 1;

	this->draw();
}

void cPeople::move(int leftLimit, int rightLimit, int topLimit, int bottomLimit)
{
	if (GetAsyncKeyState(0x41) != 0)
	{
		this->move_left(leftLimit);
	}
	else if (GetAsyncKeyState(0x44) != 0)
	{
		this->move_right(rightLimit);
	}
	else if (GetAsyncKeyState(0x57) != 0)
	{
		this->move_up(topLimit);
	}
	else if (GetAsyncKeyState(0x53) != 0)
	{
		this->move_down(bottomLimit);
	}
}

ecDirection cPeople::move_1(int leftLimit, int rightLimit, int topLimit, int bottomLimit)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		this->move_left(leftLimit);
		return ecDirection::LEFT;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		this->move_right(rightLimit);
		return ecDirection::RIGHT;
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		this->move_up(topLimit);
		return ecDirection::UP;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		this->move_down(bottomLimit);
		return ecDirection::DOWN;
	}

	return ecDirection::NONE;
}

bool cPeople::is_alive()
{
	return this->State == cPeople::ecState::ALIVE;
}

bool cPeople::is_dead()
{
	return this->State == cPeople::ecState::DEAD;
}

void cPeople::die()
{
	this->State = cPeople::ecState::DEAD;
	this->Color = ecColor::RED;
}

bool cPeople::is_impacted(int y)
{
	return this->Y[0] == y;
}

bool cPeople::is_impacted(cObject* object)
{
	return object->impact(this->X[0]);
}
