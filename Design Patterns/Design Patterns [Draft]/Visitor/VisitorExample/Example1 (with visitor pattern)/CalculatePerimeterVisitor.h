#pragma once

#include "ShapeVisitor.h"

class CalculatePerimeterVisitor : public ShapeVisitor
{
public:
	CalculatePerimeterVisitor();
	void visit_triangle(Triangle* src);
	void visit_rectangle(Rectangle* src);
	float get_result();
private:
	float result;
};

