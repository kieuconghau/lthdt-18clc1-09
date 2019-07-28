#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "CalculateAreaVisitor.h"
#include "CalculatePerimeterVisitor.h"
#include "DisplayVisitor.h"
#include "ShapeVisitor.h"
#include "Triangle.h"
#include "Rectangle.h"


int main()
{
	Triangle ABC(3, 4, 5);
	Rectangle MNPQ(3, 4);

	DisplayVisitor dv;
	ABC.accept(&dv);
	cout << endl;
	MNPQ.accept(&dv);
	cout << endl;

	CalculateAreaVisitor cav;
	ABC.accept(&cav);
	cout << "Area of ABC: " << cav.get_result() << endl;;
	MNPQ.accept(&cav);
	cout << "Area of MNPQ: " << cav.get_result() << endl;

	CalculatePerimeterVisitor cpv;
	ABC.accept(&cpv);
	cout << "Perimeter of ABC: " << cpv.get_result() << endl;
	MNPQ.accept(&cpv);
	cout << "Perimeter of MNPQ: " << cpv.get_result() << endl;

	return 0;
}