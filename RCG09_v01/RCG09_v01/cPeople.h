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
	void move_back();
	void die();

	void update_pos();

	void move(int leftLimit, int rightLimit, int topLimit, int bottomLimit);		// Use WASD
	void move_1(int leftLimit, int rightLimit, int topLimit, int bottomLimit);		// Use arrow-keys
	
	void set_starting_pos(int xStart, int yStart);
	bool is_alive();
	bool is_dead();

	bool is_impacted(int y);
	bool is_impacted(cObject* objects);

	bool stand_still();

private:
	static cPeople* Instance;
	int X;
	int Y;
	cPeople::ecState State;
	ecColor Color;
	ecDirection LastDirection;
	char Shape;
	char BrickShape;
	ecColor BrickColor;
};