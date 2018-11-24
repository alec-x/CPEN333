#ifndef GARBAGE_H
#define GARBAGE_H

#include "OilFilter.h"
#include "AirFilter.h"
#include <iostream>

using namespace std; 

class Garbage
{


public:
    void Dispose(OilFilter OldOilFilter);

    void Dispose(AirFilter OldAirFilter);

    Garbage();

    ~Garbage();
};

#endif
