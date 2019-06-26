#include "cObstacle.h"

cObstacle::cObstacle()
{

}

cObstacle::~cObstacle()
{
	if (this->X != nullptr)
		delete[] this->X;

	if (this->Y != nullptr)
		delete[] this->Y;
}
