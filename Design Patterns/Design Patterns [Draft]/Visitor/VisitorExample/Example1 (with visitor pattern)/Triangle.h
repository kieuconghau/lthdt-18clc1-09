#pragma once

#include "Shape.h"

class Triangle
{
public:
	Triangle(float a, float b, float c);
	void accept(ShapeVisitor* v) ;
	float get_a();
	float get_b();
	float get_c();
private:
	float a,b,c;
};

