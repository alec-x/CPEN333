#pragma once
#include "..\Transaction.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

struct PumpStatus{
	double quantityFueled;			// Progress in the fueling process
	double prices[4];				// Prices for different grades
	int fuelGrade;
	bool complete;
	bool pumpOn = true;				// Kill the pump (set by the GSC)
	bool pumpPaused;				// In event of low fuel (set by GSC)
	struct Transaction transactionData;
};