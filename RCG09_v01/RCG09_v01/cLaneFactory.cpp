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
		return new cMovableObjectLane(objectType, direction, objectColor, objectCount, y, time, step, leftLimit, rightLimit);
	case cObject::ecType::FE_COIN:
		return new cFixedObjectLane(objectType, direction, objectColor, y, objectCount, leftLimit, rightLimit);
	case cObject::ecType::FI_STONE:
		return new cFixedObjectLane(objectType, direction, objectColor, y, objectCount, leftLimit, rightLimit);
	case cObject::ecType::MIX_STONE_AND_COIN:
		return new cFixedObjectLane(objectType, direction, objectColor, y, objectCount, leftLimit, rightLimit);
	default:
		break;
	}

	return nullptr;
}
