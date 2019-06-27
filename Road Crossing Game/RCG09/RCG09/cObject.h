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
	// Only used for automatic-moving objects: cVehicle, cAnimal. (One-dimesional)
	cObject(unsigned int n, ecDirection direction, unsigned int x, unsigned int y);
#//virtual void draw(unsigned int leftLimit, unsigned int rightLimit) = 0;
	virtual void move(unsigned int leftLimit, unsigned int rightLimit);
					
	// Only used for controlled-moving objects: cPeople. (Two-dimensional)
	//cObject(...);
	
	// Only used for non-moving objects: cTrafficLight.
	cObject(unsigned int n, unsigned int x, unsigned int y);
#//virtual void draw() = 0;
	virtual void work();

	virtual ~cObject();

protected:
	unsigned int* X;
	unsigned int* Y;
};