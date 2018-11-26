#ifndef RECYCLING_H
#define RECYCLING_H

#include "Oil.h"
#include "Tires.h"
#include <iostream>

// Alex Von Schulmann 13975140
// Alec Xu 38108130

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
