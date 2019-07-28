#pragma once

#include "cCar.h"
#include "cTruck.h"
#include "cTrain.h"
#include "cBird.h"
#include "cDinosaur.h"
#include "cWood.h"
#include "cCoin.h"
#include "cStone.h"
#include "cPeople.h"

class cLane
{
	friend class cPeople;

public:
	cLane(cObject::ecType objectType, int y, int objectCount, int leftLimit, int rightLimit, int virtualDistance);
	virtual ~cLane();

public:
	virtual void work() = 0;
	virtual int impact(cPeople* people) = 0;
	virtual void draw();
	virtual void change_people_brick(cPeople* people) = 0;
	
	virtual bool has_people(cPeople* people);

	virtual void reset() {};
public:

private:

protected:
	int Y;
	int ObjectCount;

	char BrickShape;
	ecColor BrickColor;

	int LeftLimit;
	int RightLimit;
	int VirtualDistance;
};
