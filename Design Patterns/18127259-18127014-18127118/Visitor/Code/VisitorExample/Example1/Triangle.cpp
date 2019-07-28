#include "Triangle.h"

Triangle::Triangle(float a, float b, float c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

void Triangle::display()
{
	cout << "a: " << a << " / b: " << b << " / c: " << c << endl;
}

float Triangle::calculate_area()
{
	float p = (a + b + c) / 2;

	return sqrtf(p * (p - a) * (p - b) * (p - c));
}

float Triangle::calculate_perimeter()
{
	return a +b + c;
}