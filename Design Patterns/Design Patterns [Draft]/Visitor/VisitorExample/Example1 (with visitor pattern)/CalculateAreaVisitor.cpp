#include "CalculateAreaVisitor.h"
#include "Triangle.h"
#include "Rectangle.h"

CalculateAreaVisitor::CalculateAreaVisitor()
{
	result = 0;
}

void CalculateAreaVisitor::visit_triangle(Triangle* src)
{
	float a = src->get_a();
	float b = src->get_b();
	float c = src->get_c();

	float p = (a + b + c) / 2;

	result = sqrt(p * (p - a) * (p - b) * (p - c));
}

void CalculateAreaVisitor::visit_rectangle(Rectangle* src)
{
	result = src->get_height() * src->get_width();
}

float CalculateAreaVisitor::get_result()
{
	return result;
}