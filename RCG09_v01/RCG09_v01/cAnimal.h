#pragma once

#include "cMovableObject.h"

class cAnimal : public cMovableObject
{
public:
	enum class ecType
	{
		BIRD,
		DINOSAUR
	};

	cAnimal(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y, int step);
	virtual ~cAnimal();

	virtual void work(int leftLimit, int rightLimit, int virtualDistance) = 0;
	virtual void tell() = 0;

private:
	virtual void draw(int leftLimit, int rightLimit) = 0;
	virtual bool impact_xcor(int x) = 0;

protected:

};


