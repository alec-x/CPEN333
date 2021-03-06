#include 	<stdio.h>
#include	"..\..\rt.h"			// change pathlist to "rt.h" to suit location on disk
// Alex Von Schulmann 13975140
// Alec Xu 38108130
struct		mydatapooldata {		// template for the data in a datapool
	int 	x;						// just a single int
};

struct		mydatapooldata 	*DataPointer2;		// pointer to the actual data pool

int 	main()
{
	CSemaphore		ps2("PS2", 0, 1);    // semaphore with initial value 0 and max value 1
	CSemaphore		cs2("CS2", 1, 1);    // semaphore with initial value 1 and max value 1

//	Create a datapool and then get a pointer to it

	CDataPool dp2("MyDataPool2", sizeof(struct mydatapooldata));
	DataPointer2 = (struct mydatapooldata *)dp2.LinkDataPool();	// get pointer to data pool

//
//	Now that we have created the semaphores, let's create the child process
//
	printf("Producer Process Running.....\n");

	for (int i = 0; i < 10; i++) {	// Produce 10 lots of data
		cs2.Wait();			// wait for consumer process to signal consumer semaphore
		DataPointer2->x = i;	// generate data and store in datapool
		ps2.Signal();			// signal the producer semaphore to wake up the consumer
		printf("Produced %d.....\n", i);
	}

	return 0;				// sempahores destroyed here
}