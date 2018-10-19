#include "Pump.h"
#include "..\Transaction.h"

Pump::Pump(int pumpNumber)
{
	dataPoolName = "CDataPoolPump" + to_string(pumpNumber);
	dataPipeName = "CustomerPipeline" + to_string(pumpNumber);
	pumpNum = pumpNumber;
}

Pump::~Pump()
{

}

void Pump::updateWindow()
{
}

void Pump::decrementTank()
{
}

void Pump::signalTransaction()
{
}

void Pump::signalEnd()
{
}

int Pump::main(void)
{
	// Make/find data pool with data in the struct
	CDataPool pumpStatusDP(dataPoolName, sizeof(PumpStatus));

	// Make/find data pool with max. # of customers
	CTypedPipe<Transaction> customerPipeline(dataPipeName, 1);

	// Create Semaphores
	CSemaphore ArrivalSemaphore("ArrivalSemaphore" + to_string(pumpNum), 0);  //wait
	CSemaphore SwipeCardSemaphore("SwipeCardSemaphore" + to_string(pumpNum), 0);// signal and send transaction in pipeline
	CSemaphore RemoveHoseSemaphore("RemoveHoseSemaphore" + to_string(pumpNum), 0);// signal
	CSemaphore SelectGradeSemaphore("SelectGradeSemaphore" + to_string(pumpNum), 0);// signal
	CSemaphore DispenseGasSemaphore("DispenseGasSemaphore" + to_string(pumpNum), 0);// wait
	CSemaphore ReturnHoseSemaphore("ReturnHoseSemaphore" + to_string(pumpNum), 0);// signal
	CSemaphore LeaveSemaphore("LeaveSemaphore" + to_string(pumpNum), 0);// signal

	// Make struct to link to the data
	PumpStatus *pumpData = (PumpStatus *)(pumpStatusDP.LinkDataPool());
	pumpData->complete = false;
	pumpData->pumpOn = true;
	pumpData->pumpPaused = false;
	pumpData->quantityFueled = 0;
	// Make transaction to hold
	Transaction customerTransaction;

	ArrivalSemaphore.Wait();
	customerPipeline.Read(&customerTransaction);
	SwipeCardSemaphore.Signal();
	RemoveHoseSemaphore.Signal();
	SelectGradeSemaphore.Signal();
	DispenseGasSemaphore.Wait();
	ReturnHoseSemaphore.Signal();
	LeaveSemaphore.Signal();

	while (pumpData->pumpOn) {
		while (pumpData->pumpPaused) {
			// Wait/Sleep
			if (!pumpData->pumpOn) {
				return 0;
			}
		}

		// Take next customer from the pipeline (will wait until data is available)


		// Load pipeline data into the shared data pool
		//pumpData->tData = custInfo;
		pumpData->complete = false;
		pumpData->quantityFueled = 0;

		//while (pumpData->quantityFueled < pumpData->tData.getGasQuantity()) {
			// =======================
			// =======================
			// Fueling Logic goes here
			// =======================
			// =======================
		//}
		pumpData->complete = true;
		// Move on to next customer
	}

	return 0;
}
