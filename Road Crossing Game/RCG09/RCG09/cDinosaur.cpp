#include "cDinosaur.h"

cDinosaur::cDinosaur(cDirection direction, cColor color, unsigned int x, unsigned int y) : cAnimal(cDinosaur::N, direction, color, x, y)
{
	if (direction == cDirection::RIGHT)
	{
		this->Shape[0] = char(32);
		this->Shape[1] = char(220);
		this->Shape[2] = char(219);
		this->Shape[3] = char(219);
		this->Shape[4] = char(223);
	}
	else if (direction == cDirection::LEFT)
	{
		this->Shape[0] = char(223);
		this->Shape[1] = char(219);
		this->Shape[2] = char(219);
		this->Shape[3] = char(220);
		this->Shape[4] = char(32);
	}
	else
		throw;
}

void cDinosaur::draw()
{
	text_color(this->Color);

	for (int i = 0; i < cDinosaur::N; i++)
	{
		goto_xy(this->X[i], this->Y[i]);
		cout << this->Shape[i];
	}

	text_color();
	goto_xy(0, 0);
}

void cDinosaur::move(unsigned int leftLimit, unsigned int rightLimit)
{
	if (this->Direction == cDirection::RIGHT)
	{
		for (int i = 0; i < cDinosaur::N; i++)
		{
			if (++this->X[i] == rightLimit + 1)
				this->X[i] = leftLimit;
		}
		if (this->X[cDinosaur::N - 1] >= leftLimit && this->X[cDinosaur::N - 1] <= rightLimit)
			this->draw();
	}
	else if (this->Direction == cDirection::LEFT)
	{
		for (int i = 0; i < cDinosaur::N; i++)
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

void cDinosaur::tell()
{
	PlaySound(TEXT("dino.wav"), NULL, SND_FILENAME | SND_ASYNC);
}