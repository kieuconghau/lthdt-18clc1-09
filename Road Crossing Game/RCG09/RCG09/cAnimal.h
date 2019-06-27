#pragma once

#include "Graphic.h"
#include "cObject.h"

enum class ecAnimalType
{
	BIRD,
	DINOSAUR
};

class cAnimal : public cObject
{
public:
	cAnimal(unsigned int n, ecDirection direction, ecColor color, unsigned int x, unsigned int y);
	virtual ~cAnimal();
	
	virtual void draw(unsigned int leftLimit, unsigned int rightLimit) = 0;
	virtual void move(unsigned int leftLimit, unsigned int rightLimit) = 0;

protected:
	ecDirection Direction;
	ecColor Color;
};
