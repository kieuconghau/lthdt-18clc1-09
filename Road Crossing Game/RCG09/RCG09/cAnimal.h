#pragma once
#include "Graphic.h"
#include <Windows.h>
#include <mmsystem.h>

enum class cAnimalType
{
	BIRD,
	DINOSAUR
};

enum class cAnimalState
{
	RUNNING,
	CRASHING
};

class cAnimal
{
public:
	cAnimal();
	cAnimal(unsigned int n, cDirection direction, cColor color, unsigned int x, unsigned int y);
	virtual ~cAnimal();

	virtual void draw() = 0;
	virtual void move(unsigned int leftLimit = 0, unsigned int rightLimit = get_console_width()) = 0;
	virtual void tell() = 0;
protected:
	unsigned int* X;
	unsigned int* Y;
	cDirection Direction;
	cColor Color;
};
