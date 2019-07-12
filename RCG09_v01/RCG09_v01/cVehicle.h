#pragma once

#include "cMovableObject.h"

class cVehicle : public cMovableObject
{
public:
	enum class ecType
	{
		CAR,
		TRUCK,
		TRAIN
	};

	cVehicle(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y, int step);
	virtual ~cVehicle() {};

	virtual void work(int leftLimit, int rightLimit, int virtualDistance) = 0;
	virtual void tell() = 0;

private:
	virtual void draw(int leftLimit, int rightLimit) = 0;
	virtual bool impact_xcor(int x) = 0;

protected:

};

