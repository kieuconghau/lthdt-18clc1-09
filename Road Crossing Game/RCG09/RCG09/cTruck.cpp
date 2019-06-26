#include "cTruck.h"

cTruck::cTruck(cDirection direction, cColor color, unsigned int x, unsigned int y) : cVehicle(cTruck::N, direction, color, x, y)
{
	if (direction == cDirection::RIGHT)
	{
		this->Shape[0] = char(32);
		this->Shape[1] = char(220);
		this->Shape[2] = char(220);
		this->Shape[3] = char(219);
		this->Shape[4] = char(219);
	}
	else if (direction == cDirection::LEFT)
	{
		this->Shape[0] = char(219);
		this->Shape[1] = char(219);
		this->Shape[2] = char(220);
		this->Shape[3] = char(220);
		this->Shape[4] = char(32);
	}
	else
		throw;
}

void cTruck::draw()
{
	text_color(this->Color);

	for (int i = 0; i < cTruck::N; i++)
	{
		goto_xy(this->X[i], this->Y[i]);
		cout << this->Shape[i];
	}

	text_color();
	goto_xy(0, 0);
}

void cTruck::move(unsigned int leftLimit, unsigned int rightLimit)
{
	if (this->Direction == cDirection::RIGHT)
	{
		for (int i = 0; i < cTruck::N; i++)
		{
			if (++this->X[i] == rightLimit + 1)
				this->X[i] = leftLimit;
		}
		if (this->X[cTruck::N - 1] >= leftLimit && this->X[cTruck::N - 1] <= rightLimit)
			this->draw();
	}
	else if (this->Direction == cDirection::LEFT)
	{
		for (int i = 0; i < cTruck::N; i++)
		{
			if (--this->X[i] == leftLimit - 1)
				this->X[i] = rightLimit;
		}
		if (this->X[0] >= leftLimit && this->X[0] <= rightLimit)
			this->draw();
	}
	else
		throw;
}
