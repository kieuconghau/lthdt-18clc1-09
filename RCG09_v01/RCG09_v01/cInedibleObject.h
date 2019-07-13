#pragma once

#include "cFixedObject.h"

class cInedibleObject : public cFixedObject
{
public:
	cInedibleObject(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y);
	virtual ~cInedibleObject();

public:
	virtual bool impact_xcor(int x) = 0;
	virtual void draw(int leftLimit, int rightLimit) = 0;

private:

protected:

};

