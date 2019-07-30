#include "cVehicle.h"

cVehicle::cVehicle(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y, int step, int crazyStep)
	: cMovableObject(objectType, n, direction, color, x, y, step, crazyStep) {}

cVehicle::~cVehicle() {}


