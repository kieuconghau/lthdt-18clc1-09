#include "cPeople.h"

cPeople* cPeople::instance = nullptr;

cPeople* cPeople::getInstance()
{
	if (instance == nullptr) {
		instance = new cPeople;
		instance->state = cState::ALIVE;
		instance->X = new unsigned[2];
		instance->Y = new unsigned[2];
		instance->shape[0] = char(219);
		instance->shape[1] = char(32);
	}
	return instance;
}

cPeople::cPeople() = default;

cPeople::~cPeople()
{
	delete instance;
}

void cPeople::draw()
{
	text_color(ecColor::WHITE);

	goto_xy(this->X[0], this->Y[0]);
	cout << this->shape[0];

	goto_xy(this->X[1], this->Y[1]);
	cout << this->shape[1];

	goto_xy(0, 0);
}

void cPeople::move_up(unsigned int limit)
{
	if (this->Y[0] <= limit) {
		return;
	}

	this->X[1] = this->X[0];
	this->Y[1] = this->Y[0];

	this->Y[0] --;

	this->draw();
}

void cPeople::move_down(unsigned int limit)
{
	if (this->Y[0] >= limit) {
		return;
	}

	this->X[1] = this->X[0];
	this->Y[1] = this->Y[0];

	this->Y[0] ++;

	this->draw();
}

void cPeople::move_left(unsigned int limit)
{
	if (this->X[0] <= limit) {
		return;
	}

	this->X[1] = this->X[0];
	this->Y[1] = this->Y[0];

	this->X[0] --;

	this->draw();
}

void cPeople::move_right(unsigned int limit)
{
	if (this->X[0] >= limit) {
		return;
	}

	this->X[1] = this->X[0];
	this->Y[1] = this->Y[0];

	this->X[0] ++;

	this->draw();
}

void cPeople::set_start_pos(unsigned int xStart, unsigned int yStart)
{
	this->X[0] = xStart;
	this->X[1] = xStart;

	this->Y[0] = yStart;
	this->Y[1] = yStart - 1;

	this->draw();
}

void cPeople::move(unsigned int leftLimit, unsigned int rightLimit, unsigned int topLimit, unsigned int bottomLimit)
{
		if (GetAsyncKeyState(0x41) != 0) {
			this->move_left(leftLimit);
			Sleep(100);
			return;
		}
		else if (GetAsyncKeyState(0x44) != 0) {
			this->move_right(rightLimit);
			Sleep(100);
			return;
		}
		else if (GetAsyncKeyState(0x57) != 0) {
			this->move_up(topLimit);
			Sleep(150);
			return;
		}
		else if (GetAsyncKeyState(0x53) != 0) {
			this->move_down(bottomLimit);
			Sleep(150);
			return;
		}
}

bool cPeople::isAlive() {
	if (this->state == cState::ALIVE) {
		return true;
	}
	else {
		return false;
	}
}

bool cPeople::isFinish(unsigned int finishLine)
{
	if (this->Y[0] == finishLine) {
		return true;
	}
	else {
		return false;
	}
}

void cPeople::die()
{
	this->state = cState::DEAD;
}

bool cPeople::isInLine(unsigned int yLane)
{
	if (this->Y[0] == yLane) {
		return true;
	}
	else {
		return false;
	}
}






