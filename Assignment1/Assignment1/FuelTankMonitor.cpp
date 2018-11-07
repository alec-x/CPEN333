#include "FuelTankMonitor.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

BOOL FuelTankMonitor::decrementTank(int grade)
{
	theMutex->Wait();							// mutex for protecting monitor datapool
	int index = gradeMap.at(grade);
	BOOL Status = FALSE;						// status is return error value
	if (dataPointer[index] >= decResolution) {
		Status = TRUE;
		dataPointer[index] -= decResolution;
	}
	theMutex->Signal();
	return Status;
}

void FuelTankMonitor::addFuel(int index, double amount)
{
	theMutex->Wait();
	dataPointer[index] += amount;
	if (dataPointer[index] >= maxTank) { // Cannot be incremented beyond capacity
		dataPointer[index] = maxTank;
	}
	theMutex->Signal();
}

double FuelTankMonitor::queryTank(int grade) {
	int index = gradeMap.at(grade);
	return dataPointer[index];
}

FuelTankMonitor::FuelTankMonitor()
{
	fuelTankDataPool = new CDataPool("fuelTankDataPool", sizeof(dataPointer));
	dataPointer = (double*)(fuelTankDataPool->LinkDataPool());
	theMutex = new CMutex("fuelTankMonitorMutex");
	for (unsigned int i = 0; i < size(Tanks); i++) {
		dataPointer[i] = maxTank;
	}
}

FuelTankMonitor::~FuelTankMonitor()
{
	delete theMutex;
	delete fuelTankDataPool;
}
