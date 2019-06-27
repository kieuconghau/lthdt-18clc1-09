#include "cLevel.h"

cLevel::cLevel()
{
	this->LaneCount = 0;
	this->ObjectCounts = nullptr;
	this->Lanes = nullptr;
}

cLevel::~cLevel()
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

	if (this->ObjectCounts != nullptr)
		delete[] this->ObjectCounts;
}

void cLevel::set_up(unsigned int laneCount, vector<ecObjectType> objectTypes, vector<ecDirection> directions, vector<ecColor> colors, vector<unsigned int> objectCounts)
{
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
		delete[] this->ObjectCounts;


	this->LaneCount = laneCount;

	this->ObjectCounts = new unsigned int[this->LaneCount];
	for (unsigned int i = 0; i < this->LaneCount; i++)
		this->ObjectCounts[i] = objectCounts[i];

	this->Lanes = new cObject * *[this->LaneCount];
	for (unsigned int i = 0; i < this->LaneCount; i++)
	{
		this->Lanes[i] = new cObject * [this->ObjectCounts[i]];
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

	while (true)
	{
		for (unsigned int i = 0; i < this->LaneCount; i++)
			for (unsigned int j = 0; j < this->ObjectCounts[i]; j++)
				this->Lanes[i][j]->move(cLevel::LEFT_LIMIT, cLevel::RIGHT_LIMIT);

		Sleep(50);
		if (GetAsyncKeyState(VK_ESCAPE) != 0)
			break;
	}
}
