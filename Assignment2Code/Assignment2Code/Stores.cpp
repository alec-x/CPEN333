#include "Stores.h"

Oil Stores::GetOil(string Type, int Quantity)
{
	return  Oil(Type, Quantity);
}

AirFilter Stores::GetAirFilter()
{
	return AirFilter();
}

OilFilter Stores::GetOilFilter()
{
	return OilFilter();
}

Tires* Stores::GetTires(string Make, int Size)
{
	return new Tires(Make, Size);
}

Stores::Stores()
{
}

Stores::~Stores()
{
}
