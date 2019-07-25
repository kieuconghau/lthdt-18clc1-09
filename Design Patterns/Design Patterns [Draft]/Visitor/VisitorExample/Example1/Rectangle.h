#pragma once

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(float width, float height);
	void display() override;
	float calculate_area() override;
	float calculate_perimeter() override;
private:
	float width, height;
};
