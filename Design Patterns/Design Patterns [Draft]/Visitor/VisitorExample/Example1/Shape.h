#pragma once

#include <iostream>

using namespace std;

class Shape
{
public:
	virtual void display() = 0;
	virtual float calculate_area() = 0;
	virtual float calculate_perimeter() = 0;
};

