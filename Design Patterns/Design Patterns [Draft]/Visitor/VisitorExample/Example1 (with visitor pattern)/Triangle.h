#pragma once

#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(float a, float b, float c);
	void accept(ShapeVisitor* v) override;
	float get_a();
	float get_b();
	float get_c();
private:
	float a,b,c;
};