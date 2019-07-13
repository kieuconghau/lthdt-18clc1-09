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
		//this->BrickShape = cWood::BRICK_SHAPE;
		//this->BrickColor = cWood::BRICK_COLOR;
		break;
	case cObject::ecType::FE_COIN:
		this->BrickShape = cCoin::BRICK_SHAPE;
		this->BrickColor = cCoin::BRICK_COLOR;
		break;
	case cObject::ecType::FI_STONE:
		this->BrickShape = cStone::BRICK_SHAPE;
		this->BrickColor = cStone::BRICK_COLOR;
		break;
	case cObject::ecType::TRAFFIC_LIGHT:
		this->BrickShape = char(219);
		this->BrickColor = ecColor::BLACK;
		break;
	default:
		this->BrickShape = char(219);
		this->BrickColor = ecColor::BLACK;
		break;
	}
}

cLane::~cLane() {}

void cLane::draw()
{
	goto_xy(this->LeftLimit, this->Y);
	text_color(this->BrickColor);

	for (int i = this->LeftLimit; i <= this->RightLimit; ++i)
	{
		cout << this->BrickShape;
	}
}

bool cLane::has_people(cPeople* people)
{
	return people->is_in_line(this->Y);
}
