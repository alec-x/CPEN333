/*
**	Win32 code program to solve the graphical problem illustrated previously. The single Producer
**	Single Consumer arrangement. Let's assume this is both the Producer and the Parent program
*/
// Alex Von Schulmann 13975140
// Alec Xu 38108130

#include 	<stdio.h>
#include	"..\..\rt.h"			// change pathlist to "rt.h" to suit location on disk

struct		mydatapooldata {		// template for the data in a datapool
	int 	x;						// just a single int
};

struct		mydatapooldata 	*DataPointer1;		// pointer to the actual data pool

struct		mydatapooldata 	*DataPointer2;		// pointer to the actual data pool
int 	main()
{
	CSemaphore		ps1("PS1", 0, 1);    // semaphore with initial value 0 and max value 1
	CSemaphore		ps2("PS2", 0, 1);    // semaphore with initial value 0 and max value 1
	CSemaphore		cs1("CS1", 1, 1);    // semaphore with initial value 1 and max value 1
	CSemaphore		cs2("CS2", 1, 1);    // semaphore with initial value 1 and max value 1

//	Create a datapool and then get a pointer to it

	CDataPool dp1("MyDataPool1", sizeof(struct mydatapooldata));
	DataPointer1 = (struct mydatapooldata *)dp1.LinkDataPool();	// get pointer to data pool

	CDataPool dp2("MyDataPool2", sizeof(struct mydatapooldata));
	DataPointer2 = (struct mydatapooldata *)dp2.LinkDataPool();	// get pointer to data pool

//
//	Now that we have created the semaphores, let's create the child process
//

	CProcess p1("..\\Release\\Lab5DbChild.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,					// process has its own window
		ACTIVE							// process is active immediately
	);
	CProcess p2("..\\Release\\Lab5DbChild2.exe",	// pathlist to child program executable
		NORMAL_PRIORITY_CLASS,			// priority
		OWN_WINDOW,					// process has its own window
		ACTIVE							// process is active immediately
	);

	printf("Consumer Process Running.....\n");

	for (int i = 0; i < 10; i++) {	// Produce 10 lots of data
		printf("Hit RETURN to Consume Data.....\n");
		getchar();
		ps1.Wait();			// wait for producer process to signal producer semaphore
		ps2.Wait();
		printf("Consumed: %d\n", DataPointer1->x);
		printf("Consumed: %d\n", DataPointer2->x);
		cs1.Signal();			// signal the consumer semaphore to wake up the producer
		cs2.Signal();
	}

	return 0;				// sempahores destroyed here
}