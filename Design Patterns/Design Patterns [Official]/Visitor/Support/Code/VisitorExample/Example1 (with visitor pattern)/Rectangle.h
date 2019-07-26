#pragma once

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(float width, float height);
	void accept(ShapeVisitor* v) override;
	float get_height();
	float get_width();
private:
	float width, height;
};
