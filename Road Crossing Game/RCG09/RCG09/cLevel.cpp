#include "cLevel.h"

cLevel::cLevel()
{
	this->LaneCount = 0;
	this->ObjectCounts = nullptr;
	this->Lanes = nullptr;
	this->TrafficLights = nullptr;
}

cLevel::~cLevel()
{
	for (unsigned int i = 0; i < this->LaneCount; i++)
	{
		if (this->TrafficLights[i] != nullptr)
			delete this->TrafficLights[i];
	}
	delete[] this->TrafficLights;

	for (unsigned int i = 0; i < this->LaneCount; i++)
	{
		for (unsigned int j = 0; j < this->ObjectCounts[i]; j++)
		{
			delete this->Lanes[i][j];
		}
		delete[] this->Lanes[i];
	}
	delete[] this->Lanes;

	if (this->ObjectCounts != nullptr)
		delete[] this->ObjectCounts;
}

void cLevel::set_up(unsigned int laneCount, vector<ecObjectType> objectTypes, vector<ecDirection> directions, vector<ecColor> colors, vector<unsigned int> objectCounts, unsigned int timeRed, unsigned int timeYellow, unsigned int timeGreen)
{
	if (this->TrafficLights != nullptr)
	{
		for (unsigned int i = 0; i < this->LaneCount; i++)
		{
			if (this->TrafficLights[i] != nullptr)
				delete this->TrafficLights[i];
		}
		delete[] this->TrafficLights;
	}

	if (this->Lanes != nullptr)
	{
		for (unsigned int i = 0; i < this->LaneCount; i++)
		{
			for (unsigned int j = 0; j < this->ObjectCounts[i]; j++)
			{
				delete this->Lanes[i][j];
			}
			delete[] this->Lanes[i];
		}
		delete[] this->Lanes;
	}

	if (this->ObjectCounts != nullptr)
	{
		delete[] this->ObjectCounts;
	}

	this->LaneCount = laneCount;

	this->ObjectCounts = new unsigned int[this->LaneCount];
	for (unsigned int i = 0; i < this->LaneCount; i++)
	{
		this->ObjectCounts[i] = objectCounts[i];
	}

	this->Lanes = new cObject**[this->LaneCount];
	for (unsigned int i = 0; i < this->LaneCount; i++)
	{
		this->Lanes[i] = new cObject*[this->ObjectCounts[i]];
		if (objectTypes[i] == ecObjectType::CAR)
		{
			for (unsigned int j = 0; j < this->ObjectCounts[i]; j++)
			{
				this->Lanes[i][j] = cVehicleFactory::create(cVehicleType::CAR, directions[i], colors[i],
					directions[i] == ecDirection::RIGHT ?
					cLevel::LEFT_LIMIT + j * ((cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT) / this->ObjectCounts[i]) :
					directions[i] == ecDirection::LEFT ?
					cLevel::RIGHT_LIMIT - j * ((cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT) / this->ObjectCounts[i]) :
					throw,
					cLevel::TOP_LIMIT + (i + 1) * (cLevel::LANE_DISTANCE + 1));
			}
		}
		else if (objectTypes[i] == ecObjectType::TRUCK)
		{
			for (unsigned int j = 0; j < this->ObjectCounts[i]; j++)
			{
				this->Lanes[i][j] = cVehicleFactory::create(cVehicleType::TRUCK, directions[i], colors[i],
					directions[i] == ecDirection::RIGHT ?
					cLevel::LEFT_LIMIT + j * ((cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT) / this->ObjectCounts[i]) :
					directions[i] == ecDirection::LEFT ?
					cLevel::RIGHT_LIMIT - j * ((cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT) / this->ObjectCounts[i]) :
					throw,
					cLevel::TOP_LIMIT + (i + 1) * (cLevel::LANE_DISTANCE + 1));
			}
		}
		else if (objectTypes[i] == ecObjectType::TRAIN)
		{
			for (unsigned int j = 0; j < this->ObjectCounts[i]; j++)
			{
				this->Lanes[i][j] = cVehicleFactory::create(cVehicleType::TRAIN, directions[i], colors[i],
					directions[i] == ecDirection::RIGHT ?
					cLevel::LEFT_LIMIT + j * ((cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT) / this->ObjectCounts[i]) :
					directions[i] == ecDirection::LEFT ?
					cLevel::RIGHT_LIMIT - j * ((cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT) / this->ObjectCounts[i]) :
					throw,
					cLevel::TOP_LIMIT + (i + 1) * (cLevel::LANE_DISTANCE + 1));
			}
		}
		else if (objectTypes[i] == ecObjectType::BIRD)
		{
			for (unsigned int j = 0; j < this->ObjectCounts[i]; j++)
			{
				this->Lanes[i][j] = cAnimalFactory::create(ecAnimalType::BIRD, directions[i], colors[i],
					directions[i] == ecDirection::RIGHT ?
					cLevel::LEFT_LIMIT + j * ((cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT) / this->ObjectCounts[i]) :
					directions[i] == ecDirection::LEFT ?
					cLevel::RIGHT_LIMIT - j * ((cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT) / this->ObjectCounts[i]) :
					throw,
					cLevel::TOP_LIMIT + (i + 1) * (cLevel::LANE_DISTANCE + 1));
			}
		}
		else if (objectTypes[i] == ecObjectType::DINOSAUR)
		{
			for (unsigned int j = 0; j < this->ObjectCounts[i]; j++)
			{
				this->Lanes[i][j] = cAnimalFactory::create(ecAnimalType::DINOSAUR, directions[i], colors[i],
					directions[i] == ecDirection::RIGHT ?
					cLevel::LEFT_LIMIT + j * ((cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT) / this->ObjectCounts[i]) :
					directions[i] == ecDirection::LEFT ?
					cLevel::RIGHT_LIMIT - j * ((cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT) / this->ObjectCounts[i]) :
					throw,
					cLevel::TOP_LIMIT + (i + 1) * (cLevel::LANE_DISTANCE + 1));
			}
		}
		else
			throw;
	}

	/* Traffic light */
	this->TrafficLights = new cTrafficLight*[this->LaneCount];
	for (unsigned int i = 0; i < this->LaneCount; i++)
	{
		if (objectTypes[i] == ecObjectType::CAR || objectTypes[i] == ecObjectType::TRUCK || objectTypes[i] == ecObjectType::TRAIN)
		{
			/*this->TrafficLights[i] = new cTrafficLight(directions[i] == ecDirection::RIGHT ?
				cLevel::RIGHT_LIMIT + 1 : directions[i] == ecDirection::LEFT ? cLevel::LEFT_LIMIT - cTrafficLight::N : throw,
				cLevel::TOP_LIMIT + (i + 1) * (cLevel::LANE_DISTANCE + 1), timeRed, timeYellow, timeGreen);*/
			this->TrafficLights[i] = new cTrafficLight(directions[i] == ecDirection::RIGHT ?
				cLevel::RIGHT_LIMIT + 1 : directions[i] == ecDirection::LEFT ? cLevel::LEFT_LIMIT - 3 : throw,
				cLevel::TOP_LIMIT + (i + 1) * (cLevel::LANE_DISTANCE + 1), timeRed, timeYellow, timeGreen);
		}
		else
			this->TrafficLights[i] = nullptr;
	}
}

void cLevel::draw()
{
	text_color(cLevel::BORDER_COLOR);
	
	goto_xy(cLevel::LEFT_LIMIT, cLevel::TOP_LIMIT);
	cout << char(201);
	for (unsigned int i = 0; i < cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT - 1; i++)
		cout << char(205);
	cout << char(187);

	for (int i = 0; i < cLevel::BOT_LIMIT - cLevel::TOP_LIMIT - 1; i++)
	{
		goto_xy(cLevel::LEFT_LIMIT, i + cLevel::TOP_LIMIT + 1);
		cout << char(186);
		goto_xy(cLevel::RIGHT_LIMIT, i + cLevel::TOP_LIMIT + 1);
		cout << char(186);
	}

	goto_xy(cLevel::LEFT_LIMIT, cLevel::BOT_LIMIT);
	cout << char(200);
	for (unsigned int i = 0; i < cLevel::RIGHT_LIMIT - cLevel::LEFT_LIMIT - 1; i++)
		cout << char(205);
	cout << char(188);

	text_color();
	goto_xy(0, 0);
}

void cLevel::start()
{
	this->draw();

	unsigned int time = 0;
	while (true)
	{
		time++;

		for (unsigned int i = 0; i < this->LaneCount; i++)
		{
			if (this->TrafficLights[i] != nullptr)
				this->TrafficLights[i]->change_light_color(time);

			for (unsigned int j = 0; j < this->ObjectCounts[i]; j++)
			{
				if (this->TrafficLights[i] == nullptr)
				{
					this->Lanes[i][j]->move(cLevel::LEFT_LIMIT, cLevel::RIGHT_LIMIT);
				}
				else
				{
					if (this->TrafficLights[i]->isGreenLight(time))
					{
						this->Lanes[i][j]->move(cLevel::LEFT_LIMIT, cLevel::RIGHT_LIMIT);
					}
					else if (this->TrafficLights[i]->isYellowLight(time))
					{
						this->Lanes[i][j]->move(cLevel::LEFT_LIMIT, cLevel::RIGHT_LIMIT);
					}
				}
			}
		}

		Sleep(50);
		if (GetAsyncKeyState(VK_RETURN) != 0)
			break;
	}
}
