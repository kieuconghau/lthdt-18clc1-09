#pragma once

#include "cMovableObject.h"

class cFloat : public cMovableObject
{
public:
	cFloat(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y, int step);
	virtual ~cFloat();

public:
	virtual void move(int leftLimit, int rightLimit, int virtualDistance) = 0;
	virtual void draw(int leftLimit, int rightLimit) = 0;
	virtual void tell() = 0;
	virtual bool impact_xcor(int x) = 0;

private:

protected:

};

