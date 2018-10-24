//#include "Pump.h"
#include <stdio.h>
#include "..\rt.h"
#include "..\PumpStatus.h"
#include "..\SharedConstants.h"
#include "..\Transaction.h"
#include "..\Assignment1\FuelTankMonitor.h"

UINT __stdcall updateTankGSC(void *args); 
UINT __stdcall updatePumpGSC(void *args);
FuelTankMonitor fuelTank;
const int pumpDisplayWidth = 50;
const int heightOffset = 4;

int main() {

	CRendezvous rv("processRendezvous", NUMPROCESS);
	CRendezvous rPump("pumpRendezvous", NUMPUMPS + 2);

	CSemaphore* AllowPumping[NUMPUMPS];
	for (int i = 0; i < NUMPUMPS; i++)
	{
		AllowPumping[i] = new CSemaphore("AllowPumpingSemaphore" + to_string(i), 0);
	}
	
	// Wait until everything initialized
	rPump.Wait();
	rv.Wait();

	// Make Threads to handle the CDataPools that communicate with the pumps
	CThread* tankMonitor = new CThread(updateTankGSC, ACTIVE);

	CThread* pumpMonitors[NUMPUMPS];
	string name_arg[NUMPUMPS];
	for (int i = 0; i < NUMPUMPS; i++) {
		name_arg[i] = "CDataPoolPump" + to_string(i);
		pumpMonitors[i] = new CThread(updatePumpGSC, ACTIVE, &name_arg[i]);
	}
	
	// Main (forever)
	int userInput;
	while (1) {
		cin >> userInput;
		switch (userInput)
		{
		case 0:
			AllowPumping[0]->Signal();
			break;
		case 1:
			AllowPumping[1]->Signal();
			break;
		case 2:
			AllowPumping[2]->Signal();
			break;
		case 3:
			AllowPumping[3]->Signal();
			break;
		default:
			break;
		}

	}

	// Wait for threads to finish and clean up
	for (int i = 0; i < NUMPUMPS; i++)
	{
		pumpMonitors[i]->WaitForThread();
		delete(pumpMonitors[i]);
		delete(AllowPumping[i]);
	}

	tankMonitor->WaitForThread();
	delete(tankMonitor);
	
	return 0;
}

UINT __stdcall updatePumpGSC(void *args)
{
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

	while (pumpData->pumpOn) {
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
			MOVE_CURSOR(0, heightOffset + 7);
			writeSemaphore.Signal();
			SLEEP(200);
		}

		writeSemaphore.Wait();
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 1);             // move cursor to cords [x,y]
		printf("Name:            %-32s", " ");
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 2);             // move cursor to cords [x,y]
		printf("Credit Card #:   %-32s", " ");
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 3);             // move cursor to cords [x,y]
		printf("Fuel Grade:      %02d", 0);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 4);             // move cursor to cords [x,y]
		printf("Quantity Fueled: %02d", 0);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 5);             // move cursor to cords [x,y]
		printf("Cost:            %02d", 0);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 6);             // move cursor to cords [x,y]
		fflush(stdout);		      	// force output to be written to screen
		MOVE_CURSOR(0, heightOffset + 7);
		writeSemaphore.Signal();
		SLEEP(200);
	}


	return 0;
}


UINT __stdcall updateTankGSC(void *args)
{
	CSemaphore writeSemaphore("GSCWrite", 1);
	while (1) {
		SLEEP(200);
		writeSemaphore.Wait();
		MOVE_CURSOR(0, heightOffset + 7);
		printf("%.1f %.1f %.1f %.1f\n", fuelTank.queryTank(87), fuelTank.queryTank(89), fuelTank.queryTank(91), fuelTank.queryTank(93));
		MOVE_CURSOR(0, heightOffset + 7);
		writeSemaphore.Signal();
	}
	return 0;
}
