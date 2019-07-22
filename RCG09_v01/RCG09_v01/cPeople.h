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

public:
	static cPeople* get_instance();

public:
	cPeople();
	~cPeople();

public:
	void draw();
	void move_up(int topLimit);
	void move_down(int botLimit);
	void move_left(int leftLimit);
	void move_right(int rightLimit);
	void move_back();
	void die();

	void update_pos();

	void move(int leftLimit, int rightLimit, int topLimit, int bottomLimit);
	
	void set_starting_pos(int xStart, int yStart);
	bool is_alive();
	bool is_dead();

	bool is_in_line(unsigned int y);
	bool is_impacted(cObject* objects);

	bool stand_still();
	
	void change_brick(char brickShape, ecColor brickColor);

	void winning_effect();
	void losing_effect();

private:
	static cPeople* Instance;

private:
	int X;
	int Y;
	cPeople::ecState State;
	ecColor Color;
	ecDirection LastDirection;

	char Shape;

	char BrickShape;
	ecColor BrickColor;
};