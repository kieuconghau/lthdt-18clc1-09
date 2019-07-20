#include "Triangle.h"
#include "ShapeVisitor.h"

Triangle::Triangle(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

void Triangle::accept(ShapeVisitor* v)
{
	v->visit_triangle(this);
}

float Triangle::get_a()
{
	return a;
}

float Triangle::get_b()
{
	return b;
}

float Triangle::get_c()
{
	return c;
}