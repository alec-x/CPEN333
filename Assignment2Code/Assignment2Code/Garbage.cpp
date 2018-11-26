#include "Garbage.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

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
