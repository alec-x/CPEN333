/* Makes the Pump ActiveClass Objects
 *
 *
 *
 */

#include "../rt.h"
#include "../PumpDataPoolData.h"
#include "../SharedConstants.h"
#include "Pump.h"

int main() {

	CRendezvous rv("processRendezvous", NUMPROCESS);

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


	while (1) {
		// Update DOS Window with Info
		//pumpArray[0]->dataPoolStruct.tData.ccNumber; // etc.
	}


	// Wait for finish
	for (int i = 0; i < NUMPUMPS; i++)
	{
		pumpArray[i]->WaitForThread();
		delete(pumpArray[i]);
	}

	return 0;
}