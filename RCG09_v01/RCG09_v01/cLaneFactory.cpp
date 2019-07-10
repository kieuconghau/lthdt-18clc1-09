#include "cLaneFactory.h"

cLane* cLaneFactory::create(cObject::ecType objectType, ecDirection direction, ecColor objectColor, int objectCount, int y, vector<int> time, int step, int leftLimit, int rightLimit)
{
	switch (objectType)
	{
	case cObject::ecType::MV_CAR:
		return new cMovableObjectLane(objectType, direction, objectColor, objectCount, y, time, step, leftLimit, rightLimit);
	case cObject::ecType::MV_TRUCK:
		return new cMovableObjectLane(objectType, direction, objectColor, objectCount, y, time, step, leftLimit, rightLimit);
	case cObject::ecType::MV_TRAIN:
		return new cMovableObjectLane(objectType, direction, objectColor, objectCount, y, time, step, leftLimit, rightLimit);
	case cObject::ecType::MA_BIRD:
		return new cMovableObjectLane(objectType, direction, objectColor, objectCount, y, time, step, leftLimit, rightLimit);
	case cObject::ecType::MA_DINOSAUR:
		return new cMovableObjectLane(objectType, direction, objectColor, objectCount, y, time, step, leftLimit, rightLimit);
	case cObject::ecType::MF_WOOD:
		
	case cObject::ecType::S_COIN:

	case cObject::ecType::S_BUSH:
		
	default:
		break;
	}

	return nullptr;
}
