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

UINT __stdcall updateDisplay(void *args)
{
	CSemaphore writeSemaphore("PumpHandlerWrite", 1);
	string dataPoolName = *(string *)(args);
	CDataPool pumpStatusDP(dataPoolName, sizeof(PumpStatus));
	PumpStatus *pumpData = (PumpStatus *)(pumpStatusDP.LinkDataPool());
	int offset = dataPoolName.back() - '0';
	while (!pumpData->complete) {
		writeSemaphore.Wait();
		MOVE_CURSOR(0, offset*7);             // move cursor to cords [x,y]
		printf("%s Information:\n", dataPoolName.c_str());
		printf("Pump On:         %s\n", pumpData->pumpOn ? "true" : "false");
		printf("Pump Status:     %s\n", pumpData->pumpOn ? "Paused" : "Active");
		printf("Fuel Grade:      %02d\n", pumpData->fuelGrade);
		printf("Quantity Fueled: %02d\n", pumpData->quantityFueled);
		printf("Cost:            %02d\n", pumpData->quantityFueled);
		printf("\n");
		fflush(stdout);		      	// force output to be written to screen

		writeSemaphore.Signal();
		SLEEP(200);
	}


	return 0;
}

int main() {

	CRendezvous rv("processRendezvous", NUMPROCESS);


	// Create threads to monitor pumps
	CThread *pumpMonitors[NUMPUMPS];
	string name_arg[NUMPUMPS];
	for (int i = 0; i < NUMPUMPS; i++) {
		name_arg[i] = "CDataPoolPump" + to_string(i);
		pumpMonitors[i] = new CThread(updateDisplay, ACTIVE, &name_arg[i]);
	}
	
	// Create the pump array
	Pump* pumpArray[NUMPUMPS];

	// Init the pumps
	for (int i = 0; i < NUMPUMPS; i++)
	{
		pumpArray[i] = new Pump(i);
		pumpArray[i]->Resume();
	}
	
	// Signal that initialization complete
	rv.Wait();

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