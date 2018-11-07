#include "..\rt.h"
#include "..\SharedConstants.h"
#include "..\Assignment1\Customer.h"

// Alex Von Schulmann 13975140
// Alec Xu 38108130

int main() {

	const int numCustomers = 100;
	Customer customerArray[numCustomers];

	CRendezvous rv("processRendezvous", NUMPROCESS);

	// Init the other processes

	
	CProcess pumpHandlerProcess("..\\Debug\\PumpHandler.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	CProcess GSCProcess("..\\Debug\\GSC.exe",	// pathlist to child program executable				
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,						// process has its own window					
		ACTIVE							// process is active immediately
	);

	// Wait for other process initialization
	rv.Wait();

	// Create customers, world-events, etc.
	for (int i = 0; i < numCustomers; i++)
	{
		// Pseudo-random seed
		srand(i + 1);
		customerArray[i].Resume();
		Sleep(rand() % 30);
	}
	GSCProcess.WaitForProcess();
	
	return 0;
}