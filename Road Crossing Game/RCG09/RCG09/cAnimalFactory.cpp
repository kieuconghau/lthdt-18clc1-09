#include "cAnimalFactory.h"

cAnimal* cAnimalFactory::create(ecAnimalType type, ecDirection direction, ecColor color, unsigned int x, unsigned int y)
{
	switch (type)
	{
	case ecAnimalType::BIRD:
		return (new cBird(direction, color, x, y));
	case ecAnimalType::DINOSAUR:
		return (new cDinosaur(direction, color, x, y));
	default:
		throw;
	}
}