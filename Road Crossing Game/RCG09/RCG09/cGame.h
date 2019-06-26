#pragma once

#include "Graphic.h"
#include "Screen.h"
#include "cTextBox.h"
#include "cPeople.h"
#include "cObstacle.h"
#include "cAnimalFactory.h"
#include "cAnimal.h"
#include "cBird.h"
#include "cDinosaur.h"
#include "cVehicleFactory.h"
#include "cVehicle.h"
#include "cCar.h"
#include "cTruck.h"
#include "cTrafficLight.h"

class cGame
{
public:
	static const unsigned int MAX_LEVEL = 5;

	cGame();
	~cGame();

	void draw();

private:
	unsigned int OBJECT_COUNT;
	unsigned int OBJECT_DISTANCE;
	unsigned int LEVEL;
	/*cVehicle** lane1;
	cVehicle** lane2;
	cAnimal** lane3;
	cAnimal** lane4;*/
	cObstacle*** lanes;
	cPeople* people;
};