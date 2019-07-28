#include "Rectangle.h"

Rectangle::Rectangle(float width, float height)
{
	this->width = width;
	this->height = height;
}


void Rectangle::display()
{
	cout << "Width: " << width << "/Height: " << height;
}

float Rectangle::calculate_area()
{
	return width * height;
}

float Rectangle::calculate_perimeter()
{
	return (width + height) * 2;
}

