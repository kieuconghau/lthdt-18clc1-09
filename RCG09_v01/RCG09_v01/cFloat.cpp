#include "cFloat.h"

cFloat::cFloat(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y, int step, int crazyStep)
	: cMovableObject(objectType, n, direction, color, x, y, step, crazyStep) {}

cFloat::~cFloat() {}

