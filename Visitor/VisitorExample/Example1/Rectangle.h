#pragma once

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(float width, float height);
	void display();
	float calculate_area();
	float calculate_perimeter();
private:
	float width, height;
};

