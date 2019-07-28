#pragma once

#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(float a, float b, float c);
	void display();
	float calculate_area();
	float calculate_perimeter();
private:
	float a, b, c;
};

