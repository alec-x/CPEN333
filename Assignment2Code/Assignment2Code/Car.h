#ifndef CAR_H
#define CAR_H
#include "Oil.h"	
#include "OilFilter.h"
#include "AirFilter.h"
#include "Tires.h"
#include <string>
#include <iostream>

// Alex Von Schulmann 13975140
// Alec Xu 38108130

using namespace std;

class Car
{

private:
    bool TireStatus;
    class Oil* CarOil;
	class OilFilter* CarOilFilter;
	class AirFilter* CarAirFilter;
	class Tires* CarTires[4];

public:
    Oil SwapOil(Oil NewOil);

    OilFilter SwapOilFilter(OilFilter NewOilFilter);

    AirFilter SwapAirFilter(AirFilter NewAirFilter);

    Tires* SwapTires(Tires *NewTire, int index);

	void AddOil(Oil *aOil);
	void DelOil();
	void AddOilFilter(OilFilter *aOilFilter);
	void DelOilFilter();
	void AddAirFilter(AirFilter *aAirFilter);
	void DelAirFilter();
	void AddTire(Tires *aTire, int index);

	void DelTire(int index);

    bool CheckTiresForWear();

    void RotateTires();

    Car();

    ~Car();
};

#endif
