#pragma once

#include <vector>
using namespace std;

#include "cObject.h"
#include "cPeople.h"
#include "cAnimalFactory.h"
#include "cAnimal.h"
#include "cBird.h"
#include "cDinosaur.h"
#include "cVehicleFactory.h"
#include "cVehicle.h"
#include "cCar.h"
#include "cTruck.h"
#include "cTrafficLight.h"

class cLevel
{
public:
	/* Level setting */		
	static const unsigned int MAX_LEVEL = 2;

	/* Initial objects's location setting */
	static const unsigned int TOP_LIMIT = 5;
	static const unsigned int BOT_LIMIT = 30;
	static const unsigned int LEFT_LIMIT = 20;
	static const unsigned int RIGHT_LIMIT = 120;
	static const unsigned int LANE_DISTANCE = 2;
	static const ecColor BORDER_COLOR = ecColor::WHITE;

	cLevel();
	~cLevel();

	void set_up(unsigned int laneCount, vector<ecObjectType> objectTypes, vector<ecDirection> directions, vector<ecColor> colors, vector<unsigned int> objectCounts);
	void draw();
	void start();

private:
	unsigned int LaneCount;
	unsigned int* ObjectCounts;
	cObject*** Lanes;
	cObject** TrafficLights;
};
