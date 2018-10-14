//#include "Pump.h"
#include <stdio.h>
#include "../rt.h"
#include "../PumpDataPoolData.h"
#include "../SharedConstants.h"


// === THREAD FOR MONITORING A SINGLE PUMP ===
UINT __stdcall MonitorPumpData(void *args) // Takes in pumpNumber (same as in const.)
{	
	
	int pumpNumber = *(int *)(args) - 1; // Array indexing [1 -> 0, 2 -> 1, etc.]
	
	// Mutex between this and GSC
	CRendezvous rPumps("pumpsRendezvous", NUMPUMPS + 1);
	CSemaphore pSemaphore("pSemaphore" + to_string(pumpNumber), 0, 1);
	CSemaphore cSemaphore("cSemaphore" + to_string(pumpNumber), 1, 1);

	string dataPoolName = "CDataPool" + to_string(pumpNumber);

	// Make/find data pool with data in the struct
	CDataPool dp(dataPoolName, sizeof(PumpDataPoolData));
	struct PumpDataPoolData *pumpData = (struct PumpDataPoolData *)(dp.LinkDataPool());

	// Signal initialization complete
	rPumps.Wait();

	// On new transaction
	while (pumpData->pumpOn) {
		pSemaphore.Wait();
		// Wait for okay to proceed
		cSemaphore.Signal();
	}
	
	return 0;
}

UINT __stdcall MonitorFuelLevel(void *args) // Monitors the Fuel Tank Monitor
{
	return 0;
}

int main() {

	CRendezvous rv("processRendezvous", NUMPROCESS);
	CRendezvous rPumps("pumpsRendezvous", NUMPUMPS + 1);

	// Make Threads to handle the CDataPools that communicate with the pumps
	CThread* pumpMonitorArray[NUMPUMPS];
	for (int i = 0; i < NUMPUMPS; i++)
	{
		pumpMonitorArray[i] = new CThread(MonitorPumpData, ACTIVE, &i);
	}

	// Make Thread to Handle Fuel Level Monitor
	// ... TO DO

	// Wait for pump initialization, then signal complete.
	rPumps.Wait();
	rv.Wait();

	// Run-time display and operation
	// ... TO DO, NEED TO IMPLEMENT PRODUCER CONSUMER SEMAPHORES WITH THE PUMP CLASSES


	// Wait for threads to finish
	for (int i = 0; i < NUMPUMPS; i++)
	{
		pumpMonitorArray[i]->WaitForThread();
		delete(pumpMonitorArray[i]);
	}
	
	return 0;
}
