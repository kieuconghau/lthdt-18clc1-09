#pragma once

#include "cObject.h"

class cMovableObject : public cObject
{
public:
	cMovableObject(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y, int step);
	virtual ~cMovableObject();
	
public:
	virtual void move(int leftLimit, int rightLimit, int virtualDistance) = 0;
	virtual void draw(int leftLimit, int rightLimit) = 0;
	virtual void tell() = 0;
	virtual bool impact_xcor(int x) = 0;
	virtual char brick_shape() = 0;
	virtual ecColor brick_color() = 0;

private:

protected:
	ecColor Color;
	int Step;
};


