#pragma once
#include "../rt.h"
#include <string.h>
#include "../PumpStatus.h"
#include "..\Transaction.h"
#include "..\SharedConstants.h"
#include "..\Assignment1\FuelTankMonitor.h"


/* 
	Should be able to:
		- Communicate via Data Pool with the Gas Station Computer
		- i.e. send details of transaction (name, credit card, etc.)
		- then receive authorization token from GSC
		- then dispense gas and update GSC/Data Pool in 'real-time'
		- tell GSC done
*/


class Pump : public ActiveClass
{
public:
	struct PumpStatus dataPoolStruct;
	string dataPoolName, dataPipeName;

	Pump(int pumpNumber);
	~Pump();

private:
	int main(void);
	int pumpNum;
};