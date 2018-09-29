#pragma once
#include "../rt.h"
#include <string.h>
#include "Transaction.h"

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

	// === STRUCT FOR ACCESSING DATA POOL ===
	// ANY CHANGES HERE MUST ALSO BE MADE IN GSC.CPP
	struct PumpDataPoolData {
		Transaction tData;			// Customer transaction data
		int quantityFueled = 0;		// Progress in the fueling process
		bool complete = false;
		bool pumpOn = true;			// Kill the pump (set by the GSC)
		bool pumpPaused = false;	// In event of low fuel (set by GSC)
	};
	string dataPoolName, dataPipeName;


private:
	int main(void);
};