#ifndef RECYCLING_H
#define RECYCLING_H

#include "Oil.h"
#include "Tires.h"
#include <iostream>

using namespace std;

class Recycling
{


public:
    void Recycle(Oil* OldOil);

    void Recycle(Tires* OldTires);

    Recycling();

    ~Recycling();
};

#endif
