#ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include "Oil.h"
#include "Tires.h"
#include "AirFilter.h"
#include "OilFilter.h"
#include "JobSheet.h"
#include "Car.h"

class Technician
{

private:
    int currentlyServicing;
    Oil OilInventory;
    Tires TireInventory[4];
    AirFilter AirFilterInventory;
    OilFilter OilFilterInventory;
    JobSheet CurrentJobSheet;
    Car CurrentCar;

public:
    JobSheet ServiceCar(Car CarServicing);

    Car GetCar();

    Technician();

    ~Technician();
};

#endif
