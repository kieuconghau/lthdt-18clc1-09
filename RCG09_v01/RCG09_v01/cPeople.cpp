#include "cPeople.h"

cPeople* cPeople::Instance = nullptr;

cPeople* cPeople::get_instance()
{
	if (cPeople::Instance == nullptr)
	{
		cPeople::Instance = new cPeople;
	}

	return cPeople::Instance;
}

cPeople::cPeople()
{
	this->X = 0;
	this->Y = 0;
	this->State = ecState::ALIVE;
	this->Color = ecColor::WHITE;
	this->LastDirection = ecDirection::NONE;
	this->Shape = char(219);
	this->BrickShape = char(219);
	this->BrickColor = ecColor::BLACK;	
}

cPeople::~cPeople()
{	
	delete cPeople::Instance;
}

void cPeople::draw()
{
	text_color(this->Color);

	goto_xy(this->X, this->Y);
	cout << this->Shape;
	text_color();
	goto_xy(0, 0);
}

void cPeople::move_up(int topLimit)
{
	if (this->Y > topLimit)
	{
		this->Y --;
		this->LastDirection = ecDirection::UP;
	}
}

void cPeople::move_down(int botLimit)
{
	if (this->Y < botLimit)
	{
		this->Y++;
		this->LastDirection = ecDirection::DOWN;
	}
}

void cPeople::move_left(int leftLimit)
{
	if (this->X > leftLimit)
	{
		this->X --;
		this->LastDirection = ecDirection::LEFT;
	}
}

void cPeople::move_right(int rightLimit)
{
	if (this->X < rightLimit)
	{
		this->X ++;
		this->LastDirection = ecDirection::RIGHT;
	}
}

void cPeople::move_back()
{
	if (this->LastDirection == ecDirection::UP) {
		this->Y++;
	}
	if (this->LastDirection == ecDirection::DOWN) {
		this->Y--;
	}
	if (this->LastDirection == ecDirection::LEFT) {
		this->X++;
	}
	if (this->LastDirection == ecDirection::RIGHT) {
		this->X--;
	}
	this->LastDirection = ecDirection::NONE;
}

void cPeople::update_pos()
{
	text_color(this->BrickColor);

	if (this->LastDirection == ecDirection::UP) {
		goto_xy(this->X, this->Y + 1);
		cout << this->BrickShape;
	}
	else if (this->LastDirection == ecDirection::DOWN) {
		goto_xy(this->X, this->Y - 1);
		cout << this->BrickShape;
	}
	else if (this->LastDirection == ecDirection::LEFT) {
		goto_xy(this->X+1, this->Y);
		cout << this->BrickShape;
	}
	else if (this->LastDirection == ecDirection::RIGHT) {
		goto_xy(this->X - 1, this->Y );
		cout << this->BrickShape;
	}
	
	text_color(this->Color);
	goto_xy(this->X, this->Y);
	cout << this->Shape;
	goto_xy(this->X, this->Y);
	
	this->LastDirection = ecDirection::NONE;
}

void cPeople::set_starting_pos(int xStart, int yStart)
{
	this->Color = ecColor::WHITE;
	this->BrickColor = ecColor::BLACK;
	this->State = ecState::ALIVE;
	this->X = xStart;
	this->Y = yStart;
	this->draw();
}

//void cPeople::move(int leftLimit, int rightLimit, int topLimit, int bottomLimit)
//{
//	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
//	{
//		this->move_left(leftLimit);
//	}
//	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
//	{
//		this->move_right(rightLimit);
//	}
//	else if (GetAsyncKeyState(VK_UP) & 0x8000)
//	{
//		this->move_up(topLimit);
//	}
//	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
//	{
//		this->move_down(bottomLimit);
//	}
//	else
//	{
//		this->LastDirection = ecDirection::NONE;
//	}
//}

void cPeople::move(int leftLimit, int rightLimit, int topLimit, int bottomLimit)
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		this->move_left(leftLimit);
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		this->move_right(rightLimit);
	}
	else if (GetAsyncKeyState(VK_UP))
	{
		this->move_up(topLimit);
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		this->move_down(bottomLimit);
	}
	else
	{
		this->LastDirection = ecDirection::NONE;
	}
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

bool cPeople::is_in_line(unsigned int y)
{
	return this->Y == y;
}

bool cPeople::is_impacted(cObject* object)
{
	return object->impact_xcor(this->X);
}

bool cPeople::stand_still()
{
	return this->LastDirection == ecDirection::NONE;
}

void cPeople::change_brick(char brickShape, ecColor brickColor) 
{
	this->BrickShape = brickShape;
	this->BrickColor = brickColor;
}

void cPeople::winning_effect() {
	this->draw();
	Sleep(500);
}

void cPeople::losing_effect()
{
	this->draw();
	Sleep(1000);
}

ecDirection cPeople::get_last_direction()
{
	return this->LastDirection;
}