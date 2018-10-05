#pragma once
struct Transaction {
	char name[32];
	char ccNumber[20];
	int quantity;
	int grade;
};
struct PumpDataPoolData {
	//	Transaction tData;			// Customer transaction data
	int quantityFueled;		// Progress in the fueling process
	bool complete;
	bool pumpOn;			// Kill the pump (set by the GSC)
	bool pumpPaused;	// In event of low fuel (set by GSC)
	struct Transaction tData;
};