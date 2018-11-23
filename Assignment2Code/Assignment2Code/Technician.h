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

class Technician
{

private:
    int currentlyServicing;
    Oil OilInventory;
    Tires TireInventory[4];
    AirFilter AirFilterInventory;
    OilFilter OilFilterInventory;
    class JobSheet* CurrentJobSheet;
    class Car* CurrentCar;
	class Stores* theStores;
	class Recycling* theRecycling;
	class Garbage* theGarbage;

public:
    JobSheet ServiceCar(Car CarServicing);

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

    Car GetCar();

    Technician();

    ~Technician();
};

#endif
