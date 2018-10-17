#pragma once
#include "Tank.h"
#include "..\rt.h"

class FuelTankMonitor: public ActiveClass
{
public:
	FuelTankMonitor();
	~FuelTankMonitor();
private:
	struct Tank tanks[4];
};

