#pragma once

#include "Graphic.h"
#include "cAnimal.h"
#include "cDinosaur.h"
#include "cBird.h"

class cAnimalFactory
{
public:
	static cAnimal* create(cAnimalType type, cDirection direction, cColor color, unsigned int x, unsigned int y);
};