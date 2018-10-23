#include "..\rt.h"
#include "..\SharedConstants.h"
#include "..\Assignment1\Customer.h"

int main() {

	// ===========
	// ===========
	// === TESTING

	Customer customerArray[10];

	for (int i = 0; i < 10; i++)
	{
		srand(i + 1);
		customerArray[i].Resume();
		customerArray[i].WaitForThread();
	}

	// === TESTING
	// ===========
	// ===========



	CRendezvous rv("processRendezvous", NUMPROCESS);

	// Init the other processes

	CProcess pumpHandlerProcess("..\\Debug\\PumpHandler.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	// Wait for other process initialization
	rv.Wait();

	// Create customers, world-events, etc.

	return 0;
}