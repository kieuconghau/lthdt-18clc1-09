#include "cTruck.h"

const char cTruck::Shapes[cTruck::N] = { char(32), char(220), char(220), char(219), char(219) };

cTruck::cTruck(ecDirection direction, ecColor color, unsigned int x, unsigned int y) : cVehicle(cTruck::N, direction, color, x, y) { }

void cTruck::draw(unsigned int leftLimit, unsigned int rightLimit)
{
	text_color(this->Color);

	for (int i = 0; i < cTruck::N; i++)
	{
		goto_xy(this->X[i], this->Y[i]);
		if (this->X[i] > leftLimit && this->X[i] < rightLimit)
			cout << this->Shapes[cTruck::N - i - 1];
	}

	text_color();
	goto_xy(0, 0);
}

void cTruck::move(unsigned int leftLimit, unsigned int rightLimit)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < cTruck::N; i++)
		{
			if (++this->X[i] == rightLimit)
				this->X[i] = leftLimit + 1;
		}
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		for (int i = 0; i < cTruck::N; i++)
		{
			if (--this->X[i] == leftLimit)
				this->X[i] = rightLimit - 1;
		}
	}
	else
		throw;

	this->draw(leftLimit, rightLimit);
}