#include 	<stdio.h>
#include	"..\..\rt.h"			// change pathlist to "rt.h" to suit location on disk
// Alex Von Schulmann 13975140
// Alec Xu 38108130
struct		mydatapooldata {		// template for the data in a datapool
	int 	x;						// just a single int
};

struct		mydatapooldata 	*DataPointer1;		// pointer to the actual data pool

int 	main()
{
	CSemaphore		ps1("PS1", 0, 1);    // semaphore with initial value 0 and max value 1
	CSemaphore		cs1("CS1", 1, 1);    // semaphore with initial value 1 and max value 1

//	Create a datapool and then get a pointer to it

	CDataPool dp1("MyDataPool1", sizeof(struct mydatapooldata));
	DataPointer1 = (struct mydatapooldata *)dp1.LinkDataPool();	// get pointer to data pool

//
//	Now that we have created the semaphores, let's create the child process
//
	printf("Producer Process Running.....\n");

	for (int i = 10; i < 20; i++) {	// Produce 10 lots of data
		cs1.Wait();			// wait for consumer process to signal consumer semaphore
		DataPointer1->x = i;	// generate data and store in datapool
		ps1.Signal();			// signal the producer semaphore to wake up the consumer
		printf("Produced %d.....\n", i);
	}

	return 0;				// sempahores destroyed here
}