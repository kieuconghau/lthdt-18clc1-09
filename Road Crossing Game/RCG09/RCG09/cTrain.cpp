#include "cTrain.h"

const char cTrain::Shapes[cTrain::N] = { char(32), char(219), char(219), char(219), char(219), char(219), char(205), char(219), char(219), char(219), char(219), char(219), char(205), char(219), char(219), char(219), char(219), char(219), char(205), char(219), char(219), char(219), char(219), char(219), char(205), char(219), char(219), char(219), char(219), char(219), char(205), char(219), char(219), char(219), char(219), char(219), char(205), char(219), char(219), char(219), char(219), char(219), char(205), char(219), char(219), char(219), char(219), char(219), char(205), char(219), char(219), char(219), char(219), char(219), char(205), char(219), char(219), char(219), char(219), char(220) };

cTrain::cTrain(ecDirection direction, ecColor color, unsigned int x, unsigned int y) : cVehicle(cTrain::N, direction, color, x, y) { }

void cTrain::draw(unsigned int leftLimit, unsigned int rightLimit)
{
	text_color(this->Color);

	for (unsigned int i = 0; i < cTrain::N; i++)
	{
		goto_xy(this->X[i], this->Y[i]);
		if (this->X[i] > leftLimit && this->X[i] < rightLimit)
			cout << cTrain::Shapes[cTrain::N - i - 1];
	}

	text_color();
	goto_xy(0, 0);
}

void cTrain::move(unsigned int leftLimit, unsigned int rightLimit)
{
	if (this->Direction == ecDirection::RIGHT)
	{
		for (int i = 0; i < cTrain::N; i++)
		{
			if (++this->X[i] == rightLimit)
				this->X[i] = leftLimit + 1;
		}
	}
	else if (this->Direction == ecDirection::LEFT)
	{
		for (int i = 0; i < cTrain::N; i++)
		{
			if (--this->X[i] == leftLimit)
				this->X[i] = rightLimit - 1;
		}
	}
	else
		throw;

	this->draw(leftLimit, rightLimit);
}