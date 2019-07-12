#pragma once

#include "cObject.h"

class cFixedObject : public cObject
{
public:
	cFixedObject(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y);
	virtual ~cFixedObject();

private:
	virtual bool impact_xcor(int x) = 0;

protected:
	ecColor Color;
};

