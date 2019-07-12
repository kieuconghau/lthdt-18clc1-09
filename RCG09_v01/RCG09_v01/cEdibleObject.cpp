#include "cEdibleObject.h"

cEdibleObject::cEdibleObject(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y)
	: cFixedObject(objectType, n, direction, color, x, y) {}

cEdibleObject::~cEdibleObject() {}


