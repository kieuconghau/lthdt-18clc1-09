#include "cFixedObjectLane.h"

cFixedObjectLane::cFixedObjectLane(cObject::ecType objectType, ecDirection direction, ecColor objectColor, int y, int objectCount
	, int leftLimit, int rightLimit, int virtualDistance)
	: cLane(objectType, y, objectCount, leftLimit, rightLimit, virtualDistance)
{
	this->FixedObjectType = objectType;

	this->FixedObjects = new cFixedObject*[this->ObjectCount];
	
	vector<int> x;
	int temp;

	/////////////////////TRICKY//////////////////////
	const int MAX_COIN = 1;
	/////////////////////////////////////////////////

	bool duplicated;
	cObject::ecType type;
	for (int i = 0; i < this->ObjectCount; i++)
	{
		// Type
		/////////////////////TRICKY//////////////////////
		if (this->FixedObjectType == cObject::ecType::MIX_STONE_AND_COIN)
		{
			if (i >= this->ObjectCount - MAX_COIN)
			{
				type = cObject::ecType::FE_COIN;
				objectColor = ecColor::YELLOW;
			}
			else
			{
				type = cObject::ecType::FI_STONE;
				objectColor = ecColor::GREY;
			}
		}
		else
		{
			type = this->FixedObjectType;
		}
		/////////////////////////////////////////////////

		// Random x[i]
		while (true)
		{
			temp = this->LeftLimit + rand() % (this->RightLimit - this->LeftLimit + 1);
			
			duplicated = false;
			for (int j = 0; j < x.size(); j++)
			{
				if (this->FixedObjectType == cObject::ecType::MIX_STONE_AND_COIN)
				{
					if (direction == ecDirection::RIGHT)
					{
						if (temp <= x[j] && temp >= x[j] - cStone::N + 1)
						{
							duplicated = true;
							break;
						}
					}
					else if (direction == ecDirection::LEFT)
					{
						if (temp >= x[j] && temp <= x[j] + cStone::N - 1)
						{
							duplicated = true;
							break;
						}
					}
					else
						throw;
				}
				else
				{
					if (temp == x[j])
					{
						duplicated = true;
						break;
					}
				}
			}

			if (duplicated == false)
			{
				x.push_back(temp);
				break;
			}
		}

		// Create an object with type and x[i]
		this->FixedObjects[i] = cObjectFactory::create(type, direction, objectColor, x[i], y);
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

int cFixedObjectLane::impact(cPeople* people)
{
	if (people->is_in_line(this->Y)) {

		for (int i = 0; i < this->ObjectCount; i++) {

			if (people->is_impacted(this->FixedObjects[i])) {
				if (this->FixedObjects[i]->is_edible()) {
					if (!this->FixedObjects[i]->was_eaten()) {
						this->FixedObjects[i]->is_eaten();
						return 1;
					}
					else {
						return 0;
					}
				}
				else {
					people->move_back();
					return 0;
				}
			}
		}
	}
	return 0;
}

void cFixedObjectLane::change_people_brick(cPeople* people)
{
	if (this->ObjectCount != 0) {
		people->change_brick(this->FixedObjects[0]->brick_shape(), this->FixedObjects[0]->brick_color());
	}
}

void cFixedObjectLane::reset()
{
	for (int i = 0; i < this->ObjectCount;i++) {
		this->FixedObjects[i]->reset();
	}
}


