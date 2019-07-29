#pragma once

#include "ShapeVisitor.h"

class CalculateAreaVisitor: public ShapeVisitor
{
public:
	CalculateAreaVisitor();
	void visit_triangle(Triangle* src);
	void visit_rectangle(Rectangle* src);
	float get_result();
private:
	float result;
};


