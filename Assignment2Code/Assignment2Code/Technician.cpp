#include "Technician.h"

JobSheet Technician::ServiceCar(Car CarServicing)
{
    // TODO - implement Technician::ServiceCar
    throw "Not yet implemented";
}

void Technician::AddStores(Stores *aStores)
{
	theStores = aStores;
}

void Technician::DelStores()
{
	if (theStores != NULL) {
		theStores = NULL;
	}
}

void Technician::AddRecycling(Recycling *aRecycling)
{
	theRecycling = aRecycling;
}

void Technician::DelRecycling()
{
	if (theRecycling != NULL) {
		theRecycling = NULL;
	}
}

void Technician::AddGarbage(Garbage *aGarbage)
{
	theGarbage = aGarbage;
}

void Technician::DelGarbage()
{
	if (theGarbage != NULL) {
		theGarbage = NULL;
	}
}

void Technician::AddCar(Car *aCar)
{
	CurrentCar = aCar;
}

void Technician::DelCar()
{
	if (CurrentCar != NULL) {
		CurrentCar = NULL;
	}
}

void Technician::AddJobSheet(JobSheet *aJobSheet)
{
	CurrentJobSheet = aJobSheet;
}

void Technician::DelJobSheet()
{
	if (CurrentJobSheet != NULL) {
		CurrentJobSheet = NULL;
	}
}

Car Technician::GetCar()
{
    // TODO - implement Technician::GetCar
    throw "Not yet implemented";
}

Technician::Technician()
{
}

Technician::~Technician()
{
}
