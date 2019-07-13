#include "cFixedObjectLane.h"

cFixedObjectLane::cFixedObjectLane(cObject::ecType objectType, ecDirection direction, ecColor objectColor, int y, int objectCount
	, int leftLimit, int rightLimit, int virtualDistance)
	: cLane(objectType, y, objectCount, leftLimit, rightLimit, virtualDistance)
{
	this->FixedObjectType = objectType;

	this->FixedObjects = new cFixedObject*[this->ObjectCount];
	
	srand(time(nullptr));
	int temp = this->LeftLimit + rand() % (rightLimit - leftLimit + 1);
	vector<int> x;
	x.push_back(temp);

	bool duplicated;
	for (int i = 0; i < this->ObjectCount; i++)
	{
		this->FixedObjects[i] = cObjectFactory::create(this->FixedObjectType, direction, objectColor, x[i], y);

		if (i == this->ObjectCount - 1)
			break;

		while (true)
		{
			duplicated = false;
			for (int i = 0; i < x.size(); i++)
			{
				if (temp == x[i])
				{
					duplicated = true;
					temp = this->LeftLimit + rand() % (rightLimit - leftLimit + 1);
					break;
				}
			}

			if (duplicated == false)
			{
				x.push_back(temp);
				break;
			}
		}
	}
}

cFixedObjectLane::~cFixedObjectLane()
{
	for (int i = 0; i < this->ObjectCount; i++)
		delete[] this->FixedObjects[i];
	delete this->FixedObjects;
}

void cFixedObjectLane::draw()
{
	cLane::draw();

	for (int i = 0; i < this->ObjectCount; i++)
	{
		this->FixedObjects[i]->draw(this->LeftLimit, this->RightLimit);
	}
}

