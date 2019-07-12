#pragma once

#include "cSetting.h"
#include "cLane.h"
#include "cTrafficLight.h"
#include "cObjectFactory.h"
#include "cPeople.h"

class cMovableObjectLane : public cLane
{
public:
	cMovableObjectLane(cObject::ecType objectType, ecDirection direction, ecColor objectColor, int objectCount, int y
		, vector<int> timeTrafficLight, int step, int leftLimit, int rightLimit, int virtualDistance=0);
	~cMovableObjectLane();

private:
	cObject::ecType MovableObjectType;
	ecDirection Direction;
	cMovableObject** MovableObjects;
	cTrafficLight* TrafficLight;

	bool is_vehicle_lane();
	void work();
	void impact_xcor(cPeople* people);

	friend class cPeople;
};
