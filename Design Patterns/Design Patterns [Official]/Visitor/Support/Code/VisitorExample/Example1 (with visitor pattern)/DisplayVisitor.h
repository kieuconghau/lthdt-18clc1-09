#pragma once

#include "ShapeVisitor.h"

class DisplayVisitor : public ShapeVisitor
{
public:
	void visit_triangle(Triangle* src);
	void visit_rectangle(Rectangle* src);
};