#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include "Oil.h"
#include "Tires.h"
#include "AirFilter.h"
#include "OilFilter.h"
#include "JobSheet.h"
#include "Car.h"
#include "Stores.h"
#include "Recycling.h"
#include "Garbage.h"
#include <iostream>

using namespace std;

class Technician
{

private:
    Oil* OilInventory;
    class Tires* TireInventory[4];
    AirFilter* AirFilterInventory;
	class OilFilter* OilFilterInventory;
    class JobSheet* CurrentJobSheet;
	class Stores* theStores;
	class Recycling* theRecycling;
	class Garbage* theGarbage;

public:
    JobSheet ServiceCar(Car* CarServicing);
	class Car* CurrentCar;

	void AddStores(Stores * aStores);
	void DelStores();

	void AddRecycling(Recycling * aRecycling);
	void DelRecycling();

	void AddGarbage(Garbage * aGarbage);
	void DelGarbage();

	void AddCar(Car * aCar);
	void DelCar();

	void AddJobSheet(JobSheet * aJobSheet);
	void DelJobSheet();

    void GetCar(Car* carToService);

    Technician();

    ~Technician();
};

#endif
