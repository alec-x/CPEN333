#pragma once
#include "Tank.h"
#include "..\rt.h"
#include <map>
#include "..\SharedConstants.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

class FuelTankMonitor
{
private:
	double Tanks[4];	// the data to be protected, in this example a simple ‘double’, 
	CMutex	*theMutex;	// a pointer to a hidden mutex protecting the ‘Balance’ variable above
	CDataPool *fuelTankDataPool; //pointer to the datapool for the monitor class
	double *dataPointer; //pointer to monitor datapool
	const double maxTank = 500.0;
public:
	const double decResolution = 0.5;
	BOOL decrementTank(int grade);
	void addFuel(int grade, double amount);
	double queryTank(int grade);
	FuelTankMonitor();
	~FuelTankMonitor();
};

