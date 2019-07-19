#include "Rectangle.h"
#include "Triangle.h"

int main()
{
	Triangle ABC(3 , 4 , 5);
	Rectangle MNPQ ( 3 , 4);

	cout << "ABC: ";
	ABC.display();
	cout << endl;
	cout << "MNPQ: ";
	MNPQ.display();
	cout << endl;

	cout << "Area of ABC: " << ABC.calculate_area() << endl;
	cout << "Area of MNPQ: " << MNPQ.calculate_area() << endl;

	cout << "Perimeter of ABC: " << ABC.calculate_perimeter() << endl;
	cout << "Perimeter of MNPQ: " << MNPQ.calculate_perimeter() << endl;

	return 0;
}