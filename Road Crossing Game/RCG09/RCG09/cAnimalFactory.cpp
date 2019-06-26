#include "cAnimalFactory.h"

cAnimal* cAnimalFactory::create(cAnimalType type, cDirection direction, cColor color, unsigned int x, unsigned int y)
{
	switch (type)
	{
	case cAnimalType::BIRD:
		return (new cBird(direction, color, x, y));
	case cAnimalType::DINOSAUR:
		return (new cDinosaur(direction, color, x, y));
	default:
		throw;
	}
}