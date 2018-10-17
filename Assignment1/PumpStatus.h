#pragma once
struct Transaction {
	char customerName[32];
	long ccNumber;
	int  fuelAmount;
	int  fuelGrade;
	int  pumpNum;
	int  transactionID;

};

struct PumpStatus{
	int quantityFueled;			// Progress in the fueling process
	int fuelGrade;
	bool complete;
	bool pumpOn;				// Kill the pump (set by the GSC)
	bool pumpPaused;			// In event of low fuel (set by GSC)
	struct Transaction transactionData;
};