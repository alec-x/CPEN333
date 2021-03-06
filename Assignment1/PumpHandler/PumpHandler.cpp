#include "..\rt.h"
#include "..\PumpStatus.h"
#include "..\SharedConstants.h"
#include "..\Transaction.h"
#include "Pump.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

UINT __stdcall updateDisplay(void *args);

int main() {

	CRendezvous rv("processRendezvous", NUMPROCESS);
	CRendezvous rPump("pumpRendezvous", NUMPUMPS + 2);

	// Create the pump array
	Pump* pumpArray[NUMPUMPS];

	// Init the pumps
	for (int i = 0; i < NUMPUMPS; i++)
	{
		pumpArray[i] = new Pump(i);
		pumpArray[i]->Resume();
	}
	
	// Signal that initialization complete
	rPump.Wait();
	rv.Wait();

	// Create threads to monitor pumps
	CThread *pumpMonitors[NUMPUMPS];
	string name_arg[NUMPUMPS];
	for (int i = 0; i < NUMPUMPS; i++) {
		name_arg[i] = "CDataPoolPump" + to_string(i);
		pumpMonitors[i] = new CThread(updateDisplay, ACTIVE, &name_arg[i]);
	}


	// Wait for finish
	for (int i = 0; i < NUMPUMPS; i++)
	{
		pumpMonitors[i]->WaitForThread();
		delete(pumpMonitors[i]);
	}
	
	for (int i = 0; i < NUMPUMPS; i++)
	{
		pumpArray[i]->WaitForThread();
		delete(pumpArray[i]);
	}
	
	return 0;
}

// Update the Pump Display window (per thread)
UINT __stdcall updateDisplay(void *args)
{
	const int pumpDisplayWidth = 50;
	const int heightOffset = 4;
	CSemaphore writeSemaphore("PumpHandlerWrite", 1);
	string dataPoolName = *(string *)(args);
	CDataPool pumpStatusDP(dataPoolName, sizeof(PumpStatus));
	PumpStatus *pumpData = (PumpStatus *)(pumpStatusDP.LinkDataPool());
	int offset = dataPoolName.back() - '0';
	string banner = " # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # "
					"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # "
					"# # # # # # # # # # # # # # # # # # # # # # # # # # # # # #";

	// While pump is running...
	while (pumpData->pumpOn) {
		while (!pumpData->complete) {
			double costMult;
			int currGradeIndex;
			// If data available/init, display cost
			try
			{
				costMult = pumpData->prices[gradeMap.at(pumpData->fuelGrade)];
			}
			catch (const std::exception&)
			{
				costMult = 0.0;
			}
			// If data available/init, display grade
			try
			{
				currGradeIndex = gradeMap.at(pumpData->fuelGrade);
			}
			catch (const std::exception&)
			{
				currGradeIndex = -1;
			}

			// Write data 
			writeSemaphore.Wait();
			MOVE_CURSOR(0, 0);
			TEXT_COLOUR(12, 0);
			printf("%s", banner.c_str());
			MOVE_CURSOR(2 * pumpDisplayWidth - 10, 1);
			printf("Pumps");
			MOVE_CURSOR(0, 2);
			printf("%s", banner.c_str());
			TEXT_COLOUR(15, 0);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset);             // move cursor to cords [x,y]
			printf("Pump %d Information:", offset);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 1);             // move cursor to cords [x,y]
			printf("Name:            %-32s", pumpData->transactionData.customerName);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 2);             // move cursor to cords [x,y]
			printf("Credit Card #:   %-32s", pumpData->transactionData.ccNumber);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 3);
			// Highlight the selected grade
			for (unsigned int i = 0; i < size(grades); i++)
			{
				if (currGradeIndex == i) {
					TEXT_COLOUR(0, 15);
				}
				else {
					TEXT_COLOUR(15, 0);
				}
				printf("%02d      ", grades[i]);																		// GRADE OPTIONS
			}
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 4);
			for (unsigned int i = 0; i < size(grades); i++)
			{
				if (currGradeIndex == i){
					TEXT_COLOUR(0, 15);
				}
				else {
					TEXT_COLOUR(15, 0);
				}
				printf("%01.3f   ", pumpData->prices[i]);																// PRICE OPTIONS
			}	
			TEXT_COLOUR(15, 0);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 6);             
			printf("Fuel Grade:      %02d", pumpData->fuelGrade);														// GRADE
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 7);             
			printf("Quantity Fueled: %0.1f / %0.1f", pumpData->quantityFueled, pumpData->transactionData.fuelAmount);	// QUANTITY FUELED
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 8);             
			printf("Cost:            %03.2f       ", pumpData->quantityFueled * costMult);								// COST
			fflush(stdout);		      	
			writeSemaphore.Signal();
			SLEEP(200);
		}

		writeSemaphore.Wait();
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 6);
		printf("Fuel Grade:      %02s", "--");						
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 7);
		printf("Quantity Fueled: %0.1f / %0.1f", 0.0, 0.0);							
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 8);
		printf("Cost:            %03.2f       ", 0.0);										
		fflush(stdout);
		SLEEP(200);
		writeSemaphore.Signal();
	}


	return 0;
}