#pragma once

#include "Shape.h"

class Rectangle
{
public:
	Rectangle(float width, float height);
	void accept(ShapeVisitor* v);
	float get_height();
	float get_width();
private:
	float width, height;
};

