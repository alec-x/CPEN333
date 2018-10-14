#pragma once
struct Transaction {
	char name[32];
	char ccNumber[20];
	int quantity;
	int grade;
};

struct PumpDataPoolData {
	int quantityFueled;			// Progress in the fueling process
	bool complete;
	bool pumpOn;				// Kill the pump (set by the GSC)
	bool pumpPaused;			// In event of low fuel (set by GSC)
	struct Transaction tData;
};