//#include "Pump.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "..\rt.h"
#include "..\PumpStatus.h"
#include "..\SharedConstants.h"
#include "..\Transaction.h"
#include "..\Assignment1\FuelTankMonitor.h"
#include <map>

int pausePumpSignal[NUMPUMPS];
UINT __stdcall updateTankGSC(void *args); 
UINT __stdcall updatePumpGSC(void *args);
FuelTankMonitor fuelTank;
const int pumpDisplayWidth = 50;
const int heightOffset = 4;
map<int, double> costMap = {
{ 87, 1.512},
{ 89, 1.634},
{ 91, 1.755},
{ 93, 2.111}
};

int main() {

	CRendezvous rv("processRendezvous", NUMPROCESS);
	CRendezvous rPump("pumpRendezvous", NUMPUMPS + 2);

	CSemaphore writeSemaphore("GSCWrite", 1);
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

	for (int i = 0; i < NUMPUMPS; i++) {
		pausePumpSignal[i] = 0;
	}
	// Main (forever)
	string userInput;
	while (1) {
		int i, index;
		int j = 0;

		cin >> userInput;
		if (userInput == "ap")
		{
			cin >> i;
			if ((0 <= i) && (i <= NUMPUMPS - 1)) {
				AllowPumping[i]->Signal();
				
			}
		}
		else if (userInput == "ft") {
			cin >> i;
			try
			{
				index = fuelTank.gradeMap.at(i);
			}
			catch (const std::exception&)
			{
				continue;
			}
			cin >> j;
			fuelTank.addFuel(index, (double)j);
		}
		else if (userInput == "sp") {
			cin >> i;
			try 
			{
				pausePumpSignal[i] = 1;
			}
			catch (const std::exception&) 
			{
				continue;
			}
		}
		else if (userInput == "ep") {
			cin >> i;
			try
			{
				pausePumpSignal[i] = 0;
			}
			catch (const std::exception&)
			{
				continue;
			}
		}

		writeSemaphore.Wait();
		MOVE_CURSOR(0, heightOffset + 8);
		printf("                           ");
		MOVE_CURSOR(0, heightOffset + 9);
		printf("                           ");
		MOVE_CURSOR(0, heightOffset + 9);
		printf("%s %d %d", userInput.c_str(), i, j);
		MOVE_CURSOR(0, heightOffset + 8);
		fflush(stdout);
		writeSemaphore.Signal();

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
	char tempTime[32];
	printf("%d", pumpData->complete);
	printf("%d", pumpData->fuelGrade);
	printf("%d", pumpData->pumpOn);
	printf("%s", pumpData->transactionData.customerName);

	string banner = " # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # "
					"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # "
					"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # #";
	double tempCost;
	double costMult;
	
	while (pumpData->pumpOn) {
		while (!pumpData->complete) {
			try
			{
				costMult = costMap.at(pumpData->transactionData.fuelGrade);
			}
			catch (const std::exception&)
			{
				costMult = costMap.at(87);
			}
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
			printf("Quantity Fueled: %0.1f / %0.1f", pumpData->quantityFueled, pumpData->transactionData.fuelAmount);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 5);             // move cursor to cords [x,y]
			tempCost = pumpData->quantityFueled*costMult;
			printf("Cost:            %07.3f", costMult);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 6);             // move cursor to cords [x,y]
			strftime(tempTime, sizeof(tempTime), "%H:%M:%S", \
				localtime(&pumpData->transactionData.timeOfPurchase));
			printf("Time:            %s", tempTime);
			fflush(stdout);		      	// force output to be written to screen
			MOVE_CURSOR(0, heightOffset + 8);
			writeSemaphore.Signal();
			SLEEP(200);

			if (pausePumpSignal[offset]) {
				pumpData->pumpPaused = 1;
			}
			else {
				pumpData->pumpPaused = 0;
			}
		}

		SLEEP(500);
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
		printf("Time:                            ");

		fflush(stdout);		      	// force output to be written to screen
		MOVE_CURSOR(0, heightOffset + 9);
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
		MOVE_CURSOR(0, heightOffset + 8);
		writeSemaphore.Signal();
	}
	return 0;
}
