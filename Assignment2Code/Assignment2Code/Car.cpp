#include "Car.h"

Oil Car::SwapOil(Oil NewOil)
{
    // TODO - implement Car::SwapOil
    throw "Not yet implemented";
}

OilFilter Car::SwapOilFilter(OilFilter NewOilFilter)
{
    // TODO - implement Car::SwapOilFilter
    throw "Not yet implemented";
}

AirFilter Car::SwapAirFilter(AirFilter NewAirFilter)
{
    // TODO - implement Car::SwapAirFilter
    throw "Not yet implemented";
}

Tires Car::SwapTires(Tires NewTires)
{
    // TODO - implement Car::SwapTires
    throw "Not yet implemented";
}

void Car::AddOil(Oil * aOil)
{
	CarOil = aOil;
}

void Car::DelOil()
{
	if (CarOil != NULL) {
		CarOil = NULL;
	}
}

void Car::AddOilFilter(OilFilter * aOilFilter)
{
	CarOilFilter = aOilFilter;
}

void Car::DelOilFilter()
{
	if (CarOilFilter != NULL) {
		CarOilFilter = NULL;
	}
}

void Car::AddAirFilter(AirFilter * aAirFilter)
{
	CarAirFilter = aAirFilter;
}

void Car::DelAirFilter()
{
	if (CarAirFilter != NULL) {
		CarAirFilter = NULL;
	}
}

void Car::AddTire(Tires * aTire, int index)
{
	CarTires[index] = aTire;
}

void Car::DelTire(int index)
{
	if (CarTires[index] != NULL) {
		CarTires[index] = NULL;
	}
}

bool Car::CheckTiresForWear()
{
    // TODO - implement Car::CheckTiresForWear
    throw "Not yet implemented";
}

void Car::RotateTires()
{
    // TODO - implement Car::RotateTires
    throw "Not yet implemented";
}

Car::Car()
{
    // TODO - implement Car::Car
    throw "Not yet implemented";
}

Car::~Car()
{
    // TODO - implement Car::~Car
    throw "Not yet implemented";
}
