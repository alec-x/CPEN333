#pragma once
struct Transaction {
	char customerName[32];
	long ccNumber;
	int  fuelAmount;
	int  fuelGrade;
	int  pumpNum;
	int  transactionID;

};

struct Customer {
	int customerID;
	struct Transaction transactionInfo;

};