#ifndef STORES_H
#define STORES_H

#include "Oil.h"
#include "AirFilter.h"
#include "OilFilter.h"
#include "Tires.h"

class Stores
{

private:
    int OilTankA;
    int OilTankB;
    int OilTankC;
    int AirFilterStore;
    int OilFilterStore;
    int TireStore;

public:
    Oil GetOil(string Type, int Quantity);

    AirFilter GetAirFilter();

    OilFilter GetOilFilter();

    Tires GetTires(string Make, int Size, int Quantity);

    Stores();

    ~Stores();
};

#endif
