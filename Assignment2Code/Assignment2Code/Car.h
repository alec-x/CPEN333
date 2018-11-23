#ifndef CAR_H
#define CAR_H
#include "Oil.h"
#include "OilFilter.h"
#include "AirFilter.h"
#include "Tires.h"

class Car
{

private:
    bool TireStatus;
    Oil CarOil;
    OilFilter CarOilFilter;
    AirFilter CarAirFilter;
    Tires CarTires;

public:
    Oil SwapOil(Oil NewOil);

    OilFilter SwapOilFilter(OilFilter NewOilFilter);

    AirFilter SwapAirFilter(AirFilter NewAirFilter);

    Tires SwapTires(Tires NewTires);

    bool CheckTiresForWear();

    void RotateTires();

    Car();

    ~Car();
};

#endif
