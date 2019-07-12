#pragma once

#include "cFixedObject.h"

class cInedibleObject : public cFixedObject
{
public:
	cInedibleObject(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y);
	virtual ~cInedibleObject();

private:
	virtual bool impact_xcor(int x) = 0;

protected:

};

