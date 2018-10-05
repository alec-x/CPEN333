#pragma once
#include "../rt.h"
#include <string.h>
#include "Pump.h"

/*
	Should be able to:
		- Communicate via Data Pool with the Gas Station Computer
		- i.e. send details of transaction (name, credit card, etc.)
		- then receive authorization token from GSC
		- then dispense gas and update GSC/Data Pool in 'real-time'
		- tell GSC done
*/

class Tank : public ActiveClass
{
public:
	Tank(int tankNumber);
	~Tank();

	// === STRUCT FOR ACCESSING DATA POOL ===
	// ANY CHANGES HERE MUST ALSO BE MADE IN GSC.CPP
	struct TankDataPoolData {
		int tankLevel = 0;	// In event of low fuel (set by GSC)
	};
	string dataPoolName, dataPipeName;

};