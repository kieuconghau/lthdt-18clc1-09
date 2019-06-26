#include "cVehicleFactory.h"

cVehicle* cVehicleFactory::create(cVehicleType type, cDirection direction, cColor color, unsigned int x, unsigned int y)
{
	switch (type)
	{
	case cVehicleType::CAR:
		return (new cCar(direction, color, x, y));
	case cVehicleType::TRUCK:
		return (new cTruck(direction, color, x, y));
	default:
		throw;
	}
}
