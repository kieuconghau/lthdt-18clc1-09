#pragma once

#include "cFixedObject.h"

class cEdibleObject : public cFixedObject
{
public:
	cEdibleObject(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y);
	virtual ~cEdibleObject();

private:
	virtual bool impact_xcor(int x) = 0;

protected:

};

