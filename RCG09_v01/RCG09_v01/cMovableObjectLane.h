#pragma once

#include "cSetting.h"
#include "cLane.h"
#include "cTrafficLight.h"
#include "cObjectFactory.h"

class cMovableObjectLane : public cLane
{
	friend class cPeople;

public:
	cMovableObjectLane(cObject::ecType objectType, ecDirection direction, ecColor objectColor, int objectCount, int y
		, vector<int> timeTrafficLight, int step, int crazyStep, int leftLimit, int rightLimit, int virtualDistance=0);
	~cMovableObjectLane();

public:
	void work(cPeople* people);
	int impact(cPeople* people);
	void draw();
	void change_people_brick(cPeople* people);
	void reset() {}; // nothing need to be reset yet;
	void crazy();
	void caml_down();

public:
	bool is_vehicle_lane();
	bool is_animal_lane();

private:
	cObject::ecType MovableObjectType;
	ecDirection Direction;
	cMovableObject** MovableObjects;
	cTrafficLight* TrafficLight;
	int Step;
	int CrazyStep;
};
