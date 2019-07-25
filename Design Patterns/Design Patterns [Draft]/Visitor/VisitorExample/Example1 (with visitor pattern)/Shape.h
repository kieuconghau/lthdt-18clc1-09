#pragma once

#include <iostream>

using namespace std;

class ShapeVisitor;
//class CalculateAreaVisitor;
//class CalculatePerimeterVisitor;
//class CalculateDisplayVisitor;

class Shape
{
public:
	virtual void accept(ShapeVisitor* v) = 0;
};

