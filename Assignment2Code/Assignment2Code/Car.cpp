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
	return true;
}

void Car::RotateTires()
{
	Tires* temp;
	temp = this->CarTires[1];
	this->CarTires[1] = this->CarTires[2];
	this->CarTires[2] = this->CarTires[3];
	this->CarTires[3] = this->CarTires[4];
	this->CarTires[4] = temp;
	cout << "I, the Car, have accepted a tire rotation" << endl;
	return;
}

Car::Car()
{
	Oil *oldOil = new Oil("icky old Oil", 10);
	OilFilter *oldOilFilter = new OilFilter();
	AirFilter *oldAirFilter = new AirFilter();
	Tires *oldTire1 = new Tires("Michelin", 19);
	Tires *oldTire2 = new Tires("Michelin", 19);
	Tires *oldTire3 = new Tires("Michelin", 19);
	Tires *oldTire4 = new Tires("Michelin", 19);

	AddOil(oldOil);
	AddOilFilter(oldOilFilter);
	AddAirFilter(oldAirFilter);
	AddTire(oldTire1, 1);
	AddTire(oldTire2, 2);
	AddTire(oldTire3, 3);
	AddTire(oldTire4, 4);
}

Car::~Car()
{
	DelOil();
	DelOilFilter();
	DelAirFilter();
	DelTire(0);
	DelTire(1);
	DelTire(2);
	DelTire(3);
}
