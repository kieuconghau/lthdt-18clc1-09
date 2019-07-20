#include "Rectangle.h"
#include "ShapeVisitor.h"

Rectangle::Rectangle(float width, float height)
{
	this->width = width;
	this->height = height;
}

void Rectangle::accept(ShapeVisitor* v)
{
	v->visit_rectangle(this);
}

float Rectangle::get_height()
{

	return height;
}

float Rectangle::get_width()
{
	return width;
}
