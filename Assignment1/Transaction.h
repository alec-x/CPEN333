#pragma once
#include <time.h>

struct Transaction {
	time_t timeOfPurchase;
	char customerName[32];
	int  fuelAmount;
	char ccNumber[17];
	int  fuelGrade;
};