#pragma once

#include "cSetting.h"
#include "cLane.h"
#include "cTrafficLight.h"
#include "cObjectFactory.h"
#include "cPeople.h"

class cMovableObjectLane : public cLane
{
	friend class cPeople;

public:
	cMovableObjectLane(cObject::ecType objectType, ecDirection direction, ecColor objectColor, int objectCount, int y
		, vector<int> timeTrafficLight, int step, int leftLimit, int rightLimit, int virtualDistance=0);
	~cMovableObjectLane();

public:
	void work();
	void impact_xcor(cPeople* people);
	void draw();

public:
	bool is_vehicle_lane();

private:
	cObject::ecType MovableObjectType;
	ecDirection Direction;
	cMovableObject** MovableObjects;
	cTrafficLight* TrafficLight;
};
