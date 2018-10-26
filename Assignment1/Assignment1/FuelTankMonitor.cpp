#include "FuelTankMonitor.h"

BOOL FuelTankMonitor::decrementTank(int grade)
{
	theMutex->Wait();
	int index = gradeMap.at(grade);
	BOOL Status = FALSE;
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
	if (dataPointer[index] >= maxTank) {
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
	theMutex = new CMutex("MyBankAccount");
	for (unsigned int i = 0; i < size(Tanks); i++) {
		dataPointer[i] = maxTank - 100;
	}
}

FuelTankMonitor::~FuelTankMonitor()
{
	delete theMutex;
	delete fuelTankDataPool;
}
