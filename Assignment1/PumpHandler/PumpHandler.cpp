/* Makes the Pump ActiveClass Objects
 *
 *
 *
 */

#include "..\rt.h"
#include "..\PumpStatus.h"
#include "..\SharedConstants.h"
#include "..\Transaction.h"
#include "Pump.h"

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

	while (pumpData->pumpOn) {
		while (!pumpData->complete) {
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
			printf("%s Information:", dataPoolName.c_str());
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 1);             // move cursor to cords [x,y]
			printf("Name:            %-32s", pumpData->transactionData.customerName);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 2);             // move cursor to cords [x,y]
			printf("Credit Card #:   %-32s", pumpData->transactionData.ccNumber);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 3);             // move cursor to cords [x,y]
			printf("Fuel Grade:      %02d", pumpData->fuelGrade);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 4);             // move cursor to cords [x,y]
			printf("Quantity Fueled: %02f", pumpData->quantityFueled);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 5);             // move cursor to cords [x,y]
			printf("Cost:            %02f", pumpData->quantityFueled);
			MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 6);             // move cursor to cords [x,y]
			//printf("\n");
			fflush(stdout);		      	// force output to be written to screen
			writeSemaphore.Signal();
			SLEEP(200);
		}

		writeSemaphore.Wait();
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 1);             // move cursor to cords [x,y]
		printf("Name:            %-32s", "");
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 2);             // move cursor to cords [x,y]
		printf("Credit Card #:   %-32s", "");
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 3);             // move cursor to cords [x,y]
		printf("Fuel Grade:      %02d", 0);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 4);             // move cursor to cords [x,y]
		printf("Quantity Fueled: %02d", 0);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 5);             // move cursor to cords [x,y]
		printf("Cost:            %02d", 0);
		MOVE_CURSOR(offset * pumpDisplayWidth, heightOffset + 6);             // move cursor to cords [x,y]
		fflush(stdout);		      	// force output to be written to screen
		writeSemaphore.Signal();
		SLEEP(200);
	}


	return 0;
}