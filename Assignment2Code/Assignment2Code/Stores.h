#ifndef STORES_H
#define STORES_H

#include "Oil.h"
#include "AirFilter.h"
#include "OilFilter.h"
#include "Tires.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

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

    Tires* GetTires(string Make, int Size);

    Stores();

    ~Stores();
};

#endif
