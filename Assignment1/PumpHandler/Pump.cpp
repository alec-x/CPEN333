#include "Pump.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130
Pump::Pump(int pumpNumber)
{
	dataPoolName = "CDataPoolPump" + to_string(pumpNumber);
	dataPipeName = "CustomerPipeline" + to_string(pumpNumber);
	pumpNum = pumpNumber;
}

Pump::~Pump()
{

}



int Pump::main(void)
{
	int timing_ms = 250;
	FuelTankMonitor fuelTank;
	// Make/find data pool with data in the struct
	CRendezvous rPump("pumpRendezvous", NUMPUMPS + 2);
	CDataPool pumpStatusDP(dataPoolName, sizeof(PumpStatus));

	// Make/find data pool with max. # of customers
	CTypedPipe<Transaction> customerPipeline(dataPipeName, 1);

	// Create Semaphores with Customer
	CSemaphore ArrivalSemaphore("ArrivalSemaphore" + to_string(pumpNum), 0);  
	CSemaphore SwipeCardSemaphore("SwipeCardSemaphore" + to_string(pumpNum), 0);
	CSemaphore RemoveHoseSemaphore("RemoveHoseSemaphore" + to_string(pumpNum), 0);
	CSemaphore SelectGradeSemaphore("SelectGradeSemaphore" + to_string(pumpNum), 0);
	CSemaphore DispenseGasSemaphore("DispenseGasSemaphore" + to_string(pumpNum), 0);
	CSemaphore ReturnHoseSemaphore("ReturnHoseSemaphore" + to_string(pumpNum), 0);
	CSemaphore LeaveSemaphore("LeaveSemaphore" + to_string(pumpNum), 0);

	// Create Semaphores with GSC
	CSemaphore AllowPumping("AllowPumpingSemaphore" + to_string(pumpNum), 0);

	// Condition for low Tank
	CCondition* allowFueling[4];
	for (int i = 0; i < 4; i++)
	{
		string condName = "allowFueling" + to_string(i);
		allowFueling[i] = new CCondition(condName);
	}

	// Make struct to link to the data
	PumpStatus *pumpData = (PumpStatus *)(pumpStatusDP.LinkDataPool());

	// Make transaction to hold
	Transaction customerTransaction;
	rPump.Wait();

	pumpData->complete = false;
	pumpData->pumpOn = true;
	pumpData->pumpPaused = false;
	pumpData->quantityFueled = 0;
	pumpData->fuelGrade = 0;

	// Turning off the pump will end the ActiveClass object
	while (pumpData->pumpOn) {

		// Customer interaction
		ArrivalSemaphore.Signal();
		customerPipeline.Read(&customerTransaction); // Will wait until data is available
		SwipeCardSemaphore.Wait();
		RemoveHoseSemaphore.Wait();
		SelectGradeSemaphore.Wait();

		// Init data pool values
		pumpData->complete = false;
		pumpData->pumpPaused = true;
		pumpData->quantityFueled = 0;
		pumpData->transactionData = customerTransaction;
		pumpData->fuelGrade = pumpData->transactionData.fuelGrade;
		pumpData->pumpOn = true;

		AllowPumping.Wait(); // Wait for GSC Authorization

		// Ensure adequate fuel
		allowFueling[gradeMap.at(pumpData->fuelGrade)]->Wait();
		while (pumpData->pumpPaused);
		pumpData->transactionData.timeOfPurchase = time(NULL);
		while (pumpData->quantityFueled < pumpData->transactionData.fuelAmount) {
			if (fuelTank.decrementTank(pumpData->fuelGrade)) {
				pumpData->quantityFueled = pumpData->quantityFueled + fuelTank.decResolution;
			}
			Sleep(timing_ms);
			while (pumpData->pumpPaused);
		}

		// Customer interaction
		DispenseGasSemaphore.Signal(); // Signal end of dispensal
		ReturnHoseSemaphore.Wait();
		LeaveSemaphore.Wait();
		Sleep(500);
		pumpData->complete = true;

	}

	for (int i = 0; i < 4; i++)
	{
		delete(allowFueling[i]);
	}

	return 0;
}
