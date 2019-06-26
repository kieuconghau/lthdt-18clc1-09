#include "cCar.h"

cCar::cCar(cDirection direction, cColor color, unsigned int x, unsigned int y) : cVehicle(cCar::N, direction, color, x, y)
{
	if (direction == cDirection::RIGHT)
	{
		this->Shape[0] = char(32);
		this->Shape[1] = char(220);
		this->Shape[2] = char(219);
		this->Shape[3] = char(219);
		this->Shape[4] = char(220);
	}
	else if (direction == cDirection::LEFT)
	{
		this->Shape[0] = char(220);
		this->Shape[1] = char(219);
		this->Shape[2] = char(219);
		this->Shape[3] = char(220);
		this->Shape[4] = char(32);
	}
	else
		throw;
}

void cCar::draw()
{
	text_color(this->Color);
		
	for (int i = 0; i < cCar::N; i++)
	{
		goto_xy(this->X[i], this->Y[i]);
		cout << this->Shape[i];
	}

	text_color();
	goto_xy(0, 0);
}

void cCar::move(unsigned int leftLimit, unsigned int rightLimit)
{
	if (this->Direction == cDirection::RIGHT)
	{
		for (int i = 0; i < cCar::N; i++)
		{
			if (++this->X[i] == rightLimit + 1)
				this->X[i] = leftLimit;
		}
		if (this->X[cCar::N - 1] >= leftLimit && this->X[cCar::N - 1] <= rightLimit)
			this->draw();
	}
	else if (this->Direction == cDirection::LEFT)
	{
		for (int i = 0; i < cCar::N; i++)
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
