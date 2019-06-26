#include "cVehicle.h"

cVehicle::cVehicle()
{
	this->X = nullptr;
	this->Y = nullptr;
	this->Direction = cDirection::RIGHT;
	this->Color = cColor::WHITE;
}

cVehicle::cVehicle(unsigned int n, cDirection direction, cColor color, unsigned int x, unsigned int y)
{
	this->X = new unsigned int[n];
	for (unsigned int i = 0; i < n; i++)
	{
		if (direction == cDirection::LEFT)
			this->X[i] = x + i;
		else if (direction == cDirection::RIGHT)
			this->X[i] = x + i - n + 1;
		else
			throw;
	}
	this->Y = new unsigned int[n];
	for (unsigned int i = 0; i < n; i++)
		this->Y[i] = y;
	this->Direction = direction;
	this->Color = color;
}

cVehicle::~cVehicle()
{
	if (this->X != nullptr)
		delete[] this->X;

	if (this->Y != nullptr)
		delete[] this->Y;
}
