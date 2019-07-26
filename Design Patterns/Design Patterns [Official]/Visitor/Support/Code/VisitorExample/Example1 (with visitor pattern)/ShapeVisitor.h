#pragma once

#include <iostream>

using namespace std;

class Shape;
class Triangle;
class Rectangle;

class ShapeVisitor
{
public:
	virtual void visit_triangle(Triangle* src) = 0;
	virtual void visit_rectangle(Rectangle* src) = 0;
};


