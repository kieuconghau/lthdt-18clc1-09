#include "cLane.h"

cLane::cLane(cObject::ecType objectType, int y, int objectCount, int leftLimit, int rightLimit, int virtualDistance)
{
	this->Y = y;
	this->ObjectCount = objectCount;
	this->LeftLimit = leftLimit;
	this->RightLimit = rightLimit;
	this->VirtualDistance = virtualDistance;

	switch (objectType)
	{
	case cObject::ecType::MV_CAR:
		this->BrickShape = cCar::BRICK_SHAPE;
		this->BrickColor = cCar::BRICK_COLOR;
		break;
	case cObject::ecType::MV_TRUCK:
		this->BrickShape = cTruck::BRICK_SHAPE;
		this->BrickColor = cTruck::BRICK_COLOR;
		break;
	case cObject::ecType::MV_TRAIN:
		this->BrickShape = cTrain::BRICK_SHAPE;
		this->BrickColor = cTrain::BRICK_COLOR;
		break;
	case cObject::ecType::MA_BIRD:
		this->BrickShape = cBird::BRICK_SHAPE;
		this->BrickColor = cBird::BRICK_COLOR;
		break;
	case cObject::ecType::MA_DINOSAUR:
		this->BrickShape = cDinosaur::BRICK_SHAPE;
		this->BrickColor = cDinosaur::BRICK_COLOR;
		break;
	case cObject::ecType::MF_WOOD:
		break;
	case cObject::ecType::S_COIN:
		break;
	case cObject::ecType::S_BUSH:
		break;
	case cObject::ecType::TRAFFIC_LIGHT:
		break;
	default:
		break;
	}
}

cLane::~cLane() {}

bool cLane::has_people(cPeople* people)
{
	return people->is_impacted(this->Y);
}
