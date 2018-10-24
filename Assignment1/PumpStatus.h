#pragma once
#include "..\Transaction.h"
struct PumpStatus{
	int quantityFueled;			// Progress in the fueling process
	int fuelGrade;
	bool complete;
	bool pumpOn = true;				// Kill the pump (set by the GSC)
	bool pumpPaused;			// In event of low fuel (set by GSC)
	struct Transaction transactionData;
};