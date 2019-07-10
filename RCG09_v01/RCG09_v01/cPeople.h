#pragma once

#include "Graphic.h"
#include "cObject.h"

class cPeople
{
public:
	enum class ecState : char
	{
		ALIVE,
		DEAD
	};

	static cPeople* get_instance();
	cPeople();
	~cPeople();
	void draw();
	void move_up(int topLimit);
	void move_down(int botLimit);
	void move_left(int leftLimit);
	void move_right(int rightLimit);
	void die();

	void move(int leftLimit, int rightLimit, int topLimit, int bottomLimit);		// Use WASD
	ecDirection move_1(int leftLimit, int rightLimit, int topLimit, int bottomLimit);		// Use arrow-keys
	
	void set_starting_pos(int xStart, int yStart);
	bool is_alive();
	bool is_dead();

	bool is_impacted(int y);
	bool is_impacted(cObject* objects);

private:
	static const int N = 2;
	static const char Shapes[cPeople::N];
	static cPeople* Instance;
	int* X;
	int* Y;
	cPeople::ecState State;
	ecColor Color;
};