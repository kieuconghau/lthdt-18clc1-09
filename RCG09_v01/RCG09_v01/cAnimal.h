#pragma once
#pragma comment(lib, "winmm.lib")
#include <windows.h>
#include <mmsystem.h>

#include "cMovableObject.h"

class cAnimal : public cMovableObject
{
public:
	cAnimal(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y, int step, int crazyStep);
	virtual ~cAnimal();

public:
	virtual void move(int leftLimit, int rightLimit, int virtualDistance) = 0;
	virtual void draw(int leftLimit, int rightLimit) = 0;
	virtual void tell() = 0;
	virtual bool impact_xcor(int x) = 0;

private:

protected:

};
