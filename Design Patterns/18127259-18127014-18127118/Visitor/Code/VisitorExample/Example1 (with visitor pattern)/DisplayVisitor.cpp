#include "DisplayVisitor.h"
#include "Triangle.h"
#include "Rectangle.h"

void DisplayVisitor::visit_triangle(Triangle* src)
{
	cout << "a: " << src->get_a() << "/b: " << src->get_b() << "/c: " << src->get_c();
}

void DisplayVisitor::visit_rectangle(Rectangle* src)
{
	cout << "width: " << src->get_width() << "/height: " << src->get_height();
}
