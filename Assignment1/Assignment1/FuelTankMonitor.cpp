#include "FuelTankMonitor.h"
BOOL FuelTankMonitor::decrementTank(int grade)
{
	theMutex->Wait();
	int index = gradeMap.at(grade);
	BOOL Status = FALSE;
	if (Tanks[index] >= decResolution) {
		Status = TRUE;
		Tanks[index] -= decResolution;
	}
	theMutex->Signal();
	return Status;
}

void FuelTankMonitor::addFuel(int grade, double amount)
{
	theMutex->Wait();
	int index = gradeMap.at(grade);
	Tanks[index] += amount;
	if (Tanks[index] >= maxTank) {
		Tanks[index] = maxTank;
	}
	theMutex->Signal();
}

double FuelTankMonitor::queryTank(int grade) {
	int index = gradeMap.at(grade);
	return Tanks[index];
}

FuelTankMonitor::FuelTankMonitor()
{
	theMutex = new CMutex("MyBankAccount");
	for (int i = 0; i < size(Tanks); i++) {
		Tanks[i] = maxTank;
	}
}

FuelTankMonitor::~FuelTankMonitor()
{
	delete theMutex;
}
