#pragma once
#include "../rt.h"
#include <string.h>
#include "PumpDataPoolData.h"
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
	Pump(int pumpNumber);
	~Pump();
	struct PumpDataPoolData dataPoolStruct;
	string dataPoolName, dataPipeName;


private:
	int main(void);
};