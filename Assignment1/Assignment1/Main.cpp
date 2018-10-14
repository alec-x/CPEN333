#include "../rt.h"
#include "../SharedConstants.h"


int main() {

	CRendezvous rv("processRendezvous", NUMPROCESS);

	// Init the other processes

	//CProcess...

	// Wait for other process initialization
	rv.Wait();

	// Create customers, world-events, etc.
	// Customers should wait/signal the pipeline before writing to it

	string dataPipeName = "CPipePump0";



	return 0;
}