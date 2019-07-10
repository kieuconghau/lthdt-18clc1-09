#pragma once

#include "cCar.h"
#include "cTruck.h"
#include "cTrain.h"
#include "cBird.h"
#include "cDinosaur.h"
#include "cPeople.h"

class cLane
{
public:
	cLane(cObject::ecType objectType, int y, int objectCount, int leftLimit, int rightLimit, int virtualDistance);
	virtual ~cLane();

	virtual void work() = 0;
	virtual void impact(cPeople* people) = 0;

	virtual void update_pos() = 0;
	virtual void draw() = 0;
	
	bool has_people(cPeople* people);

private:

protected:
	int Y;
	int ObjectCount;
	char BrickShape;
	ecColor BrickColor;
	int LeftLimit;
	int RightLimit;
	int VirtualDistance;

	friend class cPeople;
};
