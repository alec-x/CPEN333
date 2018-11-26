#ifndef GARBAGE_H
#define GARBAGE_H

#include "OilFilter.h"
#include "AirFilter.h"
#include <iostream>

// Alex Von Schulmann 13975140
// Alec Xu 38108130

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
