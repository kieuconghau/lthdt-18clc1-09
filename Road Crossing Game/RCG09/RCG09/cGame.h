#pragma once

#include "Graphic.h"
#include "Screen.h"
#include "cTextBox.h"
#include "cLevel.h"
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

class cGame
{
public:
	cGame();
	~cGame();

	void draw();
	void start();

private:
	cLevel Levels[cLevel::MAX_LEVEL];
	unsigned int CurrentLevel;
	//cPeople People;
};

