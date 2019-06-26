#include <iostream>
#include <windows.graphics.h>

using namespace std;

#include "cGame.h"

#include <vector>

int main()
{
	zoom_full_console_window();

	//screen_account();

	const unsigned int lane1Count = 9;
	const unsigned int lane2Count = 9;


	const unsigned int leftLimit = 20;
	const unsigned int rightLimit = 110;

	cVehicle** lane1 = new cVehicle*[lane1Count];
	for (int i = 0; i < lane1Count; i++)
		lane1[i] = cVehicleFactory::create(cVehicleType::TRUCK, cDirection::RIGHT, i % 2 == 0 ? cColor::BLUE : cColor::RED, rightLimit - i*10, 10);

	cVehicle** lane2 = new cVehicle*[lane2Count];
	for (int i = 0; i < lane2Count; i++)
		lane2[i] = cVehicleFactory::create(cVehicleType::CAR, cDirection::LEFT, i % 2 == 0 ? cColor::CYAN : cColor::YELLOW, leftLimit + i*10, 20);

	while (true)
	{
		for (unsigned int i = 0; i < lane1Count; i++)
			lane1[i]->move(leftLimit, rightLimit);

		for (unsigned int i = 0; i < lane2Count; i++)
			lane2[i]->move(leftLimit, rightLimit);

		Sleep(100);
		if (GetAsyncKeyState(VK_ESCAPE) != 0)
			break;
	}

	for (int i = 0; i < lane1Count; i++)
		delete lane1[i];
	delete[] lane1;

	for (int i = 0; i < lane2Count; i++)
		delete lane2[i];
	delete[] lane2;

	return 0;
}