#include "Garbage.h"

void Garbage::Dispose(OilFilter OldOilFilter)
{
	cout << "I, the Garbage, have consumed the Old Oil Filter" << endl;
	return;
}

void Garbage::Dispose(AirFilter OldAirFilter)
{
	cout << "I, the Garbage, have consumed the Old Air Filter" << endl;
    return;
}

Garbage::Garbage()
{
}

Garbage::~Garbage()
{
}
