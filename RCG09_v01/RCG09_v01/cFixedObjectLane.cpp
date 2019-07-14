#include "cFixedObjectLane.h"

cFixedObjectLane::cFixedObjectLane(cObject::ecType objectType, ecDirection direction, ecColor objectColor, int y, int objectCount
	, int leftLimit, int rightLimit, int virtualDistance)
	: cLane(objectType, y, objectCount, leftLimit, rightLimit, virtualDistance)
{
	this->FixedObjectType = objectType;

	this->FixedObjects = new cFixedObject*[this->ObjectCount];
	
	srand(unsigned(time(nullptr)));
	int temp = this->LeftLimit + rand() % (rightLimit - leftLimit + 1);
	vector<int> x;
	x.push_back(temp);

	/////////////////////TRICKY//////////////////////
	const int MAX_COIN = 1;
	/////////////////////////////////////////////////

	bool duplicated;
	cObject::ecType type;
	for (int i = 0; i < this->ObjectCount; i++)
	{
		/////////////////////TRICKY//////////////////////
		if (this->FixedObjectType == cObject::ecType::MIX_STONE_AND_COIN)
		{
			if (i < MAX_COIN)
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

		this->FixedObjects[i] = cObjectFactory::create(type, direction, objectColor, x[i], y);

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

void cFixedObjectLane::impact(cPeople* people)
{
	if (people->is_in_line(this->Y)) {

		for (int i = 0; i < this->ObjectCount; i++) {

			if (people->is_impacted(this->FixedObjects[i])) {
				if (this->FixedObjects[i]->is_edible()) {
					if (!this->FixedObjects[i]->was_eaten()) {
						this->FixedObjects[i]->is_eaten();
					}
				}
				else {
					people->move_back();
				}
				return;
			}
		}
	}
}

void cFixedObjectLane::change_people_brick(cPeople* people)
{
	if (this->ObjectCount != 0) {
		people->change_brick(this->FixedObjects[0]->brick_shape(), this->FixedObjects[0]->brick_color());
	}
}

