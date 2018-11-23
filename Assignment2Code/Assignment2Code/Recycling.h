#ifndef RECYCLING_H
#define RECYCLING_H

#include "Oil.h"
#include "Tires.h"

class Recycling
{


public:
    void Recycle(Oil OldOil);

    void Recycle(Tires OldTires);

    Recycling();

    ~Recycling();
};

#endif
