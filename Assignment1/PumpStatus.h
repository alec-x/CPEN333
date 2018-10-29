#pragma once
#include "..\Transaction.h"
struct PumpStatus{
	double quantityFueled;			// Progress in the fueling process
	double prices[4];
	int fuelGrade;
	bool complete;
	bool pumpOn = true;				// Kill the pump (set by the GSC)
	bool pumpPaused;			// In event of low fuel (set by GSC)
	struct Transaction transactionData;
};