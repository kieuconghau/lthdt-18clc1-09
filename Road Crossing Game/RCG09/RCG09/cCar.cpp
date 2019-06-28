#include "cCar.h"

const char cCar::Shapes[cCar::N] = { char(32), char(220), char(219), char(219), char(220) };

cCar::cCar(ecDirection direction, ecColor color, unsigned int x, unsigned int y) : cVehicle(cCar::N, direction, color, x, y) { }

void cCar::draw(unsigned int leftLimit, unsigned int rightLimit)
{
	text_color(this->Color);
		
	for (unsigned int i = 0; i < cCar::N; i++)
	{
		goto_xy(this->X[i], this->Y[i]);
		if (this->X[i] > leftLimit && this->X[i] < rightLimit)
			cout << cCar::Shapes[cCar::N - i - 1];
	}

	text_color();
	goto_xy(0, 0);
}

void cCar::move(unsigned int leftLimit, unsigned int rightLimit)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < cCar::N; i++)
		{
			if (++this->X[i] == rightLimit)
				this->X[i] = leftLimit + 1;
		}
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		for (int i = 0; i < cCar::N; i++)
		{
			if (--this->X[i] == leftLimit)
				this->X[i] = rightLimit - 1;
		}
	}
	else
		throw;

	this->draw(leftLimit, rightLimit);
}