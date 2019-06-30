#pragma once

#include "cObject.h"
#include "Graphic.h"
#include <iostream>

static unsigned PEOPLE_DEFAULT_POS_X = get_console_width()/2;
static unsigned PEOPLE_DEFAULT_POS_Y = get_console_height() / 2 + 15;

enum class cState {
	DEAD ,
	ALIVE 
};

class cPeople : public cObject
{
public:
	static const unsigned int N = 2;

	static cPeople* getInstance();

	~cPeople() ;

	void draw();

	void move(unsigned int leftLimit, unsigned int rightLimit,unsigned int topLimit,unsigned int bottomLimit);

	void move_up(unsigned int limit);

	void move_down(unsigned int limit);

	void move_left(unsigned int limit);

	void move_right(unsigned int limit);

	void set_start_pos(unsigned int xStart,unsigned int yStart);

	bool isAlive();

	bool isFinish(unsigned int finishLine);

	void die();

	bool isInLine(unsigned int yLine);

protected:
	cPeople();
private:
	static cPeople* instance;
	char shape[N];
	cState state;

	//abandoned
	void draw(unsigned int leftLimit, unsigned int rightLimit) {};
	void move(unsigned int leftLimit = 0, unsigned int rightLimit = get_console_width()) {};
	//--------
};