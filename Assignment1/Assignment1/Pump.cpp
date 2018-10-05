#include "Pump.h"

Pump::Pump(int pumpNumber)
{
	dataPoolName = "CDataPoolPump" + to_string(pumpNumber);
	dataPipeName = "CPipePump" + to_string(pumpNumber);
}

Pump::~Pump()
{

}

int Pump::main(void)
{
	// Make/find data pool with data in the struct
	CDataPool dp(dataPoolName, sizeof(PumpDataPoolData));
	//CDataPool dp("thebestpool", sizeof(this->data));
	// Make/find data pool with max. # of transaction
	CTypedPipe<Transaction> transactionPipe(dataPipeName, 10);

	// Make struct to link to the data
	PumpDataPoolData *pumpData = (PumpDataPoolData *)(dp.LinkDataPool());
	pumpData->complete = false;
	pumpData->pumpOn = true;
	pumpData->pumpPaused = false;
	pumpData->quantityFueled = 0;

	while (pumpData->pumpOn) {
		while (pumpData->pumpPaused) {
			// Wait/Sleep?
			if (!pumpData->pumpOn) {
				return 0;
			}
		}

		// Take next customer from the pipeline (will wait until data is available)
		struct Transaction custInfo;
		transactionPipe.Read(&custInfo);

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
