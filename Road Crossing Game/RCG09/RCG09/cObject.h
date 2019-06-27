#pragma once

#include "Graphic.h"

enum class ecObjectType		// (Tricky)
{
	PEOPLE,
	BIRD,
	DINOSAUR,
	CAR,
	TRUCK,
	TRAFFIC_LIGHT
};

class cObject
{
public:
	cObject(unsigned int n, ecDirection direction, unsigned int x, unsigned int y);	// Only used for automatic-moving objects: cVehicle, cAnimal.
	//cObject(...);		// Only used for controlled-moving objects: cPeople.
	//cObject(...);		// Only used for non-moving objects: cTrafficLight.
	virtual ~cObject();

	virtual void draw(unsigned int leftLimit, unsigned int rightLimit) = 0;
	virtual void move(unsigned int leftLimit = 0, unsigned int rightLimit = get_console_width()) = 0;

protected:
	unsigned int* X;
	unsigned int* Y;
};