#pragma once
#include <time.h>

// Alex Von Schulmann 13975140
// Alec Xu 38108130

struct Transaction {
	time_t timeOfPurchase = 28800; //defaults to 00:00:00
	char customerName[32];
	double  fuelAmount;
	char ccNumber[17];
	int  fuelGrade;
};
