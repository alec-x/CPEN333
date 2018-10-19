#pragma once
#include <time.h>

struct Transaction {
	time_t timeOfPurchase;
	long long ccNumber;
	char customerName[32];
	int  fuelAmount;
	int  fuelGrade;
};