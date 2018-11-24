#include "Car.h"

Oil Car::SwapOil(Oil NewOil)
{
	Oil* temp = this->CarOil;
    this->CarOil = &NewOil;
	cout << "I, the Car, have accepted an Oil swap" << endl;
	return *temp;
}

OilFilter Car::SwapOilFilter(OilFilter NewOilFilter)
{
	OilFilter* temp = this->CarOilFilter;
	this->CarOilFilter = &NewOilFilter;
	cout << "I, the Car, have accepted an OilFilter swap" << endl;
	return *temp;
}

AirFilter Car::SwapAirFilter(AirFilter NewAirFilter)
{
	AirFilter* temp = this->CarAirFilter;
	this->CarAirFilter = &NewAirFilter;
	cout << "I, the Car, have accepted an AirFilter swap" << endl;
	return *temp;
}

Tires Car::SwapTires(Tires NewTire, int index)
{
	Tires* temp = this->CarTires[index];
	this->CarTires[index] = &NewTire;
	cout << "I, the Car, have accepted a Tire swap for the "<< index << " tire" << endl;
	return *temp;
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
}

Car::~Car()
{
}
