#include "cMovableObjectLane.h"

cMovableObjectLane::cMovableObjectLane(cObject::ecType objectType, ecDirection direction, ecColor objectColor
	, int objectCount, int y, vector<int> time, int step, int leftLimit, int rightLimit, int virtualDistance)
	: cLane(objectType, y, objectCount, leftLimit, rightLimit, virtualDistance)
{
	this->MovableObjectType = objectType;
	this->Direction = direction;
	this->Step = step;

	// Traffic light
	if (this->is_vehicle_lane())
	{
		int x;
		if (this->Direction == ecDirection::RIGHT)
		{
			x = this->RightLimit;
			this->RightLimit -= cTrafficLight::N;
		}
		else if (this->Direction == ecDirection::LEFT)
		{
			x = this->LeftLimit;
			this->LeftLimit += cTrafficLight::N;
		}
		else
			throw;

		this->TrafficLight = new cTrafficLight(direction, x, y, time[0], time[1], time[2]);
	}
	else
	{
		this->TrafficLight = nullptr;
	}

	// Virtual distance
	int distance = ceil(float((this->RightLimit + this->VirtualDistance - this->LeftLimit + 1)) / this->ObjectCount);
	if (this->VirtualDistance == 0)	// Default
	{
		this->VirtualDistance = this->ObjectCount * distance + this->LeftLimit - 1 - this->RightLimit;
	}

	// Create objects
	this->MovableObjects = new cMovableObject * [this->ObjectCount];
	int x;
	for (int i = 0; i < this->ObjectCount; i++)
	{
		if (this->Direction == ecDirection::RIGHT)
		{
			x = this->RightLimit + this->VirtualDistance - i * distance;
		}
		else if (this->Direction == ecDirection::LEFT)
		{
			x = this->LeftLimit + i * distance;
		}
		else
			throw;

		this->MovableObjects[i] = cObjectFactory::create(objectType, direction, objectColor, x, y, step);
	}
}

cMovableObjectLane::~cMovableObjectLane()
{
	for (int i = 0; i < this->ObjectCount; i++)
		delete this->MovableObjects[i];
	delete[] this->MovableObjects;

	delete this->TrafficLight;
}


bool cMovableObjectLane::is_vehicle_lane()
{
	return this->MovableObjectType == cObject::ecType::MV_CAR
		|| this->MovableObjectType == cObject::ecType::MV_TRUCK;
	//|| this->MovableObjectType == cObject::ecType::MV_TRAIN;
}

void cMovableObjectLane::work()
{
	if (this->TrafficLight != nullptr)
	{
		this->TrafficLight->work();

		if (!this->TrafficLight->isRedLight())
		{
			for (int i = 0; i < this->ObjectCount; i++)
			{
				this->MovableObjects[i]->move(this->LeftLimit, this->RightLimit, this->VirtualDistance);
				this->MovableObjects[i]->draw(this->LeftLimit, this->RightLimit);
			}
		}
	}
	else
	{
		for (int i = 0; i < this->ObjectCount; i++)
		{
			this->MovableObjects[i]->move(this->LeftLimit, this->RightLimit, this->VirtualDistance);
			this->MovableObjects[i]->draw(this->LeftLimit, this->RightLimit);
		}
	}
}

void cMovableObjectLane::impact(cPeople* people)
{
	// Check if people is on this lane? (check y_cor)
	if (people->is_in_line(this->Y))
	{
		for (int i = 0; i < this->ObjectCount; i++)
		{
			// Check if people impact on one object on this lane (check x_cor)
			if (people->is_impacted(this->MovableObjects[i]))
			{
				people->die();
				return;
			}

			// Check if people impact on a traffic light on this light (check x_cor)
			if (this->TrafficLight != nullptr)
			{
				if (people->is_impacted(this->TrafficLight))
				{
					people->move_back();
				}
			}
		}
	}
}

void cMovableObjectLane::draw()
{
	cLane::draw();

	for (int i = 0; i < this->ObjectCount; ++i)
	{
		this->MovableObjects[i]->draw(this->LeftLimit, this->RightLimit);
	}
}

void cMovableObjectLane::change_people_brick(cPeople* people)
{
	if (this->ObjectCount != 0) {
		people->change_brick(this->MovableObjects[0]->brick_shape(), this->MovableObjects[0]->brick_color());
	}
}
