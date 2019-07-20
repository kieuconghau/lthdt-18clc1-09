#include "cFloat.h"

cFloat::cFloat(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y, int step)
	: cMovableObject(objectType, n, direction, color, x, y, step) {}

cFloat::~cFloat() {}

