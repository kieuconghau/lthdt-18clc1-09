#include "cInedibleObject.h"

cInedibleObject::cInedibleObject(cObject::ecType objectType, int n, ecDirection direction, ecColor color, int x, int y)
	: cFixedObject(ObjectType, n, direction, color, x, y) {}

cInedibleObject::~cInedibleObject() {}


