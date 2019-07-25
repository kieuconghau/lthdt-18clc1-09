#pragma once

#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(float a, float b, float c);
	void display() override;
	float calculate_area() override;
	float calculate_perimeter() override;
private:
	float a, b, c;
};
