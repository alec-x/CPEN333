#include "..\rt.h"
#include "..\SharedConstants.h"
#include "..\Assignment1\Customer.h"

int main() {

	// ===========
	// ===========
	// === TESTING

	Customer testDude[10];

	for (int i = 0; i < 10; i++)
	{
		srand(i + 1);
		testDude[i].Resume();
		testDude[i].WaitForThread();
	}

	return 0;

	// === TESTING
	// ===========
	// ===========



	CRendezvous rv("processRendezvous", NUMPROCESS);

	// Init the other processes

	//CProcess...

	// Wait for other process initialization
	rv.Wait();

	// Create customers, world-events, etc.

	return 0;
}