//#include "Pump.h"
#include <stdio.h>
#include "..\rt.h"
#include "..\PumpStatus.h"
#include "..\SharedConstants.h"
#include "..\Transaction.h"

UINT __stdcall updateTankGSC(void *args); 
UINT __stdcall updatePumpGSC(void *args);

int main() {

	CRendezvous rv("processRendezvous", NUMPROCESS);

	// Make Threads to handle the CDataPools that communicate with the pumps
	CThread* pumpMonitors[NUMPUMPS];
	string name_arg[NUMPUMPS];
	for (int i = 0; i < NUMPUMPS; i++) {
		name_arg[i] = "CDataPoolPump" + to_string(i);
		pumpMonitors[i] = new CThread(updatePumpGSC, ACTIVE, &name_arg[i]);
	}

	CThread* tankMonitor = new CThread(updateTankGSC, ACTIVE);
	
	// Wait until everything initialized
	rv.Wait();

	
	
	
	// HANDLE UI INTERACTION




	// Wait for threads to finish and clean up
	for (int i = 0; i < NUMPUMPS; i++)
	{
		pumpMonitors[i]->WaitForThread();
		delete(pumpMonitors[i]);
	}

	tankMonitor->WaitForThread();
	delete(tankMonitor);
	
	return 0;
}

UINT __stdcall updatePumpGSC(void *args)
{
	const int pumpDisplayWidth = 50;
	const int heightOffset = 4;
	CSemaphore writeSemaphore("GSCWrite", 1);
	string dataPoolName = *(string *)(args);
	CDataPool pumpStatusDP(dataPoolName, sizeof(PumpStatus));
	PumpStatus *pumpData = (PumpStatus *)(pumpStatusDP.LinkDataPool());
	int offset = dataPoolName.back() - '0';

	printf("%d", pumpData->complete);
	printf("%d", pumpData->fuelGrade);
	printf("%d", pumpData->pumpOn);
	printf("%s", pumpData->transactionData.customerName);

	string banner = " # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # "
					"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # "
					"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # #";

	while (!pumpData->complete) {
		writeSemaphore.Wait();
		MOVE_CURSOR(0, 0);
		TEXT_COLOUR(14, 0);
		printf("%s", banner.c_str());
		MOVE_CURSOR(2 * pumpDisplayWidth - 10, 1);
		printf("GSC");
		MOVE_CURSOR(0, 2);
		printf("%s", banner.c_str());
		TEXT_COLOUR(15, 0);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset);             // move cursor to cords [x,y]
		printf("%s Information:", dataPoolName.c_str());
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 1);             // move cursor to cords [x,y]
		printf("Name:            %-32s", pumpData->transactionData.customerName);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 2);             // move cursor to cords [x,y]
		printf("Credit Card #:   %-32s", pumpData->transactionData.ccNumber);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 3);             // move cursor to cords [x,y]
		printf("Fuel Grade:      %02d", pumpData->fuelGrade);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 4);             // move cursor to cords [x,y]
		printf("Quantity Fueled: %02d", pumpData->quantityFueled);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 5);             // move cursor to cords [x,y]
		printf("Cost:            %02d", pumpData->quantityFueled);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 6);             // move cursor to cords [x,y]
		//printf("\n");
		fflush(stdout);		      	// force output to be written to screen
		writeSemaphore.Signal();
		SLEEP(200);
	}


	return 0;
}


UINT __stdcall updateTankGSC(void *args)
{
	printf("Tank Test");
	while (1) {

	}
	return 0;
}
