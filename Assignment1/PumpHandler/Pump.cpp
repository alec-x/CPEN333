#include "Pump.h"
#include "..\Customer.h"

Pump::Pump(int pumpNumber)
{
	dataPoolName = "CDataPoolPump" + to_string(pumpNumber);
	dataPipeName = "CPipePump" + to_string(pumpNumber);
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
	CTypedPipe<Customer> customerPipe(dataPipeName, 10);

	// Make struct to link to the data
	PumpStatus *pumpData = (PumpStatus *)(pumpStatusDP.LinkDataPool());
	pumpData->complete = false;
	pumpData->pumpOn = true;
	pumpData->pumpPaused = false;
	pumpData->quantityFueled = 0;

	while (pumpData->pumpOn) {
		while (pumpData->pumpPaused) {
			// Wait/Sleep
			if (!pumpData->pumpOn) {
				return 0;
			}
		}

		// Take next customer from the pipeline (will wait until data is available)
		struct Customer custInfo;
		customerPipe.Read(&custInfo);

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
