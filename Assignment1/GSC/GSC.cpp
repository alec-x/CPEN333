//#include "Pump.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "..\rt.h"
#include "..\PumpStatus.h"
#include "..\SharedConstants.h"
#include "..\Transaction.h"
#include "..\Assignment1\FuelTankMonitor.h"
#include <map>

UINT __stdcall updateTankGSC(void *args); 
UINT __stdcall updatePumpGSC(void *args);
FuelTankMonitor fuelTank;
const int pumpDisplayWidth = 50;
const int heightOffset = 4;
map<int, double> costMap = {
{ grades[0], 1.512},
{ grades[1], 1.634},
{ grades[2], 1.755},
{ grades[3], 2.111}
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
	
	// Main (forever)
	string userInput;
	while (1) {
		int i, index;
		int j = 0;
		double k = 0.0;

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
				index = gradeMap.at(i);
			}
			catch (const std::exception&)
			{
				continue;
			}
			cin >> j;
			fuelTank.addFuel(index, (double)j);
		}
		else if (userInput == "cp") {
			cin >> i;
			try
			{
				index = gradeMap.at(i);
			}
			catch (const std::exception&)
			{
				continue;
			}
			cin >> k;
			costMap[i] = k;
		}

		writeSemaphore.Wait();
		MOVE_CURSOR(0, heightOffset + 11);
		printf("                           ");
		MOVE_CURSOR(0, heightOffset + 12);
		printf("                           ");
		MOVE_CURSOR(0, heightOffset + 12);
		printf("%s %d %d %f", userInput.c_str(), i, j, k);
		MOVE_CURSOR(0, heightOffset + 11);
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

	string banner = " # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # "
					"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # "
					"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # #";
	
	while (pumpData->pumpOn) {
		double GSCPrices[] = { costMap.at(grades[0]), costMap.at(grades[1]), costMap.at(grades[2]), costMap.at(grades[3]) };
		for (unsigned int i = 0; i < size(GSCPrices); i++)
		{
			pumpData->prices[i] = GSCPrices[i];
		}

		while (!pumpData->complete) {
			double costMult;
			try
			{
				costMult = pumpData->prices[gradeMap.at(pumpData->fuelGrade)];
			}
			catch (const std::exception&)
			{
				costMult = pumpData->prices[0];
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
			printf("Pump %d Information:", offset);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 1);             // move cursor to cords [x,y]
			printf("Name:            %-32s", pumpData->transactionData.customerName);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 2);             // move cursor to cords [x,y]
			printf("Credit Card #:   %-32s", pumpData->transactionData.ccNumber);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 3);             // move cursor to cords [x,y]
			printf("Fuel Grade:      %02d", pumpData->fuelGrade);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 4);             // move cursor to cords [x,y]
			printf("Quantity Fueled: %0.1f / %0.1f", pumpData->quantityFueled, pumpData->transactionData.fuelAmount);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 5);             // move cursor to cords [x,y]
			printf("Cost:            %07.3f", pumpData->quantityFueled * costMult);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 6);             // move cursor to cords [x,y]
			strftime(tempTime, sizeof(tempTime), "%H:%M:%S", \
				localtime(&pumpData->transactionData.timeOfPurchase));
			printf("Time:            %s", tempTime);
			fflush(stdout);		      	// force output to be written to screen
			MOVE_CURSOR(0, heightOffset + 11);
			writeSemaphore.Signal();
			SLEEP(200);





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
		MOVE_CURSOR(0, heightOffset + 11);
		writeSemaphore.Signal();
		SLEEP(200);
	}


	return 0;
}


UINT __stdcall updateTankGSC(void *args)
{
	CSemaphore writeSemaphore("GSCWrite", 1);
	CCondition* allowFueling[4];
	for (int i = 0; i < 4; i++)
	{
		string condName = "allowFueling" + to_string(i);
		allowFueling[i] = new CCondition(condName);
	}
	int toggle[] = { 0,0,0,0 };

	while (1) {
		writeSemaphore.Wait();
		MOVE_CURSOR(0, heightOffset + 8);
		printf("Tank Status:");
		MOVE_CURSOR(0, heightOffset + 9);
		for (unsigned int i = 0; i < size(grades); i++)
		{
			printf("%02d   ", grades[i]);
		}
		MOVE_CURSOR(0, heightOffset + 10);
		for (unsigned int i = 0; i < size(grades); i++)
		{
			double tankLevel = fuelTank.queryTank(grades[i]);
			if (tankLevel < 200.0)
			{
				allowFueling[i]->Reset();
				if (toggle[i])
				{
					TEXT_COLOUR(0, 0);
					toggle[i] = 0;
				}
				else {
					TEXT_COLOUR(12, 0);
					toggle[i] = 1;
				}
			}
			else {
				allowFueling[i]->Signal();
				TEXT_COLOUR(15, 0);
				toggle[i] = 0;
			}
			printf("%3.1f  ", tankLevel);
		}
		TEXT_COLOUR(15, 0);
		MOVE_CURSOR(0, heightOffset + 11);
		writeSemaphore.Signal();
		Sleep(200);
	}

	for (int i = 0; i < 4; i++)
	{
		delete(allowFueling[i]);
	}

	return 0;
}
