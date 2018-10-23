//#include "Pump.h"
#include <stdio.h>
#include "..\rt.h"
#include "..\PumpStatus.h"
#include "..\SharedConstants.h"
#include "..\Transaction.h"


UINT __stdcall MonitorPumpData(void *args);
UINT __stdcall MonitorFuelLevel(void *args); // Monitors the Fuel Tank Monitor
UINT __stdcall updatePumpGSC(void *args);

int main() {

	CRendezvous rv("processRendezvous", NUMPROCESS);

	// Make Threads to handle the CDataPools that communicate with the pumps
	CThread* pumpMonitorArray[NUMPUMPS];
	for (int i = 0; i < NUMPUMPS; i++)
	{
		pumpMonitorArray[i] = new CThread(MonitorPumpData, ACTIVE, &i);
	}

	// Make Thread to Handle Fuel Level Monitor
	// ... TO DO

	// Wait for pump initialization, then signal complete.
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

UINT __stdcall updatePumpGSC(void *args)
{
	const int pumpDisplayWidth = 30;
	const int heightOffset = 4;
	CSemaphore writeSemaphore("PumpHandlerGSC", 1);
	string dataPoolName = *(string *)(args);
	CDataPool pumpStatusDP(dataPoolName, sizeof(PumpStatus));
	PumpStatus *pumpData = (PumpStatus *)(pumpStatusDP.LinkDataPool());
	int offset = dataPoolName.back() - '0';

	while (!pumpData->complete) {
		writeSemaphore.Wait();
		MOVE_CURSOR(0, 0);
		TEXT_COLOUR(12, 0);
		printf("%s", banner.c_str());
		MOVE_CURSOR(2 * pumpDisplayWidth - 3, 1);
		printf("Pumps");
		MOVE_CURSOR(0, 2);
		printf("%s", banner.c_str());
		TEXT_COLOUR(15, 0);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset);             // move cursor to cords [x,y]
		printf("%s Information:", dataPoolName.c_str());
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 1);             // move cursor to cords [x,y]
		printf("Pump On:           %s", pumpData->pumpOn ? "true" : "false");
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 2);             // move cursor to cords [x,y]
		printf("Pump Status:       %s", pumpData->pumpOn ? "Paused" : "Active");
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 3);             // move cursor to cords [x,y]
		printf("Fuel Grade:        %02d", pumpData->fuelGrade);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 4);             // move cursor to cords [x,y]
		printf("Quantity Fueled:   %02d", pumpData->quantityFueled);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 5);             // move cursor to cords [x,y]
		printf("Cost:              %02d", pumpData->quantityFueled);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 6);             // move cursor to cords [x,y]
		//printf("\n");
		fflush(stdout);		      	// force output to be written to screen

		writeSemaphore.Signal();
		SLEEP(200);
	}
	return 0;
}

// === THREAD FOR MONITORING A SINGLE PUMP ===
UINT __stdcall MonitorPumpData(void *args) // Takes in pumpNumber (same as in const.)
{

	int pumpNumber = *(int *)(args)-1; // Array indexing [1 -> 0, 2 -> 1, etc.]

	// Mutex between this and GSC
	CRendezvous rPumps("pumpsRendezvous", NUMPUMPS + 1);
	CSemaphore pSemaphore("pSemaphore" + to_string(pumpNumber), 0, 1);
	CSemaphore cSemaphore("cSemaphore" + to_string(pumpNumber), 1, 1);

	string dataPoolName = "CDataPool" + to_string(pumpNumber);

	// Make/find data pool with data in the struct
	CDataPool dp(dataPoolName, sizeof(PumpStatus));
	struct PumpStatus *pumpData = (struct PumpStatus *)(dp.LinkDataPool());

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