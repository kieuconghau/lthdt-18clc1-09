#pragma once

#include "Graphic.h"
#include "cAnimal.h"
#include "cDinosaur.h"
#include "cBird.h"

class cAnimalFactory
{
public:
	static cAnimal* create(ecAnimalType type, ecDirection direction, ecColor color, unsigned int x, unsigned int y);
};

