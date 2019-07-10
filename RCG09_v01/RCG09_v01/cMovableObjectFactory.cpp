#include "cMovableObjectFactory.h"

cMovableObject* cMovableObjectFactory::create(cObject::ecType movableObjectType, ecDirection direction, ecColor color, int x, int y, int step)
{
	switch (movableObjectType)
	{
	case cObject::ecType::MV_CAR:
		return new cCar(direction, color, x, y, step);
	case cObject::ecType::MV_TRUCK:
		return new cTruck(direction, color, x, y, step);
	case cObject::ecType::MV_TRAIN:
		return new cTrain(direction, color, x, y, step);
	case cObject::ecType::MA_BIRD:
		return new cBird(direction, color, x, y, step);
	case cObject::ecType::MA_DINOSAUR:
		return new cDinosaur(direction, color, x, y, step);
	case cObject::ecType::MF_WOOD:

	default:
		throw;
	}

	return nullptr;
}
