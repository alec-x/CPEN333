#pragma once
#include "Tank.h"
#include "..\rt.h"
#include <map>

class FuelTankMonitor
{
private:
	double Tanks[4];	// the data to be protected, in this example a simple ‘double’, 
	CMutex	*theMutex;	// a pointer to a hidden mutex protecting the ‘Balance’ variable above
	CDataPool *fuelTankDataPool;
	double *dataPointer;
	const double maxTank = 500.0;
public:
	const double decResolution = 0.5;
	BOOL decrementTank(int grade);
	void addFuel(int grade, double amount);
	double queryTank(int grade);
	const map<int, int> gradeMap = {
	{ 87, 0},
	{ 89, 1},
	{ 91, 2},
	{ 93, 3}
	};
	FuelTankMonitor();
	~FuelTankMonitor();
};

