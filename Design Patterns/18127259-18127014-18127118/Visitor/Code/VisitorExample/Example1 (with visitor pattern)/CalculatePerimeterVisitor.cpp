#include "CalculatePerimeterVisitor.h"
#include "Triangle.h"
#include "Rectangle.h"

CalculatePerimeterVisitor::CalculatePerimeterVisitor()
{
	result = 0;
}

void CalculatePerimeterVisitor::visit_triangle(Triangle* src)
{
	result = src->get_a() + src->get_b() + src->get_c();
}

void CalculatePerimeterVisitor::visit_rectangle(Rectangle* src)
{
	result = (src->get_height() + src->get_width()) * 2;
}

float CalculatePerimeterVisitor::get_result()
{
	return result;
}
