#pragma once

#include "Graphic.h"

class cObject
{
public:
	enum class ecType
	{
		MV_CAR,
		MV_TRUCK,
		MV_TRAIN,

		MA_BIRD,
		MA_DINOSAUR,

		MF_WOOD,

		FE_COIN,
		FI_STONE,

		TRAFFIC_LIGHT
	};

	cObject(cObject::ecType objectType, int n, ecDirection direction, int x, int y, int step=0);
	virtual ~cObject();

	virtual bool impact_xcor(int x) = 0;

private:

protected:
	int* X;
	int Y;
	ecDirection Direction;
	cObject::ecType ObjectType;
};
